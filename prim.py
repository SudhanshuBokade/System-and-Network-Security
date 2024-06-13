from math import gcd as bltin_gcd
from math import sqrt
import numpy as np
divisors_list = []
n = int(input("Enter the number"))
n1 = n-1
for i in range(1 , int(sqrt(n1))+1):
    if n1%i == 0 : 
        divisors_list.append(i)
        divisors_list.append(n1//i)
divisors_list.remove(n1)        
print(divisors_list)
required_set = [x for x in range(1,n) if (pow(x,n1,n)== 1 & all(pow(x ,g , n )!=1 for g in divisors_list ))  ]
random.choice(required_set)