Get-ChildItem -Path $env:windir -Recurse -ErrorAction SilentlyContinue | 
  ForEach-Object -Begin { 
    $c = 0 
  } -Process { 
    # empfangene Elemente z�hlen
    $c++

    # wenn mehr als 5 Elemente empfangen wurden, einen Fehler ausl�sen:
    if ($c -gt 5) { Throw 'Ich habe f�nf Elemente, mehr will ich nicht!' } 
    
    # empfangenes Element ausgeben
    $_ 
  }
