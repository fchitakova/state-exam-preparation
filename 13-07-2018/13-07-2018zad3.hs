
addDefault val [] = [val]
addDefault val l = l


sumMinFix fl xl = sum (map (\f -> minimum (addDefault 0 [x | x <- xl, (f x) == x])) fl)
