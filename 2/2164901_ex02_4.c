#include <stdio.h>
#include <math.h>

int main()
{
    int sex, wgt;
    double hgt, stw, obs;
    printf("Height [m]:");
    scanf("%lf", &hgt);
    printf("Weight [kg]:");
    scanf("%d", &wgt);
    printf("Sex [M=1, F=2, None=Others]:");
    scanf("%d", &sex);

    switch (sex)
    {
        case 1:
            stw = pow(hgt, 2) * 22;
            break;
        case 2:
            stw = pow(hgt, 2) * 21;
            break;
        default:
            stw = pow(hgt, 2) * 21.5;
            break;
    }
    obs = (wgt / stw - 1) * 100;
    printf("Standard Weight [kg]: %f\n", stw);
    printf("Obesity [%%]: %f\n", obs);

    if (obs >= 10)
        printf("太り過ぎ\n");
    else if (obs <= -10)
        printf("痩せ過ぎ\n");
    else
        printf("標準\n");

    return 0;
}