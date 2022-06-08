#include <stdio.h>

int main(void)
{
    int LSA = 0, LQ = 0;
    /*
    LSA: Label Slash & Asterisk(/*)
    LQ: Label Quotation mark("")
    */
    char str[10000] = {0, };
    printf("\n");
    while ( fgets( str, 10000, stdin ) != NULL ) //ファイルが終わるまで1行ごと入力される。
    {
        int n = 0, k = 0;
        char str_e[10000] = {0, }; //コピーする文字列の初期化
        while (str[n] != '\n') //リダイレクトにより得られた文字列の行が終わるまで
        {
            if(LQ == 0 && str[n] == '"') //クォーテーションマークがある場合(始まり)
            {
                LQ = 1; //クォーテーションマークラベルを1にする
            }
            else if(LQ == 1 && str[n] == '"') //クォーテーションマークがある場合(終わり)
            {
                LQ = 0; //クォーテーションマークラベルを0にする
            }

            if(LQ == 0 && LSA == 0) //クォーテーションマークを使っていないし、'/*'がないとき
            {
                if(str[n] == '/' && str[n+1] == '/') //もし'/'が2つ連続、つまり'//'となった場合
                {
                    break; //str_eに strを入れる作業をやめる。
                }
                else if(str[n] == '/' && str[n+1] == '*') //'/*'の場合
                {
                    LSA = 1; //スラッシュ・アステリスクラベルを1にする
                    n++;
                }
                else //コメントが何もないとき
                {
                    str_e[k] = str[n]; //str_eにstrを入れる。
                    k++;
                }
                n++;
            }
            else if(LQ == 0 && LSA == 1) //クォーテーションマークを使っていないし、'/*'があったとき
            {
                if (str[n] == '*' && str[n + 1] == '/') //コメントが終わったとき
                {
                    LSA = 0; //スラッシュ・アステリスクラベルを0にする
                    n++;
                }
                n++;
            }
            else if(LQ == 1) //クォーテーションマークを使っているとき
            {
                str_e[k] = str[n]; //str_eにstrを入れる。
                k++;
                n++;
            }
        }
        if(str_e[0] != '\0') //何もない行は除いて
            printf("%s\n", str_e); //strをコピーしたstr_eを出力。
    }
    return 0;
}