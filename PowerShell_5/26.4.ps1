workflow Test-Workflow
{
    # Splatting wird nicht unterst�tzt:
    $hash = @{Name = 'Spooler'}
    Get-Service  @hash
}
