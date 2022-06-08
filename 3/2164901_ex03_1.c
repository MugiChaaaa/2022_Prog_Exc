#include <stdio.h>

int main()
{
    int n, res = 0;
    printf("INPUT NUMBER:");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        res += i * i;
    }

    printf("%d\n", res);

    return 0;
}