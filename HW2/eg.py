# Finding coefficents m & n with the Euclid Extended Algotithm
def gcdExtend(a, b):
    # Init
    s_prev, s = 1, 0
    t_prev, t = 0, 1
    # Inverse
    p0, p1 = 0, 1
    while b != 0:
        """
        From the .hs file...
        r (i + 1) = r (i - 1) - qi*ri
        s (i + 1) = s(i - 1) - qi*si, s0 = 1, s1 = 0
        t (i + 1) = t(i - 1) - qi*ti t0 = 0, t1 = 1
        Using top-down method - combine the above for s, t with first program (hw1) for computing GCD
        """
        (quot, b), a = divmod(a, b), b
        t_prev, t = t, t_prev - quot*t
        s_prev, s = s, s_prev - quot*s
    return a, s_prev, t_prev
a, b = 103, 17
g, s, t,  = gcdExtend(a, b)
print(g, "=", s, "*", a, "+", t, "*", b)