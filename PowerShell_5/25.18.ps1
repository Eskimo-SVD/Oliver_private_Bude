$hash = [hashtable]::Synchronized(@{})
$hash.Info = 'es geht los!'

1..5 | Foreach-Parallel { 
    "Durchlauf $_ : Information ist: " + $hash.Info 
    
    # Variablen sollten NICHT geändert werden!
    $hash.Info = "thread $_ war hier!"
} -UseLocalVariables
