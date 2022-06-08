#include <stdio.h>

int main(void)
{
    int LQ = 0, LC = 0;
    //LQ: Label Quotation mark(""), LC = Label Comment
    char str[10000] = {0, };
    printf("\n");
    while ( fgets( str, 10000, stdin ) != NULL ) //ファイルが終わるまで1行ごと入力される。
    {
        int n = 0;
        if (LC == 2) //コメントラベルが2(//コメント)の場合
            LC = 0;
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

            if(LQ == 0 && LC == 0) //クォーテーションマークを使っていないし、'/*'がないとき
            {
                if(str[n] == '/' && str[n+1] == '/') //もし'/'が2つ連続、つまり'//'となった場合
                    LC = 2;
                else if(str[n] == '/' && str[n+1] == '*') //'/*'の場合
                {
                    LC = 1; //ラベルを1にする
                    printf("%c", str[n++]); // '*/'をちゃんと表示するため
                }
            }
            else if(LQ == 0 && LC == 1) //クォーテーションマークを使っていないし、'/*'があったとき
            {
                if (str[n] == '*' && str[n + 1] == '/') //コメントが終わったとき
                {
                    LC = 0; //ラベルを0にする
                    printf("%c", str[n++]); // '*/'をちゃんと表示するため
                    printf("%c", str[n++]);
                }
            }
            if(LC >= 1)
                printf("%c", str[n]); // コメントがあった場合
            n++;
        }
        printf("\n");
    }
    return 0;
}