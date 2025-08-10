from sympy import primerange  # imports a function to generate primes in a range

def countPrimes(n: int) -> int:
    # primerange(a, b) generates all prime numbers p such that a <= p < b
    primes = list(primerange(2, n))  # generate all primes less than n
    return len(primes)  # count them

# Example
print(countPrimes(10))  # Output: 4
