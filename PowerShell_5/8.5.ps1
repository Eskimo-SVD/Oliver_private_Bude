function Set-ConsoleWidth
{
  param
  (
    [Int]
    # gewünschte Breite der Konsole, optional
    # Vorgabe ist die sichtbare Breite:
    $Width = $Host.UI.RawUI.WindowSize.Width,

    [Switch]
    # automatisch Konsole so breit wie möglich machen
    $Maximum
  )

  # maximal mögliche Breite der Konsole:
  $maximumWidth = $Host.UI.RawUI.MaxPhysicalWindowSize.Width

  # aktuelle Breite der Konsole:
  $currentWindowWidth = $Host.UI.RawUI.WindowSize.Width

  # aktuelle Breite des Puffers:
  $currentBufferWidth = $Host.UI.RawUI.BufferSize.Width

  # maximale Breite gewünscht?
  if ($Maximum)
  {
    $Width = $maximumWidth
  }
  # Wunschbreite angegeben?
  elseif ($Width)
  {
    # falls größer als maximal erlaubt, begrenzen:
    if ($Width -gt $maximumWidth)
    {
      $Width = $maximumWidth
    }
  }

  # die Logik zum Anpassen des Buffers und des Fensters
  # sind interne Funktionen, weil diese je nach
  # aktuellen Werten in anderer Reihenfolge
  # aufgerufen werden müssen:
  function AdjustBuffer
  {
      # Konsolenpuffer auf neue Breite setzen:
      $buffer = $Host.UI.RawUI.BufferSize
      $buffer.Width = $Width
      $Host.UI.RawUI.BufferSize = $buffer
  }

  function AdjustWindow
  {
      # Sichtbaren Bereich anpassen
      $buffer = $Host.UI.RawUI.WindowSize
      $buffer.Width = $Width
      $Host.UI.RawUI.WindowSize = $buffer
  }

  # falls das Fenster aktuell GRÖSSER ist als die
  # neue gewünschte Breite, dann muss das Fenster
  # ZUERST verkleinert werden, bevor der Puffer
  # verkleinert werden darf:
  if ($currentWindowWidth -gt $Width)
  {
    AdjustWindow
    AdjustBuffer
  }
  # andernfalls umgekehrt:
  else
  {
    AdjustBuffer
    AdjustWindow
  }
}
