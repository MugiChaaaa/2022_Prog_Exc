#include <stdio.h>

int main()
{
    int a = 3, b = 7;

    printf("a = %d, b = %d\n", a, b);
    printf("Processing...\n");

    a = a - b;
    b = a + b;
    a = b - a;

    printf("a = %d, b = %d\n", a, b);

    return 0;
}