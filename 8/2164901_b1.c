#include <stdio.h>
#include <stdlib.h>

struct student{
    int num;        /* 学籍番号 */
    char name[20];  /* 氏名 */
    int score;      /* 得点 */
};

int data_num(char file[]);
void data_print(char file[]);

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if( fp == NULL )
    {
        printf("ファイル %sを開けませんでした。\n", argv[1]);
        exit(-1);
    }//fail safe
    fclose(fp);
    data_print(argv[1]);
    printf("\n");
    return 0;
}

int data_num(char file[]) //行数を調べる関数。戻り値として行数を返す。
{
    int num = 0;
    char temp[100000];
    FILE *fp = fopen( file, "rt"); //テキストファイルを読む
    while(fgets(temp, 100000, fp) != NULL) //行を一つずつ読みながら行数ヲ調べる。
        num++;
    fclose(fp);
    return num;
}

void data_print(char file[]) // ファイルとその行数を調べる。戻り値がないためvoid型
{
    int line = data_num(file); //行数を調べる(while分とfscanf関数との不安定性を避けるため)
    struct student stu[line]; //行数分の構造体を宣言
    FILE *fpr = fopen( file, "rt"); //テキストファイルを読む
    for (int i = 0; i < line; ++i) //行数だけfor分で繰り返す
    {
        fscanf(fpr, "%d %s %d", &stu[i].num, stu[i].name, &stu[i].score);
        printf("%4d %-20s %3d\n", stu[i].num, stu[i].name, stu[i].score);
    }
    fclose(fpr);
}