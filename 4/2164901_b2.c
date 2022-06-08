#include <stdio.h>

int G(int a, int b);

int main()
{
    int a = 0, b = 0, n1, n2;
    while (a <= 0 || b <= 0)
    {
        printf("Enter numbers:");
        scanf("%d %d", &a, &b);
        if (a <= 0 || b <= 0)
            printf("Please Enter natural number only.\n"); //自然数だけを入力
    }
    if (a >= b)             // n1=大きい数, n2=小さい数
        n1 = a, n2 = b;
    else
        n1 = b, n2 = a;
    printf("GCD of %d and %d is %d\n", a, b, G(n1, n2));
    return 0;
}

int G(int a, int b)
{
    printf("%d %d\n", a, b); //正しく計算しているか確かめるため
    if (b == 1) //b(小さい数)が1である場合
        return b;
    else if (b == 0) //前回で割り切れた場合
        return a;
    else
    {
        if (a == b) // a = bの場合
            return a;
        else // その他のすべての場合
            return G(b, a % b);
    }
}