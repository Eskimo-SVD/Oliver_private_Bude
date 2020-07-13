$Information = 'Dies ist eine lokale Variable'

1..5 | Foreach-Parallel { "Durchlauf $_ : Information ist: $Information" }
