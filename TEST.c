#include <stdio.h>

/* TEST */

int main(int argc, const char * argv[])
{
    int i;
    /* Continue rewriting numbers until 42 is read */
    while(1) {
        scanf("%d", &i);
        if (i == 42)
            break;
        else
            printf("%d\n", i);
    }
    return 0;
}