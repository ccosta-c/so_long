#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int     main(void)
{
    int     random;

    srand (time(NULL));
    random = rand();
    random = random % (5 - 1 + 1) + 1;
    printf("%d", random);
    return (0);
}