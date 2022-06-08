#include <stdio.h>

void keta(unsigned int a);

int main()
{
    unsigned int num; //4,294,967,295までの数字を入力される

    printf("Enter the number:");
    scanf("%d", &num);
    keta(num);
    printf("\n");

    return 0;
}

void keta(unsigned int a) //戻り値のない関数
{
    int n[5], j;
    if (a < 1000) //a<1000の場合そのまま出力
    {
        printf("%d", a);
    }
    else
    {
        for (int i = 0; i < 5; ++i)
        {
            n[i] = a % 1000;
            if (a / 1000 < 1) //4桁未満だったらjにiを代入。後で第j項から第0項まで順に出力する
            {
                j = i;
                break;
            }
            a /= 1000; //numを1000で割る
        }
        printf("%d", n[j]); //一番前の数字はそのまま出力
        for (int i = j-1; i >= 0; i--)
            printf(",%03d", (n[i])); //残りの項は3桁ごとに出力
    }
}
