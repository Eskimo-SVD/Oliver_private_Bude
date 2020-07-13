function Find-TypeByCommandName
{
  param
  (
    [Parameter(Mandatory=$true)]
    $Keyword
  )

  # diese Methoden sind zu allgemein, ausschließen:
  $excludeAll = 'Invoke|InitializeLifetimeService|GetType|GetHashCode|Equals|Dispose'

  # diese Namensendung wird für asynchrone Aufrufe benötigt, ausschließen:
  $excludeEnding = 'Async'

  # diese Präfixe sind Methoden, die Eigenschaften und Operatoren abbilden. Ausschließen:
  $excludeStarting = 'get_|set_|op_|add_|remove_'

  [AppDomain]::CurrentDomain.GetAssemblies() |
  ForEach-Object { try { $_.GetExportedTypes() } catch {} } |
  Where-Object { $_.isPublic} |
  Where-Object { $_.isClass } |
  Where-Object { $_.Name -notmatch '(Attribute|Handler|Args|Exception|Collection|Expression)$' }|
  # nur Methoden, die dem Schlüsselwort entsprechen, und Doppelgänger ausschließen:
  ForEach-Object { $_.GetMethods() | Where-Object { $_.Name -like $Keyword } | Sort-Object Name -Unique } |
  # die allgemeinen Methoden nach den Ausschlusslisten entfernen:
  Where-Object { $_.Name -notmatch "^($excludeStarting)" } |
  Where-Object { $_.Name -notmatch "($excludeEnding)$" } |
  Where-Object { $_.Name -notmatch "$excludeAll" } |
  Select-Object -Property Name, DeclaringType
}
