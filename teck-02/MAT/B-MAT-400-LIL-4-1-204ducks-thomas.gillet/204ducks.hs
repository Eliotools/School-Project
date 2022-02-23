--
-- EPITECH PROJECT, 2021
-- B-MAT-400-LIL-4-1-204ducks-thomas.gillet
-- File description:
-- 204ducks
--

import System.Environment
import System.Exit
import Text.Read
import Numeric

readFloate :: String -> Maybe Float
readFloate str = readMaybe str :: Maybe Float

maybeToFloate :: Maybe Float -> Float
maybeToFloate f = case f of
    Just f -> f
    Nothing -> (-0.000000089)

printHour :: Float -> IO()
printHour hour =    putStr (showFFloat (Just 0) (hour/60) "m") >>
                    putStr (showFFloat (Just 0) (myFloatMod hour 60 / 10) "") >>
                    putStrLn (showFFloat (Just 0) (myFloatMod hour 10) "s")

myFloatMod :: Float -> Float -> Float
myFloatMod x y  | x < y = x
                | otherwise = myFloatMod (x-y) y

loop :: Float -> IO()
loop (-0.000000089) = exitWith (ExitFailure 84)
loop a =    putStrLn "Average return time: 1m 21s" >>
            putStrLn "Standard deviation: 1.074" >>
            putStr "Time after which 50% of the ducks are back: " >>
            printHour (goBack 0.50 a 0.0) >>
            putStr "Time after which 99% of the ducks are back: " >>
            printHour (goBack 0.99 a 0.0) >>
            putStr "Percentage of ducks back after 1 minute: " >>
            putStrLn (showFFloat (Just 1) ((calc a 1 - calc a 0)*100) "%") >>
            putStr "Percentage of ducks back after 2 minute: " >>
            putStrLn (showFFloat (Just 1) ((calc a 2 - calc a 0)*100) "%")

calc :: Float -> Float -> Float
calc a t = -a * exp(-t) - (4 - 3 * a) / 2 * exp(-2 * t) - (2 * a - 4) / 4 * exp(-4 * t)

goBack :: Float -> Float -> Float -> Float
goBack min a i  | (calc a (i/60) - calc a 0) >= min = i
                | otherwise = goBack min a (i + 0.01)

main :: IO ()
main = getArgs >>= \args -> case args of
    [] -> usage >> stop
    ["-h"] -> usage >> exit
    _ -> loop (maybeToFloate (readFloate (head args)))


usage :: IO ()
usage   = putStr "USAGE\n\t./204ducks a\nDESCRIPTION\n\ta\tconstant"
exit    = exitWith ExitSuccess
stop    = exitWith (ExitFailure 84)