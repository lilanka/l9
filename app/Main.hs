module Main where

import System.Environment
import CC 

main :: IO ()
main = do
  args <- getArgs
  contents <- readFile (head args) 
  cc contents
  {-
  let summary = (countsText . getCounts) contents 
  appendFile "stats.dat" (mconcat [fileName, " ", summary, "\n"])
  putStrLn summary

getCounts :: String -> (Int,Int,Int)
getCounts input = (charCount, wordCount, lineCount)
  where charCount = length input
        wordCount = (length . words) input
        lineCount = (length . lines) input

countsText :: (Int,Int,Int) -> String
countsText (cc,wc,lc) =  unwords ["chars: "
                                  , show cc
                                  , " words: "
                                  , show wc
                                  , " lines: " 
                                  ,  show lc]-}
