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

## 1. Problem 2025: Line Fighting

```python
T = int(input().strip())
result = []
for _ in range(T):
    n, k = map(int, input().strip().split())
    a = n // k # standard number of fighters in each team
    e_t = n % k # number of teams with one extra fighter
    s_t = k - e_t # number of teams with the standard number of fighters


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

