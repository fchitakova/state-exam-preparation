products = [(11 ,3.50), (12, 6.30), (13, 7.7), (14, 110), (15, 4.50), (16, 7.30), (17, 8.70), (18, 8.70)]
basket = [11, 12, 13]

findPrice product = snd (head (filter (\x -> fst x == product) products))

bestFit code = fst (head (filter (\x -> (snd x) == ((findPrice code) + 1.00)) products))


recommended basket bestFit products = 
  filter (\product -> (not (elem product basket) && (findPrice product) <= basketCost)) (map bestFit basket) 
     where findPrice product = snd (head (filter (\x -> fst x == product) products))
           basketCost = sum (map findPrice basket)

recommend = recommended basket bestFit products 