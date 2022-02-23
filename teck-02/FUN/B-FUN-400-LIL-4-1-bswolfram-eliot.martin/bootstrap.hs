--
-- EPITECH PROJECT, 2021
-- B-FUN-400-LIL-4-1-bswolfram-eliot.martin
-- File description:
-- bootstrap
--
import System.Environment
import Text.Read
import System.Exit
import Control.Monad
import Data.Maybe

data Conf = Conf {
    cRule :: Maybe Int,
    cStart :: Maybe Int,
    cLine :: Maybe Int,
    cWindow :: Maybe Int,
    cMove :: Maybe Int
}   deriving (Show)

defaultConf :: Conf
defaultConf = Conf {
    cRule = Nothing,
    cStart = Just 0,
    cLine = Nothing,
    cWindow = Just 80,
    cMove = Nothing
}

readPosInt :: String -> Maybe Int
readPosInt str  = readMaybe str >>= \nb -> guard (nb >= 0 ) >> Just nb

readMaxInt :: String -> Int -> Maybe Int
readMaxInt str maxNb = readMaybe str >>= \nb -> guard (nb >= 0 && nb <= maxNb) >> Just nb

getOpts :: Conf -> [String] -> Maybe Conf
getOpts conf [] = guard (cRule conf /= Nothing) >> Just conf
getOpts _ [_] = Nothing
getOpts conf (key:value:xs) = case key of
    "--rule" -> readMaxInt value 255 >>= \nb -> getOpts conf {cRule = Just nb} xs
    "--start" -> readPosInt value >>= \nb -> getOpts conf {cStart = Just nb} xs
    "--lines" -> readPosInt value >>= \nb -> getOpts conf {cLine = Just nb } xs
    "--window" -> readPosInt value >>= \nb -> getOpts conf {cWindow = Just nb} xs
    "--move" -> readMaybe value >>= \nb -> getOpts conf {cMove = Just nb} xs
    _ -> Nothing

goToRule :: Maybe Int -> Conf -> IO()
goToRule nb conf = case nb of
    Just 30  -> rule30loop (createList [] (maybeToInt (cWindow conf)) (maybeToInt (cWindow conf))) [] 0 (maybeToInt (cLine conf)-1) (maybeToInt (cWindow conf))
    Just 90  -> rule90loop (createList [] (maybeToInt (cWindow conf)) (maybeToInt (cWindow conf))) [] 0 (maybeToInt (cLine conf)-1) (maybeToInt (cWindow conf))
    Just 110 -> rule110loop (createList [] (maybeToInt (cWindow conf)) (maybeToInt (cWindow conf))) [] 0 (maybeToInt (cLine conf)-1) (maybeToInt (cWindow conf))
    _        -> putStrLn "usage : ./wolfram --rule RULE[--start START --lines LINES -- window WINDOW -- move MOVE]" >>
        exitWith(ExitFailure 84)

    maybeToInt :: Maybe Int -> Int
    maybeToInt (Just nb) = case Just nb of
        Just nb -> nb
        Nothing -> error "RWONG number"

    rule90loop :: [Char] -> [Char] -> Int -> Int -> Int -> IO()
    rule90loop str1 str2 nb max_row max_col | max_row == nb = putStrLn ""
                                            | otherwise = do 
                                                            putStrLn (rule90 str1 str2 0 max_col)
                                                            rule90loop (rule90 str1 str2 0 max_col) [] (nb+1) max_row max_col

    rule90 :: [Char] -> [Char] -> Int -> Int -> [Char]
    rule90 str str2 nb max_col | nb+1 == max_col = str2 ++ " "
    rule90 str str2 nb max_col = rule90 str (str2 ++ loop90 str nb max_col) (nb+1) max_col

    loop90 :: [Char] -> Int -> Int -> [Char]
    loop90 str 0 max   | head str == ' ' && str!!1 == ' ' =  " "
    loop90 str nb max  | nb == max = cmpLast str nb
                        | (str!!(nb-1)) == ' ' && str!!nb == ' ' && str!!(nb+1) == ' ' =  " "
                        | (str!!(nb-1)) == '*' && str!!nb == '*' && str!!(nb+1) == '*' =  " "
                        | (str!!(nb-1)) == '*' && str!!nb == '*' && str!!(nb+1) == ' ' =  "*"
                        | (str!!(nb-1)) == '*' && str!!nb == ' ' && str!!(nb+1) == '*' =  " "
                        | (str!!(nb-1)) == '*' && str!!nb == ' ' && str!!(nb+1) == ' ' =  "*"
                        | (str!!(nb-1)) == ' ' && str!!nb == '*' && str!!(nb+1) == '*' =  "*"
                        | (str!!(nb-1)) == ' ' && str!!nb == '*' && str!!(nb+1) == ' ' =  " "
                        | (str!!(nb-1)) == ' ' && str!!nb == ' ' && str!!(nb+1) == '*' =  "*"

rule110loop :: [Char] -> [Char] -> Int -> Int -> Int -> IO()
rule110loop str1 str2 nb max_row max_col | max_row == nb = putStrLn ""
                                        | otherwise = do 
                                                        putStrLn (rule110 str1 str2 0 max_col)
                                                        rule110loop (rule110 str1 str2 0 max_col) [] (nb+1) max_row max_col

rule110 :: [Char] -> [Char] -> Int -> Int -> [Char]
rule110 str str2 nb max_col | nb+1 == max_col = str2 ++ " "
rule110 str str2 nb max_col = rule110 str (str2 ++ loop110 str nb max_col) (nb+1) max_col

loop110 :: [Char] -> Int -> Int -> [Char]
loop110 str 0 max      | head str == ' ' && str!!1 == ' ' =  " "
loop110 str nb max     | nb == max = cmpLast str nb
                    | (str!!(nb-1)) == ' ' && str!!nb == ' ' && str!!(nb+1) == ' ' =  " "
                    | (str!!(nb-1)) == '*' && str!!nb == '*' && str!!(nb+1) == '*' =  " "
                    | (str!!(nb-1)) == '*' && str!!nb == '*' && str!!(nb+1) == ' ' =  "*"
                    | (str!!(nb-1)) == '*' && str!!nb == ' ' && str!!(nb+1) == '*' =  "*"
                    | (str!!(nb-1)) == '*' && str!!nb == ' ' && str!!(nb+1) == ' ' =  " "
                    | (str!!(nb-1)) == ' ' && str!!nb == '*' && str!!(nb+1) == '*' =  "*"
                    | (str!!(nb-1)) == ' ' && str!!nb == '*' && str!!(nb+1) == ' ' =  "*"
                    | (str!!(nb-1)) == ' ' && str!!nb == ' ' && str!!(nb+1) == '*' =  "*"


rule30loop :: [Char] -> [Char] -> Int -> Int -> Int -> IO()
rule30loop str1 str2 nb max_row max_col | max_row == nb = putStrLn ""
                                        | otherwise = do 
                                                        putStrLn (rule30 str1 str2 0 max_col)
                                                        rule30loop (rule30 str1 str2 0 max_col) [] (nb+1) max_row max_col

rule30 :: [Char] -> [Char] -> Int -> Int -> [Char]
rule30 str str2 nb max_col | nb+1 == max_col = str2 ++ " "
rule30 str str2 nb max_col = rule30 str (str2 ++ loop30 str nb max_col) (nb+1) max_col

loop30 :: [Char] -> Int -> Int -> [Char]
loop30 str 0 max      | head str == ' ' && str!!1 == ' ' =  " "
loop30 str nb max     | nb == max = cmpLast str nb
                    | (str!!(nb-1)) == ' ' && str!!nb == ' ' && str!!(nb+1) == ' ' =  " "
                    | (str!!(nb-1)) == '*' && str!!nb == '*' && str!!(nb+1) == '*' =  " "
                    | (str!!(nb-1)) == '*' && str!!nb == '*' && str!!(nb+1) == ' ' =  " "
                    | (str!!(nb-1)) == '*' && str!!nb == ' ' && str!!(nb+1) == '*' =  " "
                    | (str!!(nb-1)) == '*' && str!!nb == ' ' && str!!(nb+1) == ' ' =  "*"
                    | (str!!(nb-1)) == ' ' && str!!nb == '*' && str!!(nb+1) == '*' =  "*"
                    | (str!!(nb-1)) == ' ' && str!!nb == '*' && str!!(nb+1) == ' ' =  "*"
                    | (str!!(nb-1)) == ' ' && str!!nb == ' ' && str!!(nb+1) == '*' =  "*"

cmpLast :: [Char] -> Int -> [Char]
cmpLast str nb  | (str!!(nb-1)) == ' ' && last str == ' ' =  " \n"
                | (str!!(nb-1)) == '*' && last str == '*' =  " \n"
                | (str!!(nb-1)) == '*' && last str == '*' =  " \n"
                | (str!!(nb-1)) == '*' && last str == ' ' =  " \n"
                | (str!!(nb-1)) == '*' && last str == ' ' =  "*\n"
                | (str!!(nb-1)) == ' ' && last str == '*' =  "*\n"
                | (str!!(nb-1)) == ' ' && last str == '*' =  "*\n"
                | (str!!(nb-1)) == ' ' && last str == ' ' =  "*\n"

createList :: [Char] -> Int -> Int -> [Char]
createList (x:xs) 0 max  = x:xs
createList (x:xs) nb max |nb == (max `div` 2) = '*' : createList (x:xs) (nb-1) max 
createList (x:xs) nb max = x : createList (x:xs) (nb-1) max
createList [] nb max = createList [' '] (nb-1) max


main :: IO ()
main = getArgs >>= \args -> case getOpts defaultConf args of
    Nothing -> 
        putStrLn "usage : ./wolfram --rule RULE[--start START --lines LINES -- window WINDOW -- move MOVE]" >>
        exitWith(ExitFailure 84)
    Just conf -> goToRule (cRule conf) conf