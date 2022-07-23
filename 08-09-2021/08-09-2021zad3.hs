g:: (Num a) => [[a]] -> [[a]]
g([]:_) = []
g x = (map head x): g (map tail x)
