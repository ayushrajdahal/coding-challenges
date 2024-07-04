def check_palindrome(n):
    copy_n = n
    rev_n = 0
    while n > 0:
        rev_n = rev_n*10 + n%10
        n //= 10
    if copy_n == rev_n:
        return True
    return False

multiples = {}
palindromes = []

def largest_ndigit_palindrome(n):
    for i in range(10**n - 1, 0, -1):
        for j in range(10**n - 1, 0, -1):
            mult = i*j
            if check_palindrome(mult):
                palindromes.append(mult)
    highest_palindrome = 0
    for palindrome in palindromes:
        if palindrome > highest_palindrome:
            highest_palindrome = palindrome

    return highest_palindrome

print(largest_ndigit_palindrome(3))

