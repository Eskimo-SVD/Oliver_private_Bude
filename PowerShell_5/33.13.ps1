function Find-AddonMenu
{
  param(
    $Title = '*',
    $MenuItem = $psISE.CurrentPowerShellTab.AddOnsMenu,
    [switch]
    $Recurse
  )

  foreach($item in $MenuItem.SubMenus)
  {
    if ($Recurse)
    {
      Find-AddonMenu -Title $title -MenuItem $item
    }

    if ($item.DisplayName -eq $Title)
    {
      $item
    }
  }
}

function New-AddonMenu
{
  param
  (
    [Parameter(Mandatory=$true)]
    $DisplayName,

    [ScriptBlock]
    $Action=$null,

    $Shortcut=$null
  )
  try
  {
    $Parent = $psISE.CurrentPowerShellTab.AddOnsMenu
    $Items = $DisplayName.Split('\')
    for($x=0; $x -lt $Items.Count-1; $x++)
    {
      $name = $Items[$x]
      $item = Find-AddonMenu -Title $name -MenuItem $parent
      if ($item -eq $null)
      {
        $item = $parent.SubMenus.Add($name, $null, $null)
      }
      $parent = $item
    }

    $item = Find-AddonMenu -Title $Items[-1] -MenuItem $parent
    if ($item -ne $null)
    {
      Write-Warning 'Menu item already exists.'
      break
    }

    try
    {
      $parent.SubMenus.Add($Items[-1], $Action, $Shortcut)
    }
    catch
    {
      try
      {
        $parent.SubMenus.Add($Items[-1], $Action, $null)
      }
      catch
      {
        Write-Warning "Unable to create addon menu item: $_"
      }
    }
  }
  catch
  {
    Write-Warning "Unable to create addon menu item: $_"
  }

}

function Remove-AddonMenu
{
  param
  (
    [Parameter(Mandatory=$true)]
    $DisplayName
  )

  $Parent = $psISE.CurrentPowerShellTab.AddOnsMenu
  $Items = $DisplayName -split '\\'
  $MenuItems = @($psISE.CurrentPowerShellTab.AddOnsMenu)
  for($x=0; $x -lt $Items.Count; $x++)
  {
    $name = $Items[$x]
    $parent = Find-AddonMenu -Title $name -MenuItem $parent
    $MenuItems += $parent
  }

  for($x=$MenuItems.Count -1; $x -gt 0; $x--)
  {
    if ($MenuItems[$x].SubMenus.Count -eq 0)
    {
      $null = $MenuItems[$x-1].Submenus.Remove($MenuItems[$x])
    }
  }
}
