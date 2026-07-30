import time
def iterative_factorial(n):
 fact=1
 for i in range(1,n+1):
    fact*=i
    return fact
def recursive_factorial(n):
    if n==0 or n==1:
     return 1
    return n*recursive_factorial(n-1)
n=int(input("Enter a number: "))
start=time.perf_counter()
it=iterative_factorial(n)
end=time.perf_counter()
iter_time=end-start
start=time.perf_counter()
rec=recursive_factorial(n)
end=time.perf_counter()
rec_time=end-start
print("Iterative Factorial:",it)
print("Iterative Time:",iter_time)
print("Recursive Factorial:",rec)
print("Recursive Time:",rec_time)