function Select-Color
{
    param
    (
        [ValidateSet('Red','Green','Blue')]
        [String]
        $Color
    )

    "Gew�hlte Farbe: $Color"
}
