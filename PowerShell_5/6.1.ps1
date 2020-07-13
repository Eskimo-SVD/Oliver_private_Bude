$hotfixes = Get-HotFix

foreach($hotfix in $hotfixes)
{
    if ($hotfix.HotFixID -like 'KB30*')
    {
        $hotfix
    }
}
