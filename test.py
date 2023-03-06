# # Read input
# cameras = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
# troubleduons = [int(x) for x in input().split()]

# set1 = ['A', 'C', 'F', 'H']
# set2 = ['B', 'D', 'E', 'G']

# def get_neighbors(camera):
#     if camera == 'A': return ['B', 'D', 'E']
#     elif camera == 'B': return ['A', 'C', 'F']
#     elif camera == 'C': return ['B', 'D', 'G']
#     elif camera == 'D': return ['A', 'C', 'H']
#     elif camera == 'E': return ['A', 'F', 'G']
#     elif camera == 'F': return ['B', 'E', 'H']
#     elif camera == 'G': return ['C', 'E', 'H']
#     elif camera == 'H': return ['D', 'F', 'G']
    

# # Function to check if two cameras are neighbors
# def is_neighbor(camera1, camera2):
#     if camera2 in get_neighbors(camera1): return True
#     return False


# # Function to find a pair of neighboring cameras with troubleduons
# def find_troubleduon_pair():
#     for i in range(len(cameras)):
#         for j in range(i+1, len(cameras)):
#             if troubleduons[i] > 0 and troubleduons[j] > 0 and is_neighbor(cameras[i], cameras[j]):
#                 return i, j
#     return None



# # Main algorithm
# actions = []
# while sum(troubleduons) > 0:
#     pair = find_troubleduon_pair()
#     if pair is None:
#         print("impossible")
#         exit()
#     i, j = pair
#     actions.append(cameras[i] + cameras[j] + '-')
#     troubleduons[i] -= 1
#     troubleduons[j] -= 1

# # Output actions
# for action in actions:
#     print(action)


from collections import defaultdict

def build_graph(troubleduons):
    graph = defaultdict(set)
    for i in range(4):
        for j in range(4):
            if abs(i-j) == 1:
                node1 = chr(ord('A')+i)
                node2 = chr(ord('E')+j)
                graph[node1].add(node2)
                graph[node2].add(node1)
    return graph

def augment_path(graph, u, matching, visited):
    for v in graph[u]:
        if v not in visited:
            visited.add(v)
            if v not in matching:
                matching[u] = v
                return True
            elif augment_path(graph, matching[v], matching, visited):
                matching[u] = v
                return True
    return False

def hopcroft_karp(graph):
    matching = {}
    while True:
        visited = set()
        found_path = False
        for u in graph:
            if u not in matching and augment_path(graph, u, matching, visited):
                found_path = True
        if not found_path:
            break
    return matching

troubleduons = list(map(int, input().split()))

# Check if the sum is divisible by 4
if sum(troubleduons) % 4 == 0:
    print('hihi')
    print("impossible")
else:
    graph = build_graph(troubleduons)
    matching = hopcroft_karp(graph)
    if len(matching) < sum(troubleduons) // 2:
        print("impossible")
    else:
        actions = []
        for u, v in matching.items():
            action = u + v
            if u > v:
                action = v + u
                troubleduons[v - ord('E')] -= 1
            else:
                troubleduons[u - ord('A')] -= 1
            actions.append(action + "+")
        for i, td in enumerate(troubleduons):
            if td != 0:
                print("impossible")
                break
        else:
            actions.sort()
            for action in actions:
                print(action)
