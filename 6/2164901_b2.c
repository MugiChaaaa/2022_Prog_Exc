#include <stdio.h>

int str_copy( char *a, char *b );

int main()
{
    char str_a[256], str_b[256];
    printf("1文字列のコピーを行います。\n");
    printf("INPUT:");
    gets(str_a); //get input
    printf("OUTPUT:%s\nLENGTH=%d\n", str_b, str_copy(str_a, str_b)); //print output of str_copy()

    return 0;
}

int str_copy( char *a, char *b )
{
    int i = 0, j = 0;
    while(a[i] == ' ')
        i++;
    while(a[i] != ' ' && a[i] != '\0')  //until the array a[i] is ' ' (space)
    {
        b[j] = a[i]; //put a[] into b[]
        i++; //plus i
        j++; //plus j (length)
    }
    b[j] = '\0'; //when the repeat is over, put '\0' the end of the array
    return j; //return the length of the array
}