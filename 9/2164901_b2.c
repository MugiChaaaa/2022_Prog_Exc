#include <stdio.h>
#include <stdlib.h>

struct student{
    int num;        /* 学籍番号 */
    char name[20];  /* 氏名 */
    int score;      /* 得点 */
};

int count_comp = 0, count_ex = 0; //比較回数、入れ替え回数

int data_num(char file[]);
void data_print(char file1[], char file2[]);
void data_quicksort(struct student f[], int left, int right);

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if( fp == NULL )
    {
        printf("ファイル %sを開けませんでした。\n", argv[1]);
        exit(-1);
    }//fail safe
    if( argc < 3 )
    {
        printf("出力するファイルの名前を入力してください。\n");
        exit(-1);
    }
    fclose(fp);
    data_print(argv[1], argv[2]);
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

void data_print(char file1[], char file2[]) // ファイルとその行数を調べる。戻り値がないためvoid型
{
    int line = data_num(file1); //行数を調べる(while分とfscanf関数との不安定性を避けるため)
    struct student stu[line]; //行数分の構造体を宣言
    FILE *fpr = fopen( file1, "rt"); //テキストファイルを読む
    FILE *fpw = fopen( file2, "wt"); //テキストファイルを読む
    for (int i = 0; i < line; ++i) //行数だけfor分で繰り返す
        fscanf(fpr, "%d %s %d", &stu[i].num, stu[i].name, &stu[i].score);
    data_quicksort(stu, 0, line-1); //rightがline-1なのは値が入っている最後の構造体はstu[line-1]であるから
    printf("Comp: %d, Ex: %d\n", count_comp, count_ex); //比較・交換回数出力
    for (int i = 0; i < line; ++i) //行数だけfor分で繰り返す
        fprintf(fpw, "%4d %-20s %3d\n", stu[i].num, stu[i].name, stu[i].score);
    fclose(fpr);
    fclose(fpw);
}

void data_quicksort(struct student f[], int left, int right)
{
    int l = left, r = right;
    struct student std = f[ (left + right) / 2 ]; //stdにf[ (left + right) / 2 ]の値を固定
    while (l <= r) // 作業範囲の順序上の真ん中の値を基準とし、基準の値より大きいなら右へ、小さいなら左へ
    {
        while (f[l].score > std.score) //基準の値より小さい値が出るまで左端を右へ
        {
            l++;
            count_comp++;
        }
        count_comp++; //while文から出たら
        while (std.score > f[r].score) //基準の値より大きい値が出るまで右端を左へ
        {
            r--;
            count_comp++;
        }
        count_comp++; //while文から出たら
        if (l <= r)//正の作業範囲か（左端が左に、右端が右にあるのか）
        {
            if (l < r)
            { //交換
                struct student temp;
                temp = f[l];
                f[l] = f[r];
                f[r] = temp;
                count_ex++;
            }//左端と右端をそれぞれ1ずつ中央へ
            l++;
            r--;
        }
    }
    if ( left < r )
        data_quicksort(f, left, r); //再帰呼び出し
    if ( l < right )
        data_quicksort(f, l, right);
}