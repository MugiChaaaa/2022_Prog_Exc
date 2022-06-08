#include <stdio.h>

int str_copy( char *a, char *b );

int main()
{
    int l = 1;
    char str_a[256], str_b[256];
    printf("1文字列のコピーを行います。\n");
    printf("INPUT:");
    gets(str_a); //get input
    l = str_copy(str_a, str_b);
    printf("OUTPUT:\n");
    while(l != 0)
    {
        printf("%s, LENGTH=%d\n", str_b, l); //print output of str_copy()
        l = str_copy(NULL, str_b);
    }
    return 0;
}

int str_copy( char *a, char *b )
{
    static char *temp;
    int j = 0;
    if (a != NULL) //NULL引数を受けたら
        temp = a;
    while(*temp == ' ')
        temp++;
    while(*temp != ' ' && *temp != '\0')  //until the array a(= temp) is ' ' (space)
    {
        *b = *temp; //put a[](= temp) into b[]
        j++; //plus j (length)
        b++;
        temp++;
    }
    *b = '\0'; //when the repeat is over, put '\0' into the end of the array
    return j; //return the length of the array
}