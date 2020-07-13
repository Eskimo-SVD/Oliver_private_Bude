trap [System.ArithmeticException] {
  'Fehler in arithmetischer Operation'
  continue
}

trap [System.Exception] {
  'Allgemeine Exception'
  continue
}

trap [System.DivideByZeroException] {
  'Fehler beim Teilen durch Null'
  continue
}

trap {
  'Allgemeiner Fehler'
  continue
}

1/$null
