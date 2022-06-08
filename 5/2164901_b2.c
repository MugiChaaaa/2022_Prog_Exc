#include <stdio.h>

void count(int x[], int n);

int main(void)
{
    int x[100], n=0;
    printf("0～9 の任意の整数を入力してください ( 入力終了は Ctrl-D ) :\n");
    while ( scanf( "%d", &x[n] ) != EOF && n <= 99)
    {
        n++;
    }
    count(x, n);

    return 0;
}

void count(int x[], int n)
{
    int h[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int c[10] = {0, };

    for (int j = 0; j < 10; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (x[i] == h[j])
                c[j]++;
        }
        printf("%d の個数は %2d\n", j, c[j]);
    }
}