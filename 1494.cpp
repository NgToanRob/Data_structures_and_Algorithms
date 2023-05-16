#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    bool cheating = false;
    int m = 0;
    stack<int> s;

    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        // Push from 1 to x-th to stack
        while (m < x)
            s.push(++m);
        // Check the last same number
        if (s.top() != x)
            cheating = true;
        // Pop from stack to check next ball
        s.pop();
    }

    if (cheating)
        cout << "Cheater\n";
    else
        cout << "Not a proof\n";
}