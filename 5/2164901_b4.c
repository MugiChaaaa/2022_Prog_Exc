#include <stdio.h>

int n; //次数を外部変数として宣言

double innerPro(double vec[2][n]);

int main()
{
    printf("ベクトルの次数:");
    scanf("%d", &n);
    double vec[2][n];

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("Vector %d [%d]:", i+1, j+1);
            scanf("%lf", &vec[i][j]);
        }
    }
    printf("ベクトルの内積は %lf\n", innerPro(vec));

    return 0;
}

double innerPro(double vec[2][n]) //inner product of vector
{
    double res = 0;
    for (int i = 0; i < n; ++i) // (a11 * a21) + (a12 * a22) + (a13 * a23) + ...
        res += (vec[0][i] * vec[1][i]);
    return res;
}