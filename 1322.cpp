#include <iostream>
#include <cstring>
using namespace std;

char word[100001];
int next_position[100001];

int get_index(char character)
{
    if (character >= 'A' && character <= 'Z')
        return character - 'A';
    if (character == '_')
        return 26;
    return character - 'a' + 27;
}

int main()
{
    int number, length;
    int contains[54];
    
    cin >> number >> word;
    memset(contains, 0, sizeof(contains));
    length = strlen(word);
    number--;
    
    for (int i = 0; i < length; i++)
        contains[get_index(word[i]) + 1]++;

    
    // Counting the number of characters before the current character.
    /*
    Số lượng liên tiếp xuất hiện của một phần tử i trong chuỗi đã được mã hóa 
    bằng BWT được tính bằng cách đếm số lần xuất hiện của ký tự tương ứng trong 
    chuỗi gốc trước khi mã hóa. Khi đó, vị trí đầu tiên của ký tự i trong chuỗi 
    gốc là tổng số lần xuất hiện của các ký tự trước nó (tính từ A-Z, _, a-z) 
    cộng với số lần xuất hiện liên tiếp của ký tự i trong chuỗi đã được mã hóa.
    */
    for (int i = 1; i < 53; i++)
        contains[i] += contains[i - 1];
            
    for (int i = 0; i < length; i++) {
        int index = get_index(word[i]);
        /*set next_position in the index which is the number of total characters 
        before the current character. And then add 1 to the index because of 
        the repetition of the current character.
        */ 
        int a = contains[index] ++;
        next_position[a] = i;
    }

    /*
    0   _   a   4
    1   _   n   0
    2   _   n   5
    3   _   b   6
    4   b   A   3
    5   _   a   1
    6   _   a   2
    */
    for (int i = 0; i < length; i++) {
        cout << word[number = next_position[number]];
    }
    cout << endl;
    
    return 0;
}