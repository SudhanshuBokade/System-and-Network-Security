import gmpy2

# Function to find the greatest common divisor (GCD) of two integers
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Function to find common divisors of an array of integers
def find_common_divisors(numbers):
    divisors = [numbers[0]]

    for i in range(1, len(numbers)):
        gcd_result = gcd(divisors[i - 1], numbers[i])

        for j in range(gcd_result, 0, -1):
            if gcd_result % j == 0:
                divisors.append(j)
                break

    return divisors

def main():
    n = int(input("Enter the number of integers: "))
    numbers = []

    for _ in range(n):
        num = gmpy2.mpz(input())
        numbers.append(num)

    common_divisors = find_common_divisors(numbers)

    print("Common divisors:", " ".join(str(d) for d in common_divisors))

if __name__ == "__main__":
    main()
