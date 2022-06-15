#include <stdio.h>
#include <stdlib.h>

struct student{
    int num;        /* 学籍番号 */
    char name[20];  /* 氏名 */
    int score;      /* 得点 */
};

int data_num(char file[]);
void data_print(char file1[], char file2[]);
void print_name(char file1[], char file2[]);
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
    FILE *fpw = fopen( file2, "wt");
    for (int i = 0; i < line; ++i) //行数だけfor分で繰り返す
        fscanf(fpr, "%d %s %d", &stu[i].num, stu[i].name, &stu[i].score);
    data_quicksort(stu, 0, line-1); //rightがline-1なのは値が入っている最後の構造体はstu[line-1]であるから
    for (int i = 0; i < line; ++i) //行数だけfor分で繰り返す
        fprintf(fpw, "%4d %-20s %3d\n", stu[i].num, stu[i].name, stu[i].score);
    print_name(file1, file2);
    fclose(fpr);
    fclose(fpw);
}

void data_quicksort(struct student f[], int left, int right)
{
    int l = left, r = right;
    struct student std = f[ (left + right) / 2 ]; //stdにf[ (left + right) / 2 ]の値を固定
    while (l <= r) // 作業範囲の順序上の真ん中の値を基準とし、基準の値より大きいなら右へ、小さいなら左へ
    {
        while (f[l].score > std.score || (f[l].score == std.score && f[l].num < std.num))
            l++;//基準の値より小さい値が出るまで or 得点は基準と同じだけど学籍番号が基準より小さいと、左端を右へ
        while (std.score > f[r].score || (std.score == f[r].score && std.num < f[r].num))
            r--;//基準の値より大きい値が出るまで or 得点は基準と同じだけど学籍番号が基準より大きいと、右端を左へ
        if (l <= r)//正の作業範囲か（左端が左に、右端が右にあるのか）
        {
            if (l < r)
            { //交換
                struct student temp;
                temp = f[l];
                f[l] = f[r];
                f[r] = temp;
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

void print_name(char file1[], char file2[]) //ファイル名からディレクトリ名を除く関数
{
    int fin = 0, fins = 0, fout = 0, fouts = 0;
    while(file1[fin] != '\0')
    {
        if(file1[fin] == '\\')
            fins++;
        fin++;
    }
    while(file2[fout] != '\0')
    {
        if(file2[fout] == '\\')
            fouts++;
        fout++;
    } //ファイル名の文字数を数えると同時にその中に入っている'\'の個数も数える
    char resin[fin], resout[fout]; //ファイル名になる文字列
    int a = 0; //仮の変数
    for (int i = 0; i < fin; ++i)
    {
        if(file1[i] == '\\')
            a++; // '\'が出たらaを上げる
        if(a == fins) // aが入力ファイル名の中の'\'の個数と同じだったら
        {
            for (int j = 0; j < fin - i; ++j) // それ以降の文字列を代入
                resin[j] = file1[i+j+1] ;
            break;
        }
    }
    a = 0;
    for (int i = 0; i < fout; ++i) //上と同じ作業（出力ファイル名の場合）
    {
        if(file2[i] == '\\')
            a++;
        if(a == fouts)
        {
            for (int j = 0; j < fout - i; ++j)
                resout[j] = file2[i+j+1] ;
            break;
        }
    }
    printf("Input File : %s\n", resin); //出力
    printf("Output File: %s\n", resout);
}