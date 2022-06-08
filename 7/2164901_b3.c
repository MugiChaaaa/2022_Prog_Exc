#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fpr = fopen(argv[1], "r");
    FILE *fpw = fopen(argv[2], "w");
    char head[100];
    int max_lumi; //最大輝度
    if( fpr == NULL )
    {
        printf("ファイル %sを開けませんでした。\n", argv[1]);
        return -1;
    }
    //フェイルセーフ

    for (int i = 0; i < 2; ++i)
    {
        fgets( head, 100, fpr );
        fprintf(fpw, "%s", head);
    }
    fscanf(fpr, "%d", &max_lumi);
    fprintf(fpw, "%d\n", max_lumi);
    // header data read&write

    int data;
    while(fscanf(fpr, "%d", &data) != EOF)
    {
        if(data <= max_lumi/2) // dataが最大輝度の半分(127)以下の場合
        {
            fprintf(fpw, "0\n"); //0を出力
        }
        else if(data > max_lumi/2) // dataが最大輝度の半分(127)超過の場合
        {
            fprintf(fpw, "%d\n", max_lumi); //最大輝度(255)を出力
        }
    }
    // body data read&write

    fclose(fpr);
    fclose(fpw);
    printf("Done Successfully\n");

    return 0;
}