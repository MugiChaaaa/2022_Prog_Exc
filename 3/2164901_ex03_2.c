#include <stdio.h>

int jw(int n);

int main()
{
    int n;
    while (1)
    {
        printf("INPUT NUMBER:");
        scanf("%d", &n);
        if (n >= 0)
            printf("%d\n", jw(n));
        else
            break;
    }
    return 0;
}

int jw(int n)
{
    int res = 0;
    static int cres, cn;
    if (cn == n)
    {
        printf("Return cache data.\n");
        return cres;
    }
    cn = n;
    for (int i = 1; i <= n; ++i)
    {
        res += i * i;
    }
    cres = res;
    return res;
}