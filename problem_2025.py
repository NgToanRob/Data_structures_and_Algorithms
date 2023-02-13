'''

'''


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