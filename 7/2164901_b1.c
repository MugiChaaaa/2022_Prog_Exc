#include <stdio.h>

int main(void)
{
    int n=0;
    char str[10000];
    char *xp = str;
    printf("( 入力終了は Ctrl-D ) :\n");
    while ( gets( str ) != NULL )
    {
        printf("%05d %s\n", ++n, str);
    }

    return 0;
}