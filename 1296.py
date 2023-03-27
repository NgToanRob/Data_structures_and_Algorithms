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


