--
-- EPITECH PROJECT, 2021
-- pushswapchecker
-- File description:
-- swapchecker
--

import System.Environment
import Data.List
import System.Exit

sa :: [String] -> [String]
sa [] = []
sa [x] = [x]
sa (x:y:xs) = y:x:xs

myTail :: [a] -> [a]
myTail [] = error "myTail -> Empty list"
myTail (_:a) = a

myListTuple :: [a] -> [b] -> ([a], [b])
myListTuple a b = (a, b)

callPa ::  [a] -> [a] -> ([a],[a])
callPa a b = myListTuple (pa a b) (myTail b)

pa :: [a] -> [a] -> [a]
pa a [] = a
pa a (b:_) = b : a

ra :: [a] -> [a]
ra a = myTail (myAppend a (myPutInString(myHead (a))))

rra :: [a] -> [a]
rra a = myInit (pa a (myPutInString(myLast (a))))

myAppend :: [a] -> [a] -> [a]
myAppend [] bs = bs
myAppend (a:as) bs = a : myAppend as bs

myInit :: [a] -> [a]
myInit [] = error "myInit"
myInit [_] = []
myInit (a:as) = a : myInit as

myHead :: [a] -> a
myHead [] = error "myHead -> Empty list"
myHead (a:_) = a

myPutInString :: a -> [a]
myPutInString a = [a]

myLast :: [a] -> a
myLast [] =  error("myLast -> Empty list")
myLast a = myNth a ((myLength a)-1)

myNth :: [a] -> Int -> a
myNth [] _ = error "myNth -> Too long index"
myNth _ x | myIsNeg x == True = error "myNth -> Negative Index"
myNth (a) x | x > 0 = myNth (myTail a) (x-1) 
            | otherwise = myHead a

myLength :: [a] -> Int
myLength [] = 0
myLength (_:a) = 1 + myLength a

myIsNeg :: Int -> Bool
myIsNeg x = x < 0


myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort f (x:xs) = myQuickSort f right ++ [x] ++ myQuickSort f left
    where (left, right) = partition (f x) xs


verifSort :: ([String], [String]) -> IO ()
verifSort (l_a, l_b@(_:_)) = putStrLn $ "KO: " ++ (show (l_a, l_b))
verifSort (l_a, []) = case l_a == myQuickSort (<) l_a of
    True -> putStrLn "OK"
    False -> putStrLn $ "KO: " ++ (show (l_a, [] :: [String]))


checkInstruct :: ([String],[String]) -> [String] -> IO()
checkInstruct list []  = verifSort list
checkInstruct (l_a, l_b) (x:xs) = case x of
    "sa" -> checkInstruct ((sa l_a), l_b) xs
    "sb" -> checkInstruct (l_a, (sa l_b)) xs
    "sc" -> checkInstruct ((sa l_a), (sa l_b)) xs
    "pa" -> checkInstruct (callPa l_a l_b) xs
    "pb" -> checkInstruct ((snd (callPa l_b l_a)), (fst (callPa l_b l_a))) xs
    "ra" -> checkInstruct ((ra l_a), l_b) xs
    "rb" -> checkInstruct (l_a, (ra l_b)) xs
    "rr" -> checkInstruct ((ra l_a), (ra l_b)) xs
    "rra" -> checkInstruct ((rra l_a), l_b) xs
    "rrb" -> checkInstruct (l_a, (rra l_b)) xs
    "rrr" -> checkInstruct ((rra l_a), (rra l_b)) xs
    _ -> exitWith (ExitFailure 84)

parseInput :: ([String],[String]) -> IO()
parseInput lists | readin (fst Lists) == true = getLine >>= (checkInstruct lists) . words

main :: IO()
main = getArgs >>= main' where
    main' l_a = parseInput (l_a, [])