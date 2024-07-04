def check_palindrome_number(num:int):
    return reverse_num(num) == num

def reverse_num(num:int):
    reversed_num = 0
    while num > 0:
        reversed_num = reversed_num * 10 + num % 10
        num //= 10
    return reversed_num

def check_lychrel(n):
    for i in range(50):
        n = n + reverse_num(n)
        if check_palindrome_number(n):
            return False
    return True

lychrel_count = 0

for i in range(10_000):
    if check_lychrel(i):
        lychrel_count+=1


print(lychrel_count)
