#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct point
{
    // point: (x, y)
    int64_t x, y;
};

struct line
{
    // line: ax + by + c = 0
    int64_t a, b, c;
};

struct line get_line(struct point point1, struct point point2) {
    struct line line;
    line.a = point1.y - point2.y;
    line.b = point2.x - point1.x;
    line.c = point1.x * point2.y - point2.x * point1.y;
    return line;
}

int64_t dot_product_between_point_and_line(struct point point, struct line line) {
    return line.a * point.x + line.b * point.y + line.c;
}

int are_equal_sets(struct point *points, int n, struct line line) {
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++) {
        int64_t dot_product = dot_product_between_point_and_line(points[i], line);
        if (dot_product > 0) {
            left++;
        } else if (dot_product < 0) {
            right++;
        }
    }
    return left == right;
}

int main()
{

    int n;
    scanf("%d", &n);

    struct point *points;

    points = (struct point *)malloc(sizeof(struct point) * n);

    for (size_t i = 0; i < n; i++)
    {
        scanf("%" SCNd64 " %" SCNd64, &points[i].x, &points[i].y);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            struct line line = get_line(points[i], points[j]);
            if (are_equal_sets(points, n, line))
            {
                printf("%d %d\n", i + 1, j + 1);
                return 0;
            }
        }
    }

    return 0;
}