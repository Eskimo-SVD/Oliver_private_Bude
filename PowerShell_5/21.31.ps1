Get-ChildItem -Path $env:windir -Recurse -ErrorAction SilentlyContinue | 
  ForEach-Object -Begin { 
    $c = 0 
  } -Process { 
    # empfangene Elemente zählen
    $c++

    # wenn mehr als 5 Elemente empfangen wurden, einen Fehler auslösen:
    if ($c -gt 5) { Throw 'Ich habe fünf Elemente, mehr will ich nicht!' } 
    
    # empfangenes Element ausgeben
    $_ 
  }
