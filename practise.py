from math import gcd as bltin_gcd
def primitive(n):
    required_set = {num for num in range(1,n) if bltin_gcd(n ,num) == 1}
    return [g for g in range(1 , n ) if required_set  == {pow(g , powers , n) for powers in range(1,n)}]

n = int(input("Enter the number"))
print(primitive(n))