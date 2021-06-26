lmb = 0.8
A = 12
t = 3600
l = 0.3
deltaT = 24

Q = lmb * (A * t * deltaT)/l
print("Q = \u03BB {}".format(round(Q/1000)))
