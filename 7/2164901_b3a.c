#include <stdio.h>

int kihonnkadai3(int argc, char *argv[])
{
    FILE *fpr = fopen(argv[1], "r");
    FILE *fpw = fopen(argv[2], "w");
    char head[100];
    int /* 最大輝度 */ max_lumi/* 行の最後には必ずセミコロン;を忘れずに */;
    /*/*
     * ★豆知識★
     * 輝度は英語でluminanceである
     * */
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
    printf("/*これはコメントではありません。テスト用の文です*/\n");
    return 0;
}
//コメント
/* here's
 * the
 * comment */