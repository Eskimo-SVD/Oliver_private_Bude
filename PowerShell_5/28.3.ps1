function Monitor-Folder {
    param([string]$folder)

    $fsw = New-Object System.IO.FileSystemWatcher
    $fsw.Path = $folder

    $global:folderchange = @()

    $action = {
        [System.Console]::Beep(440,100)
  $info = @{}
  $info.Path = $eventArgs.FullPath
  $info.Type = $eventArgs.ChangeType
  $info.Timestamp = (Get-Date)
  $global:folderchange += (New-Object PSObject -Property $info)
    }

    Register-ObjectEvent $fsw -EventName Created -Action $action -SourceIdentifier Watch1 | Out-Null
    Register-ObjectEvent $fsw -EventName Changed -Action $action -SourceIdentifier Watch2 | Out-Null
    Register-ObjectEvent $fsw -EventName Deleted -Action $action -SourceIdentifier Watch3 | Out-Null
}

function Unmonitor-Folder {
  Unregister-Event Watch*
  Remove-Job -Name Watch*
}
