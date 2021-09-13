# Finding coefficents m & n with the Euclid Extended Algotithm
# NOTE: Clone of other -- modified for inverse modulo
def gcdExtend(a, b, n):
    # Init s & t
    s_prev, s = 1, 0
    t_prev, t = 0, 1
    # Inverse Params
    p_list = [0, 1]
    q_list = []
    # Counter
    i = 0
    while b != 0:
        """
        From the .hs file...
        r (i + 1) = r (i - 1) - qi*ri
        s (i + 1) = s(i - 1) - qi*si, s0 = 1, s1 = 0
        t (i + 1) = t(i - 1) - qi*ti t0 = 0, t1 = 1
        Using top-down method - combine the above for s, t with first program (hw1) for computing GCD
        """
        if (i > 1):
            p_list.append((p_list[i-2] - p_list[i-1] * q[i-2]) % n)
        (q, b), a = divmod(a, b), b  
        q_list.append(q)
        t_prev, t = t, t_prev - q*t
        s_prev, s = s, s_prev - q*s
        i = i + 1
    p_f = (p_list[i-2] - p_list[i-1]*q_list[i-2]) % n
    return a, s_prev, t_prev, p_f

# Find inverse of 17 mod 103
# Use relation pi = pi-2 - pi-1 * qi-2 (mod n), source of algorithm: http://www-math.ucdenver.edu/~wcherowi/courses/m5410/exeucalg.html
a, b, n = 103, 17, 103
g, s, t, p = gcdExtend(a, b, n)
print(g, "=", s, "*", a, "+", t, "*", b)
print("Inverse Modulo: ", p)