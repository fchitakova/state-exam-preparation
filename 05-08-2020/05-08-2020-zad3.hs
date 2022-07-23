module Defs where

--let track  = [(0 , 900), (100 , 910), (200 , 925), (300 , 905), (600 , 950)]
-- let tracks = [[(0, 900), (100 , 910), (200 , 925), (300 , 905), (600 , 950)],[(0, 1300), (100 , 1305), (500 , 1340), (800 , 1360), (1000 , 1320)],[(0 , 800), (200 , 830), (300 , 845), (600 , 880), (800 , 830)]]
-- f = (*) (-2)
argMin f l = foldr (\ x y -> if f x < f y then x else y) (head l) l

maxSlope track = maximum (map  (\ x -> abs ((snd (fst x) - snd (snd x)) / (fst (fst x) - fst (snd x)))) (zip track (tail track)))

easiestTrackUnder maxLen tracks = argMin maxSlope (filter (\x -> (snd (head (reverse x)) - snd (head x)) < maxLen) tracks)

