#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");
    char a, b;

    if( fp1 == NULL )
    {
        printf("ファイル %sを開けませんでした。\n", argv[1]);
        return -1;
    }
    if( fp2 == NULL )
    {
        printf("ファイル %sを開けませんでした。\n", argv[2]);
        return -1;
    }
    //フェイルセーフ

    printf("2つのファイルは");
    do
    {
        a = fgetc( fp1 );
        b = fgetc( fp2 );
        if (a != b) //2つのファイルの内容（テキスト）が異なった場合
        {
            printf("異なります。\n");
            break;
        }
    }while ( a != EOF || b != EOF);
    if (a == b)
        printf("同じです。\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}