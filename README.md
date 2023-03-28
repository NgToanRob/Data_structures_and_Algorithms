<p align="center" style ="font-size: 24px">Министерство образования и науки РФ
</p>
<p align="center" style ="font-size: 20px">Федеральное государственное автономное <br>
образовательное учреждение высшего образования <br>
«Национальный исследовательский университет ИТМО»
</p>

<p align="center" style ="font-size: 24px"><em>Факультет систем управления и робототехники </em></p>

<p align="center">
  <img src="doc/Picture1.png" />
</p>

<p align="center" style ="font-size: 24px"><strong>Лабораторные работы</br>
По дисциплине : «Алгоритмы и структуры данных»</br>
</strong>
</p>
<p align="left">Преподаватель: <strong>Тропченко Андрей Александрович</strong></br>
Выполнил: <strong>Нгуен Тоан</strong></br>
Группа: <strong>R32372</strong>
</p>

# Алгоритмы и структуры данных

## Table of Contents
1. [Problem 2025: Line Fighting](#1-problem-2025-line-fightingProblem)
2. [Problem 1005: Stone Piles](#2-problem-1005-stone-piles)
3. [Problem 1155: Troubleduons](#3-problem-1155-troubleduons)
4. [Problem 1296: Hyperjump](#4-problem-1296-hyperjump)
5. [Problem 1401: Gamer](#5-problem-1401-gamers)
6. [Problem 1207: Median on the plane](#6-problem-1207-median-on-the-plane)
7. [Problem 1322: Spy](#7-problem-1322-spy)
8. [Problem 1604: Country of Fools](#9-problem-1604-country-of-fools)
9. [Problem 1726: Visits](#10-problem-1726-visits)


## 1. Problem 2025: Line Fighting

```python
T = int(input().strip())
result = []
for _ in range(T):
    n, k = map(int, input().strip().split())
    e_t = n % k # number of teams with one extra fighter
    s_t = k - e_t # number of teams with the standard number of fighters
    a = n // k # standard number of fighters in each team


    # Multiply by maximum number of fights between each combination of teams:
    # First part: Choose two teams in teams with one extra fighter, 
    part_1 = e_t * (e_t - 1) // 2 * (a + 1)**2
    # Second part: Choose tow teams in teams with the standard number of fighters
    part_2 = s_t * (s_t - 1) // 2 * a**2 
    # Third part: Choose one in teams with one extra fighter and one teams with the standard number of fighters
    part_3 = s_t * e_t * (a + 1) * a
    result.append(part_1 + part_2 +part_3)
for e in result:
    print(e)
```

```
# Input
3
6 3
5 5
4 2
# Output
12
10
4
```
The code calculates the maximum number of fights between teams in a line fighting competition. The code takes in an integer input, which represents the number of test cases.

A list `result` is created to store the results of each test case. A for loop is used to iterate through the test cases and calculate the maximum number of fights for each.

In each iteration, two integers `n` and `k` are taken as input, representing the total number of fighters and the number of teams respectively. The code then calculates the standard number of fighters in each team by dividing `n` by `k` and assigns the result to a variable `a`.

The code also calculates the number of teams with one extra fighter by taking the remainder of n divided by k and assigns the result to a variable `e_t`. The number of teams with the standard number of fighters is calculated by subtracting `e_t` from k and assigning the result to a variable `s_t`.

![\Large result = {\mathrm{C}_{et}^2}{\mathrm{C}_{a+1}^1}{\mathrm{C}_{a+1}^1}  + {\mathrm{C}_{st}^2}{\mathrm{C}_{a}^1}{\mathrm{C}_{a}^1} + {\mathrm{C}_{et}^1}{\mathrm{C}_{st}^1}{\mathrm{C}_{a+1}^1}{\mathrm{C}_{a}^1} ](https://latex.codecogs.com/svg.image?result%20=%20{\mathrm{C}_{et}^2}{\mathrm{C}_{a+1}^1}{\mathrm{C}_{a+1}^1}%20%20+%20{\mathrm{C}_{st}^2}{\mathrm{C}_{a}^1}{\mathrm{C}_{a}^1}%20+%20{\mathrm{C}_{et}^1}{\mathrm{C}_{st}^1}{\mathrm{C}_{a+1}^1}{\mathrm{C}_{a}^1})

The next section of the code calculates the maximum number of fights between each combination of teams. This is done by computing three parts: `part_1`, `part_2`, and `part_3`.

`part_1` represents the maximum number of fights between teams with one extra fighter. `part_2` represents the maximum number of fights between teams with the standard number of fighters. `part_3` represents the maximum number of fights between teams with one extra fighter and teams with the standard number of fighters.

The sum of these three parts is then appended to the `result` list, which represents the maximum number of fights for the current test case.

Finally, the code prints the `result` list, where each element in the list represents the maximum number of fights between teams for each test case.

## 2. Problem 1005: Stone Piles
```C
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
```
```
# Input
5
5 8 13 27 14
# Output
3
```
This is a C program that solves the problem of finding the minimum difference between the sum of two piles of stones given `n` stones and their weights `weights`.

The program starts by reading `n` from the input using the `scanf` function.

Next, it declares an array `weights` of size `n` and reads the weights of the stones into it using a for loop and the `scanf` function.

The variable `result` is initialized to `100000 * n`, which is the maximum possible difference between the sum of the two piles of stones. This is used to keep track of the minimum difference found so far.

The program then calculates the number of combinations `combinations` by shifting `1` to the left by `n` bits using the `<<` operator.

In the next step, the program uses a for loop to iterate over all `combinations`. For each combination, it declares two variables `first_pile` and `second_pile` to keep track of the sum of stones in each pile.

Another for loop is used to iterate over each bit in the current combination `comb`. The `is_ith_bit_1` variable is used to determine whether the `bit_i`-th bit in comb is set to `1` or `0`. If it is set to `1`, the weight of the corresponding stone is added to the `first_pile`. If it is set to `0`, the weight of the corresponding stone is added to the `second_pile`.

The absolute difference between the sum of stones in the two piles is then calculated and compared to `result`. If it is smaller, `result` is updated to the new difference.

Finally, the program prints the **minimum difference** found


## 3. Problem 1155: Troubleduons
```cpp
#include <iostream>
#include<math.h>
#include <vector>

using namespace std;

vector<char> result;

struct Vercites{
    char ch;
    int w;
};

void record(Vercites &x, Vercites &y, char sign){
    result.push_back(x.ch);
    result.push_back(y.ch);
    result.push_back(sign);
    result.push_back('\n');
}


void substraction_V(Vercites &x, Vercites &y){
    // Subtract until either is zero
    while(x.w && y.w){
        record(x,y,'-');
        x.w -= 1;
        y.w -= 1;
    }
}

// Transfer weight through a third vertex
void move_W(Vercites &a, Vercites &b, Vercites &c){
    while(c.w > 0){
        record(b,a,'+');
        record(c,b,'-');
        a.w = a.w + 1;
        c.w = c.w - 1;
    }
}

bool isAdjacent(int a, int b){
    if(a > b) swap(a, b);
    if (b - a == 4) return true;
    if (a < 4 && b >= 4) return false;
    if (b - a == 3) return true;
    if(a + 1 == b) return true;
    return false;
}

int main(){
    Vercites a = {'A'}, b = {'B'}, c = {'C'}, d = {'D'}, e = {'E'}, f = {'F'}, g = {'G'}, h = {'H'};
    // Enter the troubleduons of the Vercites
    cin>>a.w>>b.w>>c.w>>d.w>>e.w>>f.w>>g.w>>h.w;

    /*
    Tow sets of bipartite graph:
     - set 1: A C F H
     - set 2: B D E G
    */

    if(a.w + f.w + c.w + h.w != b.w + d.w + e.w + g.w ){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<Vercites> cube = {a,b,c,d,e,f,g,h};
   
    //Find the adjacent edges and subtract their weights if the condition is satisfied
    for(int i = 0; i < 8; i++){
        for(int j = 0;j < 8; j++){
            if(isAdjacent(i,j)){
                substraction_V(cube[i],cube[j]);
            }
        }
    }

    // C F H -> A
    // F - B - A
    if(cube[5].w > 0) move_W(cube[0],cube[1],cube[5]); 
    // H - E - A
    if(cube[7].w) move_W(cube[0],cube[4],cube[7]);
    // C - B - A
    if(cube[2].w) move_W(cube[0],cube[1],cube[2]);

    // D E G -> B
    // D - C - B
    if(cube[3].w) move_W(cube[1],cube[2],cube[3]);
    // E - A - B
    if(cube[4].w) move_W(cube[1],cube[0],cube[4]); 
    // G - C - B
    if(cube[6].w) move_W(cube[1],cube[2],cube[6]);

    //After putting the weight on the top of A, B, we just need to subtract their weight
    substraction_V(cube[0],cube[1]);

    for(char c: result) cout << c;

}
```
|    ID    |         Date        |    Author   |       Problem      |   Language  | Judgement result | Test # | Execution time | Memory used |
|:--------:|:-------------------:|:-----------:|:------------------:|:-----------:|:----------------:|:------:|:--------------:|:-----------:|
| 10192966 | 05:18:39 6 Mar 2023 | Toan Nguyen | 1155. Troubleduons | G++ 9.2 x64 |     Accepted     |        |      0.001     |    396 KB   |

The main function starts by defining a struct `Vercites` which contains a character `ch` representing the name of the vertex and an integer `w` representing the weight of the troubleduons at that vertex. It also defines a vector `result` to store the sequence of actions required to remove the troubleduons.

Next, it defines three functions:
 - `record(x,y,sign)` adds an action to the `result` vector, indicating that the weight of the troubleduons at vertices `x` and `y` is either being added or subtracted.
 - `substraction_V(x,y)` subtracts the weight of the troubleduons at vertices `x` and `y` by repeatedly calling `record` until one of the vertices has a weight of 0.
 - `move_W(a,b,c)` transfers the weight of the troubleduons from vertex `c` to vertices `a` and `b` by repeatedly calling `record` until the weight at vertex `c` is `0`.

The `isAdjacent(a,b)` function returns true if vertices `a` and `b` are adjacent on the cube. This is determined by checking the difference in their indices and handling the special cases where vertices wrap around or cross the diagonal.

The main function then initializes the eight vertices of the cube with their names and weights, and checks if the total weight of the troubleduons is evenly divided between the two sets of vertices. If not, it outputs `"IMPOSSIBLE"` and exits.

Next, it initializes a vector cube containing the eight vertices, and loops over all pairs of vertices to find adjacent vertices. For each adjacent pair, it calls `substraction_V` to subtract the weight of the troubleduons at the two vertices if the weight at both vertices is non-zero.

Finally, it calls `move_W` to transfer the weight of the troubleduons from specific vertices to the top vertices `A` and `B`. It then calls `substraction_V` to subtract the weight of the troubleduons at `A` and `B`, and outputs the sequence of actions stored in `result`.


## 4. Problem 1296: Hyperjump
```python
# Read input
n = int(input().strip())
a = []
for i in range(0, n):
    ele = int(input())
    a.append(ele) # adding the element

# Main solution
max_ending_here = 0
max_so_far = - n * 10e9
for i in range(n):
    max_ending_here += a[i]
    # Cut head of subarray if sum < 0
    if max_ending_here < 0: max_ending_here = 0
    # Replace new max potential
    if max_ending_here > max_so_far:
        max_so_far = max_ending_here
print(max_so_far)

```
This code reads in an integer `n` from the user and creates an empty list `a`. It then reads in `n` more integers from the user and appends them to `a`.

The main solution to the problem is then calculated using the Kadane's algorithm to find the maximum sum subarray. The algorithm initializes two variables, `max_ending_here` and `max_so_far`, both initially set to 0 and negative infinity respectively. It then iterates through the list a and calculates the maximum sum subarray ending at the current index i by adding the element `a[i]` to `max_ending_here`.

If the sum `max_ending_here` becomes negative, it means that the current subarray has a negative contribution to the sum, so we discard it and start a new subarray from the next index. This is achieved by setting `max_ending_here` to 0.

If the current `max_ending_here` sum is greater than the current `max_so_far` sum, then update `max_so_far` to `max_ending_here`. After iterating through the entire list, `max_so_far` will contain the maximum sum of any subarray within a.

Finally, the program prints the value of `max_so_far`, which is the solution to the maximum sum subarray problem.

## 5. Problem 1401: Gamers
|    ID    |         Date         |    Author   |    Problem   |   Language  | Judgement result | Test # | Execution time | Memory used |
|:--------:|:--------------------:|:-----------:|:------------:|:-----------:|:----------------:|:------:|:--------------:|:-----------:|
| 10218623 | 04:44:43 27 Mar 2023 | Toan Nguyen | 1401. Gamers | G++ 9.2 x64 |     Accepted     |        |      0.015     |   1 172 KB  |

```C
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

```

 The program uses a recursive algorithm that fills the square in a divide-and-conquer approach. The square is recursively divided into four quadrants until the size of each quadrant is equal to 2. At each recursion level, a 2x2 square is filled with numbers, except for the hole cell, and the hole cell is passed down to the recursive call of the quadrant that contains it.

The `main` function of the program reads the input size of the square and the coordinates of the hole cell from the standard input, initializes the map to zero, and calls the `solve` function with the size of the square and the coordinates of the hole cell. After the `solve` function returns, the `print_map` function is called to print the map of the filled square.

The `reset_map` function initializes the map to zero by iterating over all the cells of the square and setting their values to zero.

The `print_map` function prints the map of the filled square by iterating over all the cells of the square and printing their values. The `%3d` format specifier is used to print each value in a field of width 3 characters, which makes the output aligned.

The `fill_square_size_2` function fills a 2x2 square with numbers, except for the hole cell. The function takes as input the coordinates of the top-left corner of the square and the coordinates of the hole cell. It iterates over all the cells of the square and sets their values to a sequence of numbers, skipping the cell that corresponds to the hole cell.

The `solve` function is the heart of the algorithm that fills the square. The function takes as input the size of the square, the coordinates of the top-left corner of the square, and the coordinates of the hole cell. The function first checks if the size of the square is equal to 2, in which case it calls the `fill_square_size_2` function to fill the square. Otherwise, it finds the quadrant block that contains the hole cell, fills the middle triangle of the square with numbers, except for the hole cell, and recursively calls itself on each of the four quadrants of the square, passing down the coordinates of the hole cell to the quadrant that contains it.

## 6. Problem 1207: Median on the plane
|    ID    |         Date         |    Author   |          Problem          |   Language  | Judgement result | Test # | Execution time | Memory used |
|:--------:|:--------------------:|:-----------:|:-------------------------:|:-----------:|:----------------:|:------:|:--------------:|:-----------:|
| 10214245 | 20:33:26 23 Mar 2023 | Toan Nguyen | 1207. Median on the Plane | GCC 9.2 x64 |     Accepted     |        |      0.468     |    304 KB   | 

```C
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
```
The code is an implementation of the gift wrapping algorithm to solve the convex hull problem. Specifically, it looks for a line that separates the set of points into two equal-sized subsets, and returns the indices of the two points that define this line.

The main function first reads in the number of points `n`, and then dynamically allocates an array of `n` `point` structs. It then reads in the coordinates of each point.

Next, the function iterates over all pairs of points and computes the line that passes through them using the `get_line` function. For each line, it checks whether it separates the set of points into two equal-sized subsets using the `are_equal_sets` function. If it does, it prints the indices of the two points and exits the program.

The `get_line` function takes two `point` structs as input and returns a `line` struct. It computes the coefficients `a`, `b`, and `c` of the line `ax + by + c = 0` that passes through the two points.

The `dot_product_between_point_and_line` function takes a `point` struct and a `line` struct as input and returns the dot product between the point and the line. It computes `ax + by + c`.

The `are_equal_sets` function takes an array of `point` structs, the number of points `n`, and a `line` struct as input, and returns a boolean indicating whether the line separates the set of points into two equal-sized subsets. It iterates over all points in the array and computes the dot product between each point and the line using the `dot_product_between_point_and_line` function. If the dot product is positive, it increments a counter for the left subset. If it is negative, it increments a counter for the right subset. If the counters for the left and right subsets are equal at the end of the loop, the function returns true. Otherwise, it returns false.


## 7. Problem 1322: Spy
|    ID    |         Date         |    Author   |  Problem  |   Language  | Judgement result | Test # | Execution time | Memory used |
|:--------:|:--------------------:|:-----------:|:---------:|:-----------:|:----------------:|:------:|:--------------:|:-----------:|
| 10219178 | 17:11:51 27 Mar 2023 | Toan Nguyen | 1322. Spy | G++ 9.2 x64 |     Accepted     |        |      0.031     |    884 KB   |

```cpp
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
    0   A   a   4
    1   a   n   0
    2   a   n   5
    3   a   b   6
    4   b   A   3
    5   n   a   1
    6   n   a   2
    */
    for (int i = 0; i < length; i++) {
        cout << word[number = next_position[number]];
    }
    cout << endl;
    
    return 0;
}
```
In this implementation, the BWT is performed on the input string, and the resulting transformed string is output to the console.

Here is a brief overview of the main steps in the code:

1. The input string is read from the console along with an integer number.

2. An array called "contains" is used to count the number of occurrences of each character in the input string.

3. The "contains" array is then modified to contain the total number of characters that come before each character in the sorted order of the input string.

4. A new array called "next_position" is created to store the positions of the characters in the transformed string.

5. For each character in the input string, its position in the transformed string is calculated by finding the total number of characters that come before it in the sorted order of the input string, and then adding 1 to account for the repetition of the character.

6. The transformed string is then output to the console by starting at the position specified by the "number" variable and outputting the characters in the "next_position" array in sequence.

## 9. Problem 1604: Country of Fools
|    ID    |         Date         |    Author   |         Problem        |   Language  | Judgement result | Test # | Execution time | Memory used |
|:--------:|:--------------------:|:-----------:|:----------------------:|:-----------:|:----------------:|:------:|:--------------:|:-----------:|
| 10220312 | 04:30:17 28 Mar 2023 | Toan Nguyen | 1604. Country of Fools | G++ 9.2 x64 |     Accepted     |        |      0.093     |    488 KB   |

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

/*
 *  Shifts the value of the signs to the right
 *
 *  @param signs: array of signs
 *  @param n: number of signs
 *  @param i: index of the sign to be shifted
 */
void shift_signs_value(pair<int, int> *signs, int n, int i)
{
    int j = i + 1;
    while (signs[i].second < signs[j].second)
    {
        swap(signs[i], signs[j]);
        i++, j++;
        if (j == n)
            break;
    }
}

int main()
{
    int n = 0;
    cin >> n;
    pair<int, int> signs[n]; //<index, number of signs left>
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        cin >> x;
        sum += x;
        signs[i] = make_pair(i + 1, x);
    }
    sort(signs, signs + n, comp); // descending value of order

    while (sum--)
    {
        cout << signs[0].first << " ";
        signs[0].second--;
        if (n > 1 && signs[1].second > 0)
        {
            cout << signs[1].first << " ";
            signs[1].second--;
            sum--;
        }
        if (n > 2)
            shift_signs_value(signs, n, 1);
        if (n > 1)
            shift_signs_value(signs, n, 0);
    }
    cout << endl;
}
```
This code solves the "Speed Limit" problem by using an array of pairs to store the frequency of each speed limit sign, sorted in descending order based on the frequency. The algorithm then iterates through the array and prints out the index of the sign with the highest frequency. If there is a sign with a frequency greater than zero following it, the algorithm prints out the index of that sign as well.

After printing the two signs, the algorithm shifts the position of the two signs in the array based on the frequency. The sign with the higher frequency is shifted to the left, while the sign with the lower frequency is shifted to the right.

This process is repeated until all of the signs have been printed. The output is a list of the indices of the speed limit signs in the order they should be placed on the motorway to maximize the number of times a driver must change their speed.

## 10. Problem 1726: Visits
|    ID    |         Date         |    Author   |    Problem   |   Language  | Judgement result | Test # | Execution time | Memory used |
|:--------:|:--------------------:|:-----------:|:------------:|:-----------:|:----------------:|:------:|:--------------:|:-----------:|
| 10221294 | 16:23:07 28 Mar 2023 | Toan Nguyen | 1726. Visits | G++ 9.2 x64 |     Accepted     |        |      0.296     |   1 972 KB  |
```cpp
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n = 0;
    cin >> n;
    ll xs[n];
    ll ys[n];
    ll total_distance = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }
    sort(xs, xs + n);
    sort(ys, ys + n);
    for (ll i = 1; i < n; ++i) {
        total_distance += (xs[i] - xs[i - 1]) * i * (n - i) * 2;
        total_distance += (ys[i] - ys[i - 1]) * i * (n - i) * 2;
    }
    cout << total_distance / (n * (n - 1)) << endl;
}
```

This program takes in the input of a number `n`, followed by `n` pairs of integer coordinates, and calculates the average distance between all pairs of coordinates.

The program first declares an integer `n` and reads in the input value. It then creates two arrays `xs` and `ys` of length `n` to store the x and y coordinates of the input pairs respectively.

Next, it enters a for loop to read in the n pairs of coordinates and store them in the `xs` and `ys` arrays. The `sort()` function is called on both `xs` and `ys` arrays to sort the values in `ascending` order.

Another `for` loop is used to calculate the total distance between each pair of coordinates. It does this by calculating the difference between the `x` values and `y` values of each pair, multiplying this by `i` (the index of the current coordinate in the sorted array) and (n-i) (the number of coordinates remaining after the current coordinate), and multiplying the result by 2. The total_distance variable is updated by adding these values for both the xs and ys arrays.

For example, let's consider a road segment `S` at the `i`-th position. There are `i` points to the left of the road segment that need to be passed through to reach the right side of the road segment, and similarly there are `n-i` points to the right of the road segment that need to be passed through to reach the left side of the road segment. Therefore, we can calculate the total number of road segments travelled as `i * (n - i) * 2`.

Finally, the program outputs the average distance by dividing the total_distance variable by `n*(n-1)` which is the total number of possible distances between any two pairs of houses in the committee..