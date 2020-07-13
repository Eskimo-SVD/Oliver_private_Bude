$code = @'
using System;
using System.Collections.Generic;
using System.Text;
using System.Management.Automation;
using System.Management.Automation.Runspaces;

namespace InProcess
{
    public class InMemoryJob : System.Management.Automation.Job
    {
        public InMemoryJob(ScriptBlock scriptBlock, string name)
        {
            _powerShell = PowerShell.Create().AddScript(scriptBlock.ToString());
            SetUpStreams(name);
        }

        public InMemoryJob(PowerShell powerShell, string name)
        {
            _powerShell = powerShell;
            SetUpStreams(name);
        }

        private void SetUpStreams(string name)
        {
          _powerShell.Streams.Verbose = this.Verbose;
          _powerShell.Streams.Error = this.Error;
          _powerShell.Streams.Debug = this.Debug;
          _powerShell.Streams.Warning = this.Warning;
          _powerShell.Runspace.AvailabilityChanged += 
            new EventHandler<RunspaceAvailabilityEventArgs>(Runspace_AvailabilityChanged);

            int id = System.Threading.Interlocked.Add(ref InMemoryJobNumber, 1);
            if (!string.IsNullOrEmpty(name))
            {
                this.Name = name;
            }
            else
            {
                this.Name = "InProcessJob" + id;
            }
        }

        void Runspace_AvailabilityChanged(object sender, RunspaceAvailabilityEventArgs e)
        {
            if (e.RunspaceAvailability == RunspaceAvailability.Available)
            {
                this.SetJobState(JobState.Completed);
            }
        }

        PowerShell _powerShell;
        static int InMemoryJobNumber = 0;

        public override bool HasMoreData
        {
            get {
                return (Output.Count > 0);
            }
        }
        public override string Location
        {
            get { return "In Process"; }
        }

        public override string StatusMessage
        {
            get { return "A new status message"; }
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                if (!isDisposed)
                {
                    isDisposed = true;
                    try
                    {
                        if (!IsFinishedState(JobStateInfo.State))
                        {
                            StopJob();
                        }

                        foreach (Job job in ChildJobs)
                        {
                            job.Dispose();
                        }
                    }
                    finally
                    {
                        base.Dispose(disposing);
                    }
                }
            }
        }

        private bool isDisposed = false;

        internal bool IsFinishedState(JobState state)
        {
            return (state == JobState.Completed || state == JobState.Failed || state == JobState.Stopped);
        }

        public override void StopJob()
        {
            _powerShell.Stop();
            _powerShell.EndInvoke(_asyncResult);
            SetJobState(JobState.Stopped);
        }

        public void Start()
        {
            _asyncResult = _powerShell.BeginInvoke<PSObject, PSObject>(null, Output);
            SetJobState(JobState.Running);
        }
        IAsyncResult _asyncResult;

        public void WaitJob()
        {
            _asyncResult.AsyncWaitHandle.WaitOne();
        }

        public void WaitJob(TimeSpan timeout)
        {
            _asyncResult.AsyncWaitHandle.WaitOne(timeout);
        }
    }

}
'@

Add-Type -TypeDefinition $code

function Start-JobInProcess
{
  [CmdletBinding()]
   param
  (
    [scriptblock] $ScriptBlock,

    $ArgumentList,

    [string] $Name
  )

  function Get-JobRepository
  {
    [cmdletbinding()]
    param()
    $pscmdlet.JobRepository
  }

  function Add-Job
  {
    [cmdletbinding()]
    param
    (
      $job
    )

    $pscmdlet.JobRepository.Add($job)
  }

  if ($ArgumentList)
  {
    $powershell = [powershell]::Create().AddScript($ScriptBlock).AddArgument($argumentlist)
    $MemoryJob = New-Object InProcess.InMemoryJob $powershell, $Name
  }
  else
  {
    $MemoryJob = New-Object InProcess.InMemoryJob $ScriptBlock, $Name
  }

  $MemoryJob.Start()
  Add-Job $MemoryJob
  $MemoryJob
}
