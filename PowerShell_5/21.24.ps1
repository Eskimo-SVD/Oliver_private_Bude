function Get-DerivedException {
  param
  (
    [Parameter(Mandatory=$true)]
    $ExceptionName
  )

  # alle geladenen .NET-Assemblys...
  [AppDomain]::CurrentDomain.GetAssemblies() |
    # ...auf alle exportierten Typen durchsuchen (falls möglich)...
    ForEach-Object { try {$_.GetExportedTypes()} catch {} } |
    # ...aber nur solche, die im Namen "Exception" tragen...
    Where-Object { $_.Name -like '*Exception*' } |
    # ...und nur solche, die vom angegebenen Typ abgeleitet sind...
    Where-Object { $_.BaseType -like $ExceptionName } |
    # ...und davon bitte den Namen:
    Select-Object -ExpandProperty Name
}
