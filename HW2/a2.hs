-- Extended Euclidean Algorithm
-- g = gcd(a,b)
-- (m,n) -> ma + nb = g
 
-- function type
extendGCD :: Integer -> Integer -> (Integer, Integer, Integer)  

-- NOTES:
-- from wiki https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm can use the Bezout coefficients
-- r (i + 1) = r (i - 1) - qi*ri
-- s (i + 1) = s(i - 1) - qi*si, s0 = 1, s1 = 0
-- t (i + 1) = t(i - 1) - qi*ti t0 = 0, t1 = 1
-- You can work this out using a top-down approach in calculating each successive remainder (like above) (in eg.py I have this version)
-- With haskell a better (functional) approach is to run calculaiton in one recursive call
--      here, rather than storing each si and ti, can use the relation si = t (i-1) - (a // b)*s(i - 1); ti = s(i - 1)
--      NOTE: I didn't come up with this on my own, here is the source for this recurse: https://www.reddit.com/r/learnprogramming/comments/b8jnxj/haskell_extended_euclidean_algorithm_filter/

-- funciton
-- completed the gcd finding
extendGCD a 0 = (a, 0, 1)
-- otherwise 
extendGCD a b = let (g, s, t) = extendGCD b (a `mod` b) -- same as last time
     in (g, t - (a `div` b) * s, s)
  
main :: IO ()
main = do
    putStrLn "Extended Euclidean Algorithm"
    print(extendGCD 1020 544)