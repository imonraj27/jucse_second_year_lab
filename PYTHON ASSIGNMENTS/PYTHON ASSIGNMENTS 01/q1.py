

import math


def isPrime(n):
    if n == 1 or n==0:
        return False
    if n == 2:
        return True
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


def showAllPrimes(a, b):
    print("ALL PRIMES--")
    for i in range(a, b+1):
        if isPrime(i):
            print(i, end=", ")
    print("\n")


a = int(input("Enter start point number: "))
b = int(input("Enter end point number: "))


showAllPrimes(a, b)
