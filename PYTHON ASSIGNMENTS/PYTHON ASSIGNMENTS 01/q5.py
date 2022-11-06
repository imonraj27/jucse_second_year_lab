

def fibonacci(n):
    a, b = 1, 1
    for ii in range(n):
        yield a
        a, b = b, a + b


fibonacci_list = list(fibonacci(10))
print(fibonacci_list)
