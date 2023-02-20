from queue import Queue

def bfs(start):
    q = Queue()
    q.put((start, []))
    visited = {start}

    while not q.empty():
        state, actions = q.get()
        if all(x == 0 for x in state):
            return actions

        for i in range(8):
            for j in range(i + 1, 8):
                if abs(i - j) == 1:
                    new_state = list(state)
                    if new_state[i] > 0 and new_state[j] > 0:
                        new_state[i] -= 1
                        new_state[j] -= 1
                        new_state = tuple(new_state)
                        if new_state not in visited:
                            q.put((new_state, actions + [f"{chr(ord('A') + i)} {chr(ord('A') + j)} - {new_state}"]))
                            visited.add(new_state)
                    elif new_state[i] < 100 and new_state[j] < 100:
                        new_state[i] += 1
                        new_state[j] += 1
                        new_state = tuple(new_state)
                        if new_state not in visited:
                            q.put((new_state, actions + [f"{chr(ord('A') + i)} {chr(ord('A') + j)} + {new_state}"]))
                            visited.add(new_state)

    return "IMPOSSIBLE"

def main():
    start = tuple(map(int, input().strip().split()))
    actions = bfs(start)
    if actions == "IMPOSSIBLE":
        print(actions)
    else:
        for action in actions:
            print(action)

if __name__ == '__main__':
    main()
