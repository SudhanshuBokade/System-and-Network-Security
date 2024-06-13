import sys
import gmpy2
import random
import Crypto
from Crypto.Util.number import *
from Crypto import Random

alpha_dict = {1:'a',2:'b',3:'c',4:'d',5:'e',6:'f',7:'g',8:'h',9:'i',10:'j',11:'k',12:'l',13:'m',14:'n',15:'o',16:'p',17:'q',18:'r',19:'s',20:'t',21:'u',22:'v',23:'w',24:'x',25:'y',26:'z'}
key_list = list(alpha_dict.keys())
val_list = list(alpha_dict.values())

def gcd_of_two(a, b):
    if b == 0:
        return a
    a = gmpy2.f_mod(a,b)
    return gcd_of_two(b, a)
def lcm_of_two(a,b):
    return (a*b)//gcd_of_two(a,b)

def calculate_inverse(a,b):
    t1 =0 
    t2 =1
    r1 = max(a,b)
    r2 = min(a,b)
    while(r2>0):
        q= gmpy2.f_div(r1,r2)
        r = gmpy2.f_mod(r1,r2)
        t = t1-q*t2
        t1 = t2
        t2 = t
        r1=r2
        r2 = r        
    return t1

def calculate_encryption_key(n):
    for i in range(2,n):
        if gcd_of_two(i,n)==1:
            return i
    

#key generation phase
#lets take two prime numbers p and q
length = 4096
b=3
bits = length//b
p = Crypto.Util.number.getPrime(bits,randfunc=Crypto.Random.get_random_bytes)
q = Crypto.Util.number.getPrime(bits,randfunc=Crypto.Random.get_random_bytes)
r = Crypto.Util.number.getPrime(bits,randfunc=Crypto.Random.get_random_bytes)
n = p * q * r
euler_totient = (p-1)*(q-1)*(r-1)
e = calculate_encryption_key(euler_totient)

def encrypt(plaintext):
    encrypted_plaintext = []
    for i in plaintext:
        encrypted_plaintext.append(int(gmpy2.powmod(ord(i),e,n)))
    return encrypted_plaintext


def decrypt(ciphertext,d,p,q,r):
    d = gmpy2.mpz(d)
    mod_value = gmpy2.mpz(p*q*r)
    plaintext_decrypt = []
    for num in ciphertext:
        number = gmpy2.mpz(num)
        plaintext_decrypt.append(gmpy2.powmod(number,d,mod_value))
    print(plaintext_decrypt)
    res =""
    for i in plaintext_decrypt:
        res += chr(int(i))
    return res
    

if(sys.argv[1]=="-e"):
    plaintext = sys.argv[2]
    plaintext_list = encrypt(plaintext)
    print(plaintext_list,e,p,q,r)
    print(''.join(str(p) for p in plaintext_list))
elif(sys.argv[1]=="-d"):
    length = len(sys.argv[2])
    ciphertext = sys.argv[2][1:length-1]
    ciphertext = ciphertext.split(', ')
    encryption_key = int(sys.argv[3])
    p = int(sys.argv[4])
    q = int(sys.argv[5])
    r = int(sys.argv[6])
    phi_n = (p-1)*(q-1)*(r-1)
    d = calculate_inverse(encryption_key,phi_n)
    while d < 0:
        d = d + euler_totient
    
    print(decrypt(ciphertext,d,p,q,r))
else:
    print("use -e for encryption or -d for decryption")


