import sys
import gmpy2
import random
import math
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

def calculate_RRSM(n):
    RRSM = []
    for i in range(2,n):
        if gcd_of_two(i,n)==1:
            RRSM.append(i)
    return RRSM

#key generation phase
#lets take two prime numbers p and q
p =53
q =59
n = p * q
euler_totient = (p-1)*(q-1)
e = random.choice(calculate_RRSM(euler_totient))

def encrypt(plaintext):
    k = random.randrange(1,n)
    A = gmpy2.powmod(k,e,n)
    print(k,A)
    H=""
    plaintext_encrypt=[]
    for i in plaintext:
        plaintext_encrypt.append(int(gmpy2.f_mod(gmpy2.f_mod(ord(i),n)*gmpy2.powmod(k+1,e,n),n)))
    for i in plaintext:
        H += str(gmpy2.powmod(ord(i),k,100))
    return [int(A),plaintext_encrypt,int(H)]


def decrypt(A,B,H,d,encryption_key):
    k = gmpy2.powmod(A,d,n)
    print(k)
    k_plus_1_power_e = gmpy2.powmod(k + 1, encryption_key, n)
    plaintext_decrypt=[]
    for i in B:
        plaintext_decrypt.append(int(gmpy2.f_mod(int(i) * gmpy2.invert(k_plus_1_power_e, n), n)))
    res =""
    h=""
    for i in plaintext_decrypt:
        h += str(gmpy2.powmod(int(i),k,100))
    h = int(h)
    if h == H:
        print("True")
        for i in plaintext_decrypt:
            res += chr(int(i))
    else:
        print("hash didn't match")
    return res
    

if(sys.argv[1]=="-e"):
    plaintext = sys.argv[2]
    print(encrypt(plaintext),e)
elif(sys.argv[1]=="-d"):
    A = int(sys.argv[2])
    length = len(sys.argv[3])
    B = sys.argv[3][1:length-1]
    B = B.split(', ')
    H = int(sys.argv[4])
    encryption_key = int(sys.argv[5])
    d = calculate_inverse(encryption_key,euler_totient)
    while d < 0:
        d = d + euler_totient
    
    print(decrypt(A,B,H,d,encryption_key))
else:
    print("use -e for encryption or -d for decryption")