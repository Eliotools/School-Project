myElem :: Eq a => a -> [a] -> Bool
safeDiv :: Int  -> Int  -> Maybe  Int
safeNth :: [a] -> Int  -> Maybe a
myHead :: [a] -> a
myTail :: [a] -> [a]
myIsNeg :: Int -> Bool
safeSucc  :: Maybe Int -> Maybe Int
myLookup  :: Eq a => a -> [(a,b)] -> Maybe b
maybeDo  :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
readInt  :: [Char] -> Maybe  Int
readIntError :: [Char] -> Maybe Bool
getLineLength  :: IO Int
printAndGetLength  ::  String  -> IO Int
printBox  :: Int  -> IO ()
fsLine :: Int -> Int -> IO()
col :: Int -> Int -> IO()
inCol :: Int -> Int -> IO()
concatLines  :: Int  -> IO  String
getInt  :: IO (Maybe  Int)

myElem x [] = False
myElem x (a:as) | x == a = True
                | otherwise =  myElem x as

safeDiv x 0 = Nothing
safeDiv x y = Just (x `div` y)

safeNth [] x = Nothing
safeNth (a) x | myIsNeg x == True = Nothing
safeNth (a) x | x > 0 = safeNth (myTail a) (x-1) 
              | otherwise = Just (myHead a)

safeSucc (Just x) = Just (x + 1)
safeSucc _ = Nothing

myLookup x [] = Nothing
myLookup x ((a,b):as) | a == x = Just (b)
                      | otherwise = myLookup x as

maybeDo f (Just x) (Just y) = Just (f x y) 
maybeDo f _ _ = Nothing

readIntError [] = Just True
readIntError (x:xs)  | myElem x ['0'..'9'] == True = readIntError xs
                     | otherwise = Nothing
readInt [] = Nothing
readInt x | readIntError x == Just True = Just (read x::Int)
          | otherwise = Nothing

getLineLength = do input <- getLine
                   return (length input)

printAndGetLength input = do putStrLn(input)
                             return (length input)
printBox x | x <= 0 = return()
printBox x | x == 1 = putStrLn ("+")
printBox x = do fsLine x 0
                inCol (x) 0
                fsLine x 0

fsLine x y | y == ((2*x)-2) = do putStrLn ("+")
fsLine x 0 = do putStr ("+")
                fsLine x 1
fsLine x y = do putStr ("-")
                fsLine x (y+1)

col x y | y == ((2*x)-2) = do putStrLn ("|")
col x 0 = do putStr ("|")
             col x 1
col x y = do putStr (" ")
             col x (y+1)

inCol x y | y == (x-2) = do return()
inCol x y = do col x 0
               inCol x (y+1)

concatLines y = >>= x <- getLine
                   if y == 1
                       then return (x)
                       else do xs <- concatLines (y - 1)
                               return (x ++ xs)

getInt = do x <- getLine
            return (readInt x)


myIsNeg x = x < 0

myHead [] = error "myHead -> Empty list"
myHead (a:_) = a

myTail [] = error "myTail -> Empty list"
myTail (_:a) = a
