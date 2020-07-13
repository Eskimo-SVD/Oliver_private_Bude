function Get-PathComponent 
{   
  param   
  (     
    [Parameter(Mandatory=$true)]     
    $Path   
  )
  # Rückgabewerte in einem Hashtable hinterlegen   
  $hash = [Ordered]@{     
    FileName = [System.IO.Path]::GetFileName($Path)
    BaseName = [System.IO.Path]::GetFileNameWithoutExtension($Path)
    Extension = [System.IO.Path]::GetExtension($Path)
    Parent = [System.IO.Path]::GetDirectoryName($Path)
    Drive  = [System.IO.Path]::GetPathRoot($Path)
    Path = $Path   
  }

  # Aus dem Hashtable ein Objekt herstellen
  $result = New-Object -TypeName PSObject -Property $hash 
      
  # Eigenschaften angeben, die sofort sichtbar sein sollen:
  [string[]]$sichtbar = 'BaseName','Extension','Parent'
  # daraus ein Info-Objekt herstellen, das PowerShell bei der Ausgabe
  # auswertet:
  $typ = 'DefaultDisplayPropertySet'
  [System.Management.Automation.PSMemberInfo[]]$info = 
    New-Object System.Management.Automation.PSPropertySet($typ,$sichtbar)

  # an Rückgabeobjekt anhängen:
  $result | 
    Add-Member -MemberType MemberSet -Name PSStandardMembers -Value $info -PassThru    
}
