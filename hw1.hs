import Debug.Trace ( trace ) 
-- 9/1/2021
-- GCD of a,b using Euclid 

-- printing all the ri
myGCD :: Integer -> Integer -> Integer   
myGCD a b = trace ("r = " ++ show b) $ if b == 0
      then a
      else myGCD b (a `mod` b)

-- too big too print
myBigGCD :: Integer -> Integer -> Integer   
myBigGCD a b 
      | b == 0    = a
      | otherwise = myBigGCD b (a `mod` b)

-- main for numbers given (parts b & c)
main = do   
      putStrLn "GCD of 5287 & 3927"
      print(myGCD 5287 3927)
      putStrLn "GCD of 6277405925706921604898713904836 & 33905302297439148131685112836424"
      print(myBigGCD 6277405925706921604898713904836 33905302297439148131685112836424)

-- NOTE: have been wanting to use / learn Haskell for a while - I'd like to try and use it for this class



