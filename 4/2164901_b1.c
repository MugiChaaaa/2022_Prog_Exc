#include <stdio.h>

struct vector{
    double coor[6]; //計算用変数をもう一組設ける。(3 + 3)
};

double outerPro(struct vector a, struct vector b, int c); //それぞれのベクトルと何番目かを引数とする

int main()
{
    struct vector vec[2];
    for (int i = 0; i < 2; ++i)
    {
        printf("Vector %d：", i+1);
        scanf("%lf %lf %lf", &vec[i].coor[0], &vec[i].coor[1], &vec[i].coor[2]);
        for (int j = 0; j < 3; ++j)
        {
            vec[i].coor[j+3] = vec[i].coor[j]; //計算用変数に代入
        }
    }
    printf("Outer Product: (%lf, %lf, %lf)", outerPro(vec[0], vec[1], 0), outerPro(vec[0], vec[1], 1), outerPro(vec[0], vec[1], 2));

    return 0;
}

double outerPro(struct vector a, struct vector b, int c)
{
    double res;
    res = (a.coor[c+1] * b.coor[c+2]) - (a.coor[c+2] * b.coor[c+1]); //ベクトルの外積の定義
    return res;
}