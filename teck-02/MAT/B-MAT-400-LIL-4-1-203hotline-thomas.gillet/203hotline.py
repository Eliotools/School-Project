#!/usr/bin/python3
import sys
import argparse
import math
def main():
    args = parseArg()
    if (len(sys.argv) == 2):
        big(args.D)
    if (len(sys.argv) == 3):
        small(args.N, args.K)

def parseArg():
    parser = argparse.ArgumentParser()
    if (len(sys.argv) == 2):
        parser.add_argument("D", help="average duration of calls (in seconds)", type=int)
    else :
        parser.add_argument("N", help="n value for the computation of C(n, k)", type=int)
        parser.add_argument("K", help="k value for the computation of C(n, k)", type=int)
    args = parser.parse_args()
    return args

def big(D):
    print('D =',D)

def small(N,K):
    print (str(K) + "-combinations of a set of size " + str(N) + ":")
    print(int(binomFdp(N,K)))

def binomFdp (n, k):
    if (facto(k)*(facto(n-k)) == 0):
        exit (84)
    res = (facto(n)/(facto(k)*(facto(n-k))))
    return res

def binLay(n, k, p):
{
    res = binomFdp(n, k) * math.exp(p, k) * math.exp(1-p, n-k)
}
def facto (x):
    res = 1

    if (x < 0):
        return 0
    if (x == 0):
        return 1

    while (x != 1) :
        res = res * x
        x-=1

    return res

main()