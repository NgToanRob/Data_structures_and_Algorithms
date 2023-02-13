#include <stdio.h>
#include <math.h>

int main()
{
    int T; // Số lượng bộ test
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        int core_fighters = n/k;
        int left_fighters = n%k;
        int fights = power(core_fighters, k-left_fighters) + power(core_fighters+1, left_fighters);
        printf("%d\n", fights);
    }
    return 0;
}
