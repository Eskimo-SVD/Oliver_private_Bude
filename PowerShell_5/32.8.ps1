$here = Split-Path -Parent $MyInvocation.MyCommand.Path
$sut = (Split-Path -Leaf $MyInvocation.MyCommand.Path).Replace(".Tests.", ".")
. "$here\$sut"

Describe "Get-HelloWorld" {
    It "outputs 'Hello World!" {
        Get-HelloWorld | Should Be 'Hello World!'
    }

    It "outputs 'Hello World [NAME]!" {
        Get-HelloWorld -Name Tobias | Should Be 'Hello World Tobias!'
    }
}
