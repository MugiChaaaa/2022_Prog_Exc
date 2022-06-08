#include <stdio.h>

double inverse(double a[2][2], double b[2][2]); //inverse matrix

int main(void)
{
    double a[2][2], b[2][2];

    for (int i = 0; i < 2; ++i) // scan and print matrix a
    {
        printf("a[%d][1] a[%d][2]:", i+1, i+1);
        scanf("%lf %lf", &a[i][0], &a[i][1]);
    }
    printf("行列\n");
    printf("%.5lf %.5lf\n%.5lf %.5lf\n", a[0][0], a[0][1], a[1][0], a[1][1]);
    printf("の逆行列は");
    if( inverse(a, b) == 0)
        printf("存在しない\n");
    else
        printf("\n%.5lf %.5lf\n%.5lf %.5lf\n", b[0][0], b[0][1], b[1][0], b[1][1]);
    return 0;
}

double inverse(double a[2][2], double b[2][2])
{
    double det = (a[0][0] * a[1][1])-(a[0][1] * a[1][0]); //initialize det
    if (det == 0) //if det is 0, return 0 (there is no inverse matrix)
        return 0;
    else //if not, save b and return 1 (there is an inverse matrix)
    {
        b[0][0] = (1 / det) * a[1][1];
        b[0][1] = (-1 / det) * a[0][1];
        b[1][0] = (-1 / det) * a[1][0];
        b[1][1] = (1 / det) * a[0][0];
        return 1;
    }
}