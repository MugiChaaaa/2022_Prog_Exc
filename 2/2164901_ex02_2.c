#include <stdio.h>

int main()
{
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            if (i * j == 24)
                printf("解：%d * %d\n", i, j);
            else if (i * j > 24)
                break;
        }
    }
    return 0;
}