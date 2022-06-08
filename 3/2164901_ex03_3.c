#include <stdio.h>
#include <math.h>

struct vector{
    double coor[3];
};

double sizeVec(struct vector a);
double innerPro(struct vector a, struct vector b);

int main()
{
    struct vector vec[2];
    for (int i = 0; i < 2; ++i)
    {
        printf("Vector %d：", i+1);
        scanf("%lf %lf %lf", &vec[i].coor[0], &vec[i].coor[1], &vec[i].coor[2]);
    }
    printf("φ[deg]=%.6le", innerPro(vec[0], vec[1]));

    return 0;
}

double innerPro(struct vector a, struct vector b)
{
    double res;
    res = ((a.coor[0] * b.coor[0]) + (a.coor[1] * b.coor[1]) + (a.coor[2] * b.coor[2])) / (sizeVec(a) * sizeVec(b));
    return (180 / M_PI) * acos(res);
}

double sizeVec(struct vector a)
{
    double res;
    res = sqrt(pow(a.coor[0], 2) + pow(a.coor[1], 2) + pow(a.coor[2], 2));
    return res;
}