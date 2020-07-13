function Select-Color
{
    param
    (
        [ValidateSet('Red','Green','Blue')]
        [String]
        $Color
    )

    "Gewählte Farbe: $Color"
}
