#include <stdio.h>
#include <stdlib.h>

struct student{
    int num;        /* 学籍番号 */
    char name[20];  /* 氏名 */
    int score;      /* 得点 */
};

int data_num(char file[]);
void data_print(char file[]);
void data_selection_sort(struct student f[], int line);

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
    printf("\n");
    data_selection_sort(stu, line);
    for (int i = 0; i < line; ++i) //行数だけfor分で繰り返す
        printf("%4d %-20s %3d\n", stu[i].num, stu[i].name, stu[i].score);
    fclose(fpr);
}

void data_selection_sort(struct student f[], int line)
{
    int max;
    for (int i = 0; i < line-1; ++i) //一番大きい値が入っている順番を覚えておいて、その値を焦点の値と換える
    {
        max = i;
        for (int j = i + 1; j < line; ++j)
            if(f[max].score < f[j].score)
                max=j;
        struct student temp; //仮の(交換用の)構造体を宣言
        temp = f[i]; //交換
        f[i] = f[max];
        f[max] = temp;
    }
}
/*
 * 単純選択整列というのは、最初から調べて、一番大きい値を一番最初に置く整列法。
 * 最後に比較する値が2つしかないと、1回だけでいいので、全体の比較回数は全体行数-1
 * */