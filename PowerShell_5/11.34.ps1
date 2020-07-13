function Find-TypeByCommandName
{
  param
  (
    [Parameter(Mandatory=$true)]
    $Keyword
  )

  # diese Methoden sind zu allgemein, ausschlie�en:
  $excludeAll = 'Invoke|InitializeLifetimeService|GetType|GetHashCode|Equals|Dispose'

  # diese Namensendung wird f�r asynchrone Aufrufe ben�tigt, ausschlie�en:
  $excludeEnding = 'Async'

  # diese Pr�fixe sind Methoden, die Eigenschaften und Operatoren abbilden. Ausschlie�en:
  $excludeStarting = 'get_|set_|op_|add_|remove_'

  [AppDomain]::CurrentDomain.GetAssemblies() |
  ForEach-Object { try { $_.GetExportedTypes() } catch {} } |
  Where-Object { $_.isPublic} |
  Where-Object { $_.isClass } |
  Where-Object { $_.Name -notmatch '(Attribute|Handler|Args|Exception|Collection|Expression)$' }|
  # nur Methoden, die dem Schl�sselwort entsprechen, und Doppelg�nger ausschlie�en:
  ForEach-Object { $_.GetMethods() | Where-Object { $_.Name -like $Keyword } | Sort-Object Name -Unique } |
  # die allgemeinen Methoden nach den Ausschlusslisten entfernen:
  Where-Object { $_.Name -notmatch "^($excludeStarting)" } |
  Where-Object { $_.Name -notmatch "($excludeEnding)$" } |
  Where-Object { $_.Name -notmatch "$excludeAll" } |
  Select-Object -Property Name, DeclaringType
}
