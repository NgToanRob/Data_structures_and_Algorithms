#include <stdio.h>

// Hàm inverse BWT trong C
char *inverse_BWT(int n, char *str)
{
    // tìm kí tự trong chuỗi
    char ch[n + 1];
    for (int i = 0; i < n; i++)
        ch[i] = str[i];
    ch[n] = '\0';

    // tạo mảng phụ
    int p[n];
    for (int i = 0; i < n; i++)
        p[i] = i;

    // sắp xếp mảng phụ
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ch[i] > ch[j])
            {
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // tạo chuỗi kết quả
    char *result = (char *)malloc((n + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        index = p[index];
        result[i] = ch[index];
    }
    result[n] = '\0';

    return result;
}

int main(int argc, char const *argv[])
{

    int n = 5;
    char *str = "BANAN";

    char *result = inverse_BWT(n, str);
    printf("Kết quả: %s\n", result);
    /* code */
    return 0;
}
