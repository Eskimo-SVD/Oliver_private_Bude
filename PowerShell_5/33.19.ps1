function Get-Ast
{

  param
  (
    [ValidateSet('All','Array','ArrayLiteral','AssignmentStatement','Attribute',
        'AttributeBase','Attributed','Binary','BlockStatement','BreakStatement',
        'CatchClause','Command','CommandBase','CommandElement','CommandParameter',
        'Constant','ContinueStatement','Convert','DataStatement','DoUntilStatement',
        'DoWhileStatement','Error','ErrorStatement','ExitStatement','ExpandableString',
        'FileRedirection','ForEachStatement','ForStatement','FunctionDefinition',
        'Hashtable','IfStatement','Index','InvokeMember','LabeledStatement',
        'LoopStatement','Member','MergingRedirection','NamedAttributeArgument',
        'NamedBlock','ParamBlock','Parameter','Paren','Pipeline','PipelineBase',
        'Redirection','ReturnStatement','ScriptBlock','SequencePoint','Statement',
        'StatementBlock','StringConstant','Sub','SwitchStatement','ThrowStatement',
        'TrapStatement','TryStatement','Type','TypeConstraint','Unary',
        'Using','Variable','WhileStatement')]
    $AstType='All',
    
    [String]
    $Code = $psise.CurrentFile.Editor.Text,
        
    [Switch]
    $NonRecurse,
        
    [System.Management.Automation.Language.Ast]
    $Parent=$null
  )

  # provide buckets for errors and tokens
  $Errors = $Tokens = $null

  # ask PowerShell to parse code
  $AST = [System.Management.Automation.Language.Parser]::ParseInput($Code, [ref]$Tokens, [ref]$Errors)

  [bool]$recurse = $NonRecurse.IsPresent -eq $false

  # search for AST instances recursively
  if ($AstType -eq 'All')
  {
    $AST.FindAll({ $true }, $recurse) | 
      Where-Object { $Parent -eq $null -or 
      ($_.Extent.StartOffset -ge $Parent.Extent.StartOffset -and
      $_.Extent.EndOffset -le $Parent.Extent.EndOffset) } |
      Add-Member -Member ScriptProperty -Na ASTType -Value { $this.GetType().Name } -Pa
  }
  else
  {
    $AST.FindAll({ $args[0].GetType().Name -like "*$ASTType*Ast" }, $recurse) | 
    Where-Object { $Parent -eq $null -or 
      ($_.Extent.StartOffset -ge $Parent.Extent.StartOffset -and 
    $_.Extent.EndOffset -le $Parent.Extent.EndOffset) } |
      Add-Member -Member ScriptProperty -Na ASTType -Value { $this.GetType().Name } -Pa
  }
}
