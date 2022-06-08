#include <stdio.h>
#include <math.h>

int main()
{
    double a = 1, x, res = 1;
    int n = 1;
    printf("INPUT NUMBER:");
    scanf("%lf", &x);
    printf("%2d %.8le\n", n, res);
    do
    {
        a *= (fabs(x) / n);
        res += a;
        n++;
        printf("%2d %.8le\n", n, res);
    }
    while(a >= 0.0000001);
    printf("ans: %.8le\n", res);

    return 0;
}