function Configure-System 
{
  [CmdletBinding(ConfirmImpact='High')]
  Param()

  ' Ich werde immer ausgef�hrt!'
  if ($PSCmdlet.ShouldProcess('Configure-System', '�nderungen am System'))
  {
    'Ich werde nur ausgef�hrt, wenn Sie zustimmen!'
  }
  else
  {
    'Ich werde ausgef�hrt, wenn Sie NICHT zustimmen'
  }
  'Ich werde auch immer ausgef�hrt!'
}
