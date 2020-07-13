function Limit-Runspace
{
  [CmdletBinding()]
  param
  (
    # kommaseparierte Liste erlaubter PowerShell-Befehle
    # Platzhalterzeichen sind nicht erlaubt
    [String[]]
    $AllowedCommands,
    
    # kommaseparierte Liste der absoluten Pfadnamen zu nativen Befehlen
    # Platzhalterzeichen wie "*" sind erlaubt
    # Beispiel: *\notepad.exe
    [String[]]
    $AllowedNativeCommands,
    
    # in einer normalen PowerShell ist der Defaultwert "RestrictedLanguage"
    # in einer Remoteshell ist der Defaultwert "NoLanguage"
    [System.Management.Automation.PSLanguageMode]
    $LanguageMode = $(if ($host.Name -eq 'ServerRemoteHost') { 'NoLanguage' } else { 'RestrictedLanguage' }),
    
    # werden die Basiscmdlets der PowerShell entfernt, kann die Sitzung
    # nicht mehr interaktiv ausgeführt werden. Die Sitzung kann dann
    # nur noch mit Invoke-Command verwendet werden.
    [Switch]
    $ExcludeDefaultCommands,
    
    [Switch]
    $IncludeTabExpansion,
    
    [Microsoft.PowerShell.ExecutionPolicy]
    $ExecutionPolicy = 'Restricted'
  )
  
  # läuft diese Funktion in einer Remoteshell?
  $isRemote = $host.Name -eq 'ServerRemoteHost'
  Write-Verbose "Remotesession? $isRemote"
  
  # DefaultCommands dürfen nur in einer Remotepowershell entfernt werden
  # eine normale PowerShell benötigt diese für den Betrieb
  if ($ExcludeDefaultCommands -and !$isRemote)
  {
    Write-Warning 'DefaultCommands können in lokaler PowerShell nicht entfernt werden.'
    $ExcludeDefaultCommands = $false
  }
  Write-Verbose "Exclude Default Commands? $ExcludeDefaultCommands"

  # Anwendungsliste löschen
  $ExecutionContext.SessionState.Applications.Clear()
  Write-Verbose 'Removing Applications.'
  if ($AllowedNativeCommands.Count -gt 0)
  {
    $ExecutionContext.SessionState.Applications.AddRange($AllowedNativeCommands)
    Write-Verbose "Adding Applications: $AllowedNativeCommands"
  }

  # Skriptliste löschen
  $ExecutionContext.SessionState.Scripts.Clear()
  Write-Verbose 'Removing Scripts.'

  # Erlaubte Befehle definieren
  $issHash = @{}
  
  [System.Collections.ArrayList]$BaseCommands = New-Object System.Collections.ArrayList
  if (!$ExcludeDefaultCommands)
  {
    $type = [Management.Automation.Runspaces.InitialSessionState]
    $iss = $type::CreateRestricted('RemoteServer')
    
    # wenn dies eine Remoteshell ist, werden die Basisbefehle als
    # Proxycommands importiert
    # bei einer lokalen Shell werden die vorhandenen Befehle nicht entfernt
    if ($isRemote)
    {
      foreach($proxy in $iss.Commands | Where-Object { $_.CommandType -eq 'Function'})
      {
        Set-Item "function:global:$($proxy.Name)" $proxy.Definition
        $name = '{0}-{1}' -f $proxy.Name, $proxy.CommandType
        $issHash[$name] = $proxy
        Write-Verbose ("Adding Proxy Command " + $proxy.Name)
      }
    }
    else
    {
      [System.Collections.ArrayList]$BaseCommands = $iss.Commands | 
      Where-Object { $_.Visibility -eq 'Public' } | 
      Select-Object -ExpandProperty Name
      Write-Verbose 'Enabling Default PowerShell Commands'
    }
  }
  
  # aktiviert Tabvervollständigung
  # ACHTUNG: Tabvervollständigung zeigt auch versteckte Befehlsnamen an,
  # obwohl diese Befehle nicht ausführbar sind
  if ($IncludeTabExpansion)
  {
    $null = $BaseCommands.Add('tabexpansion2')
    Write-Verbose 'Enabling Tabexpansion'
  }
  
  if ($AllowedCommands.Count -gt 0)
  {
    $BaseCommands.AddRange($AllowedCommands)
    Write-Verbose "Enabling Explicit Commands: $AllowedCommands"
  }
  
  # ExecutionPolicy setzen
  Set-ExecutionPolicy -Scope Process -ExecutionPolicy $ExecutionPolicy -ErrorAction SilentlyContinue
  Write-Verbose "Setting Execution Policy: $ExecutionPolicy"

  # Alle Befehle mit Ausnahme der erlaubten Befehle verstecken
  [System.Collections.ArrayList]$hide = @(Get-Command | 
  Where-Object {$BaseCommands -notcontains $_.Name}) |
  Where-Object {
    $name = '{0}-{1}' -f $_.Name, $_.CommandType 
    
    $issCmd = $issHash[$name]
    !$issCmd -or $issCmd.Visibility -ne 'Public'
  }

  # Alle Aliase mit Ausnahme der erlaubten verstecken:
  Get-Alias | 
  Where-Object {$BaseCommands -notcontains $_.Name} | 
  ForEach-Object { $null = $hide.Add($_) }

  Write-Verbose "Language Mode = $LanguageMode"
  
  foreach($hidden in $hide) 
  { 
    Write-Verbose ('Hiding {0} ({1})' -f $hidden.Name, $hidden.CommandType)
  }
  
  foreach($hidden in $hide) 
  { 
    $hidden.Visibility = 'Private' 
  }

  # LanguageMode setzen
  $ExecutionContext.SessionState.LanguageMode = $LanguageMode
}
