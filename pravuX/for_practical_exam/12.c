#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Computes (a * b) % mod */
long long int mulmod(long long int a, long long int b, long long int mod)
{
    long long int res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (a * 2) % mod;
        b >>= 1;
    }
    return res;
}

/* Computes (a ^ b) % mod */
long long int powmod(long long int a, long long int b, long long int mod)
{
    long long int res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}

/* Miller-Rabin primality test */
char* miller_rabin(long long int n, int k)
{
    if (n < 2)
        return "composite";
    if (n == 2 || n == 3)
        return "probably prime";

    int s = 0;
    long long int d = n - 1;
    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }

    for (int i = 0; i < k; i++)
    {
        long long int a = (rand() % (n - 3)) + 2;
        long long int x = powmod(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        for (int j = 0; j < s - 1; j++)
        {
            x = mulmod(x, x, n);
            if (x == 1)
                return "composite";
            if (x == n - 1)
                break;
        }
        if (x != n - 1)
            return "composite";
    }
    return "probably prime";
}

int main()
{
    srand(time(NULL));

    long long int n;
    int k;
    printf("Enter an odd integer greater than 2: ");
    scanf("%lld", &n);
    printf("Enter the number of rounds of testing to perform: ");
    scanf("%d", &k);

    char* result = miller_rabin(n, k);
    printf("%lld is %s.\n", n, result);

    return 0;
}
