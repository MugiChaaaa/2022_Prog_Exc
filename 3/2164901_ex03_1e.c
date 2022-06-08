#include <stdio.h>

int repeat(int a);

int main()
{
    int n;
    printf("INPUT NUMBER:");
    scanf("%d", &n);
    printf("%d\n", repeat(n));
    return 0;
}

int repeat(int a)
{
    int res=0;
    for (int i = 1; i <= a; ++i)
    {
        res += i * i;
    }
    return res;
}