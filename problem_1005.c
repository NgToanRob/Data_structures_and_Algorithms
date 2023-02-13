#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    int weights[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    int result = 100000 * n;

    int combinations = (int)1 << n;
    // All combination
    for (int comb = 0; comb < combinations; comb++)
    {
        int first_pile = 0, second_pile = 0;
        // All bit in a combination
        for (int bit_i = 0; bit_i < n; bit_i++)
        {
            int is_ith_bit_1 = (comb >> bit_i) & 1;
            if (is_ith_bit_1)
            {
                first_pile += weights[bit_i];
            }
            else
            {
                second_pile += weights[bit_i];
            }
        }
        int different = abs(first_pile - second_pile);
        if (different < result)
        {
            result = different;
        }
    }

    printf("%d\n", result);

    return 0;
}
