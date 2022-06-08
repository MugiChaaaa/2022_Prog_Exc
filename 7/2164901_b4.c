#include <stdio.h>

int main(void)
{
    char str[10000];
    printf("\n");
    while ( gets( str ) != NULL ) //ファイルが終わるまで1行ごと入力される。
    {
        int n=0;
        char str_e[10000] = {0, }; //コピーする文字列の初期化
        while (str[n] != '\n') //リダイレクトにより得られた文字列の行が終わるまで
        {
            if(str[n] == '/' && str[n+1] == '/') //もし'/'が2つ連続、つまり'//'となった場合
            {
                break; //str_eに strを入れる作業をやめる。
            }
            str_e[n] = str[n]; //str_eにstrを入れる。
            n++;
        }
        printf("%s\n", str_e); //strをコピーしたstr_eを出力。
    }
    return 0;
}