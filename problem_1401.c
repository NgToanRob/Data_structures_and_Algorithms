#include <stdio.h>
#include <math.h>

size_t n;
int map[512][512];
int k = 3; // the number to count the squares

void reset_map(int map[][512], size_t n)
{
    int size = pow(2, n);
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            map[i][j] = 0;
        }
    }
}

void print_map(int map[][512], size_t n)
{
    int size = pow(2, n);
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            printf("%3d ", map[i][j]);
        }
        printf("\n");
    }
}

/**
 * It fills a 2x2 square with numbers, except for the hole
 *
 * @param x x coordinate of the square
 * @param y the y coordinate of the top left corner of the square
 * @param hx the x coordinate of the hole
 * @param hy the y coordinate of the hole
 */
void fill_square_size_2(int x, int y, int hx, int hy)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int is_the_hole = (x + i == hx && y + j == hy);
            if (!is_the_hole)
            {
                map[x + i][y + j] = k++ / 3;
            }
        }
    }
}

void solve(int size, int x, int y, int hx, int hy)
{
    // The simplest case
    if (size == 2)
    {
        fill_square_size_2(x, y, hx, hy);
        return;
    }

    // find the quadrant block that contains the hole
    int hi, hj;
    int is_left = hx < x + size / 2;
    int is_top = hy < y + size / 2;
    hi = !is_left;
    hj = !is_top;

    // fill the middle triangle with numbers, expect for the hole
    int triangle_x = x + size / 2 - 1, triangle_y = y + size / 2 - 1;
    fill_square_size_2(triangle_x, triangle_y, triangle_x + hi, triangle_y + hj);

    // Recursively filling the rest blocks
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int is_contain_the_hole = i == hi && j == hj;
            if (!is_contain_the_hole)
            {
                int hole_x = x + size / 2 - 1 + i;
                int hole_y = y + size / 2 - 1 + j;
                solve(size / 2, x + i * size / 2, y + j * size / 2, hole_x, hole_y);
            }
            else
            {
                solve(size / 2, x + i * size / 2, y + j * size / 2, hx, hy);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    scanf("%zu", &n);
    int size = pow(2, n);

    int hx, hy; // the coordinates of the hole
    scanf("%d %d", &hx, &hy);
    hx--;
    hy--;

    reset_map(map, n);

    solve(size, 0, 0, hx, hy);

    print_map(map, n);
    return 0;
}
