#include <stdio.h>
#include <gmp.h>

void calculateOrder(const mpz_t a, const mpz_t m)
{
    mpz_t order;
    mpz_init(order);

    mpz_t result, gcd;
    mpz_inits(result, gcd, NULL);

    mpz_set_ui(order, 1); // Initialize order to 1
    mpz_gcd(gcd, a, m);
    if (mpz_cmp_ui(gcd, 1) > 0)
    {
        gmp_printf("Since there is common factor between %Zd and %Zd  order does not exists ." , a , m );
    }
    else
    {

        while (mpz_cmp(order, m) <= 0)
        {
            mpz_powm(result, a, order, m); // Calculate a^order mod m

            if (mpz_cmp_ui(result, 1) == 0)
            {
                gmp_printf("The order of %Zd modulo %Zd is %Zd\n", a, m, order);
                break; // Found the order
            }

            mpz_add_ui(order, order, 1); // Increment order
        }

        if (mpz_cmp(order, m) > 0)
        {
            gmp_printf("No order exists for %Zd modulo %Zd\n", a, m);
        }
    }
    mpz_clear(order);
    mpz_clear(result);
}

int main()
{
    mpz_t a, m;
    mpz_inits(a, m, NULL);
    gmp_printf("Enter a : ");
    gmp_scanf("%Zd", a);
    gmp_printf("Enter m : ");
    gmp_scanf("%Zd", m);
    calculateOrder(a, m);

    mpz_clear(a);
    mpz_clear(m);

    return 0;
}
