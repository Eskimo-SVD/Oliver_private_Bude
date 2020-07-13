do
{
  $eingabe = Read-Host 'Eine Zahl'

} until ($eingabe -as [Int])
