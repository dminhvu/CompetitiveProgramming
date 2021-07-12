# calculate n-th fibonacci number

# fib[1] = 1, fib[2] = 1
# fib[i] = fib[i - 1] + fib[i - 2]

# 0 1 2 3 4 5 6 7
# 0 1 1 2 3 5 8 13

# n is global variable

# YOUR CODE GOES HERE
n = int(input())
def fib(n):
    # n is local variable
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fib(n - 1) + fib(n - 2)

print(fib(n))
# END

# Calculate n-th factorial

# n! = n * (n - 1) * ... * 1
# fact(4) = 4 * fact(3) = 4 * 3 * 2 * 1 * fact(0)
# fact(3) = 3 * fact(2) = 3 * 2 * 1 * fact(0)
# fact(2) = 2 * fact(1) = 2 * 1 * fact(0)
# fact(1) = 1 * fact(0)
# fact(0) = 1

# YOUR CODE GOES HERE
n = int(input())
def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)
print(factorial(n))
# END