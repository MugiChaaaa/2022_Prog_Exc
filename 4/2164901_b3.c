#include <stdio.h>

void keta(int a);

int main()
{
    int num;

    printf("Enter the number:");
    scanf("%d", &num);
    keta(num);
    printf("\n");

    return 0;
}

void keta(int a) //戻り値のない関数
{
    if (a / 1000 >= 1) //4桁以上だったら ",000"の形で出力
    {
        keta(a / 1000);
        printf(",%03d", (a%1000));
    }
    else //3桁以下だったら そのまま出力
        printf("%d", a);
}