#requires -Version 3

$code = @'
using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
namespace AppManager
{
  public enum ShowStates
  {
    Hide,
    Normal,
    Minimized,
    Maximized,
    ShowNoActivateRecentPosition,
    Show,
    MinimizeActivateNext,
    MinimizeNoActivate,
    ShowNoActivate,
    Restore,
    ShowDefault,
    ForceMinimize
  }

  public class AppInstance : System.Diagnostics.Process
  {
    [DllImport("User32")]
    private static extern int ShowWindow(IntPtr hwnd, ShowStates nCmdShow);
    [DllImport("User32.dll")]
    public static extern IntPtr FindWindowEx(IntPtr parent, IntPtr childAfter, string className, string windowName);
    [DllImport("user32.dll")]
    private static extern int GetWindowThreadProcessId(IntPtr hWnd, out int ProcessId);
    [DllImport("user32.dll")]
    public static extern bool SetWindowPos(IntPtr hWnd, IntPtr hWndInsertAfter, int X, int Y, int cx, int cy, uint uFlags);

    public IntPtr WindowHandle;
    

    public AppInstance(string Name, bool Hidden) : this(Name, ProcessWindowStyle.Hidden)
    {
      if (Hidden == false) this.Show();
    }

    public AppInstance(string Name, ProcessWindowStyle WindowStyle) : base()
    {
      this.StartInfo.FileName = Name;
      this.StartInfo.WorkingDirectory = Environment.CurrentDirectory;
      this.StartInfo.WindowStyle = WindowStyle;
      this.Start();
      this.WaitForInputIdle();
      this.WindowHandle = this.MainWindowHandle;
      
      if (this.WindowHandle == IntPtr.Zero)
      {
        this.WindowHandle = FindWindow(this.Id);
      }
    }

    public AppInstance(string Name) : this(Name, ProcessWindowStyle.Normal) { }

    public void Show()
    {
      ShowWindow(this.WindowHandle, ShowStates.ShowDefault);
    }

    public void Minimize()
    {
      ShowWindow(this.WindowHandle, ShowStates.ForceMinimize);
    }

    public void Maximize()
    {
      ShowWindow(this.WindowHandle, ShowStates.Maximized);
    }

    public void Hide()
    {
      ShowWindow(this.WindowHandle, ShowStates.Hide);
    }

    public void SetWindowStyle(ShowStates WindowStyle)
    {
      ShowWindow(this.WindowHandle, WindowStyle);
    }

    public void Topmost(bool ShowTopmost = true)
    {
      IntPtr flag = new IntPtr(-2);
      if (ShowTopmost)
      {
        flag = new IntPtr(-1);
      }
      SetWindowPos(this.WindowHandle, flag, 0, 0, 0, 0, 3);
    }

    public void Stop()
    {
      this.Kill();
    }

    
    public void Close(int Timeout = 0)
    {
      this.CloseMainWindow();
      if (Timeout > 0)
      {
        this.WaitForExit(Timeout * 1000);
        if (this.HasExited == false)
        {
          this.Stop();
        }
      }
    }

    private IntPtr FindWindow(int Pid)
    {
      IntPtr h = IntPtr.Zero;
      int tid;
      int pid;
      
      do
      {
        pid = 0;
        h = FindWindowEx(IntPtr.Zero, h, null, null);
        tid = GetWindowThreadProcessId(h, out pid);
        if (pid == Pid)
        {
          break;
        }
      } while (!h.Equals(IntPtr.Zero));
      
      return h;
    }
  } 
}
'@

Add-Type -TypeDefinition $code
