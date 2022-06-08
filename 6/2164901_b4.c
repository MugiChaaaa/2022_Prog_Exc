#include <stdio.h>

int count_key( char a[], char b[] );

int main()
{
    char str_a[256], str_b[256];
    printf("INPUT A:");
    gets(str_a); //get input
    printf("INPUT B:");
    gets(str_b); //get input
    printf("文字列%sに含まれている文字列%sの個数は%d個です\n", str_a, str_b, count_key(str_a, str_b));
    return 0;
}

int count_key( char a[], char b[] )
{
    int length = 0, j = 0, count = 0;
    // length: 文字列bの長さ
    // j: j番目の順序
    // count: 該当する文字列が何個あるか
    while(b[length] != '\0') // bの長さを求める
    {
        length++;
    }
    while(a[j] != '\0') //aが終わるまで
    {
        for (int i = 0; i < length; ++i)
        {
            if (a[j+i] != b[i]) //もしaとbが一致しなかったら
            {
                j++;
                break; //jを1つ上げてfor文から出る
            } else if (i == length - 1) //そうでない場合（ずっと最後まで一致した場合）、countを1つ上げ、jにlength分の値を足し上げる
            {
                count++;
                j += length;
            }
        }
    }
    return count;
}