& {
  trap [System.ArithmeticException] {
    'Fehler in arithmetischer Operation'
    break
  }
  & {
    trap [System.Exception] {
      'Allgemeine Exception'
      break
    }

    & {
      trap [System.DivideByZeroException] {
        'Fehler beim Teilen durch Null'
        break
      }

      & {
        trap {
          'Allgemeiner Fehler'
          break
        }

        1 / $null
      }
    }
  }
}
