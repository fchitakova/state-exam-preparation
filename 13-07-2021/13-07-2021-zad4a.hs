module Data where

data Tree a = EmptyTree | Node {
    value :: a,
    left  :: Tree a,
    right :: Tree a
} deriving(Show, Read)

treeWords :: (Tree Char) -> [[Char]]
treeWords EmptyTree = []
treeWords (Node v EmptyTree EmptyTree) = [[v]]

treeWords (Node v l r) = map (v:) (wl ++ wr)
   where wl = treeWords l 
         wr = treeWords r

-- ТЕСТ -> РЕЗУЛТАТЪТ ТРЯБВА ДА БЪДЕ ["abcd", "abe", "azm", "azl"]
-- t = Node 'a' (Node 'b' (Node 'c' (Node 'd' EmptyTree EmptyTree) EmptyTree) (Node 'e' EmptyTree EmptyTree)) (Node 'z' (Node 'm' EmptyTree EmptyTree) (Node 'l' EmptyTree EmptyTree)) 
-- treeWords t