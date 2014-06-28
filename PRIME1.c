#include <stdio.h>
#include <string.h>

#define LIM 500000
/* In the problem max number of primes to find is N-M <= 100000 */
#define MAX_SEGMENT_SIZE 100000

/* Define arrays globally to avoid segfaults due to large stack */
unsigned long primes[MAX_SEGMENT_SIZE];
short isPrime[LIM];
short boundedSieve[LIM];

/* Algorithm taken from: http://primesieve.org/segmented_sieve.html */

int main(int argc, const char * argv[])
{

    unsigned long n;
    unsigned long a, b, i, j, low, high;
    int T;
    memset((void *) isPrime, 1, LIM * sizeof(short));
    
    /* Precompute initial sieve primes */
    n = 0;
    isPrime[0] = isPrime[1] = 0;
    
    for (i = 0; i < LIM; i++) {
        if (isPrime[i]) {
            primes[n++] = i;
            for (j = 2; i * j < LIM; j++)
                isPrime[i * j] = 0;
        }
    }
    
    scanf("%d", &T);
    while (T--) {
        memset((void *) boundedSieve, 1, LIM * sizeof(short));
        scanf("%ld %ld", &a, &b);
        /* Print the sieve primes if less than LIM */
        if (b < LIM) {
            for (i = a; i <= b; i++)
                if (isPrime[i])
                    printf("%ld\n", i);
                continue;
        }
        /* sqrt(1000000000) ~ 31622 need at least 32k primes */
        for (i = 0; i < 32000 && primes[i] * primes[i] < b; i++) {
            /* determine segments */
            low = (a / primes[i]) * primes[i];
            high = (b / primes[i]) * primes[i];
            /* sieve current segment */
            while (low <= high) {
                if (low >= a && low <= b)
                    boundedSieve[low-a] = 0;
                low += primes[i];
            }
        }
        for (i = a; i <= b; i++) {
            if (boundedSieve[i-a])
                printf("%ld\n", i);
        }
    }
    return 0;
}

