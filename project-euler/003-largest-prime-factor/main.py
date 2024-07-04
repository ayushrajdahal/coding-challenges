import collections
import time

start_time = time.time()

def largest_prime_factor(n):
    for i in range(2, n):
        other_factor = n/i
        other_factor_int = int(other_factor)
        if other_factor == other_factor_int and check_prime(other_factor_int):
            return other_factor_int

is_prime = collections.defaultdict(bool)

def check_prime(n):
    if n in is_prime.keys():
        return is_prime[n]
    for i in range(2,n):
        if n % i == 0:
            is_prime[n] = False
            return False
        
    return True

print(largest_prime_factor(600851475143))

print(f'Time taken(seconds): {time.time() - start_time}')
