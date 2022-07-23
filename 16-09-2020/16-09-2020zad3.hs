
-- [("Mozart","The Marriage of Figaro Overture",270), ("Gershwin","Summertime",
-- 300), ("Queen","Bohemian Rhapsody",355), ("Gershwin","Rhapsody in Blue",1100)]

recommender pl = 
let avgDuration artist = (\l -> div (sum . map (\(_,_,x) -> x) . filter (\(a,_,_) -> a == artist) $ l) (length . map (\(_,_,x) -> x) . filter (\(a,_,_) -> a == artist) $ l))
    option1 = (\p -> filter (\(a,_,l) -> a == artist && l > p))
    option2 = filter (\(x,_,_) -> avgDuration x < avgDuration artist)
in if not (null option1) then (head option1)
   else if not (null option1) then  (maximum  option2)
        else tail

-- [ fn | (_, fn, grade) <- students, grade >= 2 ]
-- avgDuration artist = (\l -> div (sum . map (\(_,_,x) -> x) . filter (\(a,_,_) -> a == artist) $ l) (length . map (\(_,_,x) -> x) . filter (\(a,_,_) -> a == artist) $ l))


-- option2 artist = \pl -> filter (\(x,_,_) -> avgDuration x < avgDuration artist) pl