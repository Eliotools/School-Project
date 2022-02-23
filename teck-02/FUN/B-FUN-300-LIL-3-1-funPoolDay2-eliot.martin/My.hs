mySucc :: Int -> Int
myIsNeg :: Int -> Bool
myAbs :: Int -> Int
myMin :: Int -> Int -> Int
myMax :: Int -> Int -> Int
myTuple :: a -> b -> (a, b)
myTruple :: a -> b -> c -> (a, b, c)
myFst :: (a, b) -> a
mySnd :: (a, b) -> b
mySwap :: (a, b) -> (b, a)
myHead :: [a] -> a
myTail :: [a] -> [a]
myLength :: [a] -> Int
myNth :: [a] -> Int -> a
myTake :: Int -> [a] -> [a]
myInit :: [a] -> [a]
--smyDrop :: Int -> [a] -> [a] -> [a] -> [a] -> [a]
myReverse :: [a] -> [a]
myLast :: [a] -> a
myZip :: [a] -> [b] -> [(a, b)]
myUnzip  :: [(a,b)] -> ([a], [b])
myMap :: (a -> b) -> [a] -> [b]
myFilter :: (a -> Bool) -> [a] -> [a]
myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldr :: (a -> b -> b) -> b -> [a] -> b
myPartition :: (a -> Bool) -> [a] -> ([a], [a])

mySucc x = x + 1

myIsNeg x = x < 0

myAbs x | x < 0 = x*(-1)
        | otherwise = x

myMin x y | x < y = x
          | otherwise = y

myMax x y | x > y = x
          | otherwise = y

myTuple a b = (a, b)

myTruple a b c = (a, b, c)

myFst (a, b) = a

mySnd (a, b) = b

mySwap (a, b) = (b, a)

myHead [] = error "myHead -> Empty list"
myHead (a:_) = a

myTail [] = error "myTail -> Empty list"
myTail (_:a) = a

myLength [] = 0
myLength (_:a) = 1 + myLength a

myNth [] x = error "myNth -> Too long index"
myNth (a) x | myIsNeg x == True = error "myNth -> Negative Index"
myNth (a) x | x > 0 = myNth (myTail a) (x-1) 
            | otherwise = myHead a

myTake x (a) | myIsNeg x == True = error "myTake -> Negative Index"
myTake 0 (a) = []
myTake n [a] | n > myLength [a] = [a]
myTake n (a:as) = a : myTake (n - 1) as

myInit [] = error "myInit"
myInit [a] = []
myInit (a:as) = a : myInit as

myLast [] =  error("myLast -> Empty list")
myLast a = myNth a ((myLength a)-1)

{-
myDrop x (a) | myIsNeg x == True = error "myDrop -> Negative Index"
myDrop 0 (a) = (a)
myDrop x (a) | x > myLength(a) = []
             | otherwise = myDrop (x-1) (myTail (a))
-}

myAppend [] bs = bs
myAppend (a:as) bs = a : myAppend as bs

myReverse [] = []
myReverse as = myLast as : myReverse(myInit as)

myZip [] b = []
myZip a [] = []
myZip (a:as) (b:bs) = (a,b) : myZip as bs

myUnzip [] = ([], [])
myUnzip as = (map myFst as, myMap mySnd as)

myMap f [] = []
myMap f (a:as) = f a : myMap f as

myFilter _ [] = []
myFilter f (a:as) | f a = a : myFilter f as
                  | otherwise = myFilter f as

myFoldl f v [] = v
myFoldl f x (a:as) = myFoldl f (f x a) as

myFoldr f v [] = v
myFoldr f x a = myFoldr f (f (myLast a) x) (myInit(a))

myPartition f [] = error("Partiction -> empty Index")
myPartition f a = (myFilter f a, myFilter (not.f) a)

myPutInString :: a -> [a]
myPutInString a = [a]

pa :: [a] -> [a] -> [a]
pa a [] = a
pa a (b:bs) = b : a

ra :: [a] -> [a]
ra a = myTail (myAppend a (myPutInString(myHead (a))))

rra :: [a] -> [a]
rra a = myInit (pa a (myPutInString(myLast (a))))

callpa ::  [a] -> [a] -> ([a],[a])
callpa a b = myListTuple (pa a b) (myTail b)

myListTuple :: [a] -> [b] -> ([a], [b])
myListTuple a b = (a, b)