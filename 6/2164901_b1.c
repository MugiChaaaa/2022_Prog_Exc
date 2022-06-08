#include <stdio.h>

int str_copy( char *a, char *b );

int main()
{
    char str_a[256], str_b[256];
    printf("文字列のコピーを行います。\n");
    printf("INPUT:");
    gets(str_a); //get input
    printf("OUTPUT:%s\nLENGTH=%d\n", str_b, str_copy(str_a, str_b)); //print output of str_copy()

    return 0;
}

int str_copy( char *a, char *b )
{
    int leng = 0, i = 0;
    while(a[i] != '\0') //while the array is over
    {
        b[i] = a[i]; //put a[] into b[]
        leng++; //plus leng (length)
        i++; //plus i
    }
    b[i] = '\0'; //when the repeat is over, put '\0' the end of the array
    return leng; //return the length of the array
}