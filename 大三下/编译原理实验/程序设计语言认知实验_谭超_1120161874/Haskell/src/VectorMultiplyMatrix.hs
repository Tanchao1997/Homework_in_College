import System.IO
import Text.Printf
import System.CPUTime


col m = [x|x:xs <- m]
rights m = [xs|x:xs <- m,length(xs) > 0 ]
rowMulMat r []  = []
rowMulMat r m   = sum(zipWith (*) r (col m)):(rowMulMat r (rights m))

main =do
    vectorFile <- readFile"vector.txt"
    let vector=map (read::String->Int) (words vectorFile)
    matrixFile <- readFile"matrix.txt"
    let matLine = lines matrixFile
    let matrix = [map (read::String->Int) (words row) | row <- matLine]
    --let matrix=map (read::String->Int) (words matrixFile)
    startTime <- getCPUTime
    let result=rowMulMat vector matrix
    printf "result[999]: %d\n" (result!!(999))
    endTime <- getCPUTime
    let diff = (fromIntegral (endTime - startTime)) / (10^9)
    printf "Running time(size: 1000): %f ms\n"  (diff :: Double)

