workflow Test-Workflow
{
    # Splatting wird nicht unterstützt:
    $hash = @{Name = 'Spooler'}
    Get-Service  @hash
}
