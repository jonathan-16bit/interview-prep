def fib(n):
    if n == 0 or n == 1:
        return n
    return fib(n - 1) + fib(n - 2)

def main():
    n = 20
    for i in range(n + 1):
        print(fib(i), end=" ")
    print()

main()
