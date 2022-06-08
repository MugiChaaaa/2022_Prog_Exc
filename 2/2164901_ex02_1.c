#include <stdio.h>

int main()
{
    int n, res = 1;

    do
    {
        printf("INPUT NUMBER:");
        scanf("%d", &n);
        if(n < 0)
        {
            printf("負の数が入力されましたので、計算を実行せずに終了します。\n");
            return 0;
        }
        else if(n > 12)
            printf("12以下の正数を入力してください。\n");
    }
    while(n < 0 || 12 < n);
    if (n > 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            res = res * i;
        }
        printf("result: %d\n", res);
    }
    else if (n == 0)
        printf("1\n");

    return 0;
}