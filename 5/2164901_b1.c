#include <stdio.h>
#define EOD -1 /* EOD(End Of Data)でデータの終わりを示す */
#define size sizeof(x)/sizeof(int) // =配列の大きさ

int maxi(int x[]);

int main(void)
{
    int x[] = { 31, 4, 17, 45, 0, 88, 24, 76, 52, EOD };
    printf("array: {");
    for (int i = 0; i < size - 2; ++i)
        printf("%d, ", x[i]);
    printf("%d}\n", x[size - 2]);   // 配列をそのまま表現するため
    printf("maximum number is %d", maxi(x));    // 配列の中最大値を探す
    return 0;
}

int maxi(int x[])
{
    int i = 0, max = 0;
    while(x[i] != EOD)    // x[i]がEOD出ない限り繰り返す・
    {
        if(max < x[i])  // maxよりx[i]が大きいならmaxにx[i]を代入
            max = x[i];
        i++; //iを1ずつ足す
    }
    return max;
}