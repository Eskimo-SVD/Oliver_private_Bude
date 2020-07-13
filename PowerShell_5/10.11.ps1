$zeichen = 'abcdefghijklmnopqrstuvwxyz0123456789!"§$%&/()=?'.ToCharArray()
-join (Get-Random -InputObject $zeichen -Count 7)
