#include <bits/stdc++.h>

using namespace std;

struct Point
{
    long long num;
    long long x;
    long long y;
};

    Point firstPoint;

    bool compare(Point p1, Point p2)
    {
        p1.x -= firstPoint.x;
        p1.y -= firstPoint.y;
        p2.x -= firstPoint.x;
        p2.y -= firstPoint.y;
        // 2D cross product between two vectors
        return (p1.x * p2.y - p1.y * p2.x) > 0;
    }

int main()
{
    #include <iostream>
using namespace std;

int main() {
int n;
cin >> n;
if(!(n >= 4 && n<=10000)) return -1;

int points[n][2];
for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    points[i][0] = x;
    points[i][1] = y;
}

for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
        int left = 0;
        int right = 0;
        for (int k = 0; k < n; k++) {
            if (k == i || k == j) {
                continue;
            }
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];
            int x3 = points[k][0];
            int y3 = points[k][1];
            // calculate cross product to determine which side of the line
            // point k is on
            int cross_product = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
            if (cross_product > 0) {
                left++;
            }
            else if (cross_product < 0) {
                right++;
            }
        }
        if (left == right) {
            cout << i+1 << " " << j+1 << endl;
            return 0;
        }
    }
}

return 0;
}
