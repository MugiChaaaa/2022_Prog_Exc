#include <stdio.h>
#include <stdlib.h>

struct student{
    int num;        /* 学籍番号 */
    char name[20];  /* 氏名 */
    int score;      /* 得点 */
    char grade[2];     /* グレード */
};

int data_num(char file[]);
void data_print(char file1[], char file2[]);
void data_score_to_grade (struct student f[], int line);
void data_selection_sort(struct student f[], int line);

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
    FILE *fpw = fopen( file2, "wt");
    for (int i = 0; i < line; ++i) //行数だけfor分で繰り返す
        fscanf(fpr, "%d %s %d", &stu[i].num, stu[i].name, &stu[i].score);
    printf("\n");
    data_score_to_grade(stu, line);
    data_selection_sort(stu, line);
    for (int i = 0; i < line; ++i) //行数だけfor分で繰り返す
        fprintf(fpw, "%d,%s,%c\n", stu[i].num, stu[i].name, stu[i].grade[0]);
    fclose(fpr);
    fclose(fpw);
}

void data_score_to_grade (struct student f[], int line)
{
    for (int i = 0; i < line; ++i)
    {
        if (f[i].score >= 90)
        {
            f[i].grade[0] = 'S';
            f[i].grade[1] = '0'; //ASCIIでは48
        } else if (90 > f[i].score && f[i].score >= 80)
        {
            f[i].grade[0] = 'A';
            f[i].grade[1] = '1'; //ASCIIでは49
        } else if (80 > f[i].score && f[i].score >= 70)
        {
            f[i].grade[0] = 'B';
            f[i].grade[1] = '2'; //ASCIIでは50

        } else if (70 > f[i].score && f[i].score >= 60)
        {
            f[i].grade[0] = 'C';
            f[i].grade[1] = '3'; //ASCIIでは51

        } else if (60 > f[i].score)
        {
            f[i].grade[0] = 'D';
            f[i].grade[1] = '4'; //ASCIIでは52
        }
    }
}

void data_selection_sort(struct student f[], int line)
{
    int min;
    for (int i = 0; i < line-1; ++i) //一番大きい値が入っている順番を覚えておいて、その値を焦点の値と換える
    {
        min = i;
        for (int j = i + 1; j < line; ++j)
            if(f[min].grade[1] > f[j].grade[1])
                min=j;
            else if(f[min].grade[1] == f[j].grade[1] && f[min].num > f[j].num) //成績が同じだったら、学籍番号の低い順に並び替える
                min=j;
        struct student temp; //仮の(交換用の)構造体を宣言
        temp = f[i]; //交換
        f[i] = f[min];
        f[min] = temp;
    }
    printf("Sort Completed\n");
}
/*
 * 単純選択整列というのは、最初から調べて、一番大きい値を一番最初に置く整列法。
 * 最後に比較する値が2つしかないと、1回だけでいいので、全体の比較回数は全体行数-1
 * */



/*もっと非効率的な方法。ただ, 一度ソートされているデータならかなり役に立つかも。
/ひお成績が同じ時は学籍番号昇順に並び替える。
for (int n = 0; n < line; ++n)
{
    if ( f[n].score == f[n+1].score )
    {
        int count = 0;
        while( f[n].score == f[n+count].score )
            count++;
        int min;
        for (int i = 0; i < count-1; ++i) //一番大きい値が入っている順番を覚えておいて、その値を焦点の値と換える
        {
            min = n; // 焦点はnから始まる
            for (int j = i + 1; j < count; ++j)
                if (f[min].num > f[n+j].num) //nからj番目の数と比較
                    min=n+j;
            struct student temp; //仮の(交換用の)構造体を宣言
            temp = f[n]; //交換
            f[n] = f[min];
            f[min] = temp;
        }
    }
}
 */