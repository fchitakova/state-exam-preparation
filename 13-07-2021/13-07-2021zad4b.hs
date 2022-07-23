quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort (x:xs) = quickSort lesser ++ [x] ++ quickSort greater
    where 
       lesser = filter (<x) xs
       greater = filter (>=x) xs