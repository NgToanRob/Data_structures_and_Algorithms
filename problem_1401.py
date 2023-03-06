n, (x, y) = int(input()), tuple(map(int, input().split()))

board = [[0] * (2 ** n) for _ in range(2 ** n)]
board[x-1][y-1] = 0  # mark the deleted cell

def fill_board(board, n, x_start, y_start):
    if n == 1:
        return [1]

    half_n = n // 2
    figures = [0] * 4

    # Check which quadrant contains the deleted cell
    quadrant = (0, 0)
    if x_start + half_n >= x and y_start + half_n >= y:
        quadrant = (0, 0)
    elif x_start + half_n >= x and y_start < y:
        quadrant = (0, 1)
    elif x_start < x and y_start + half_n >= y:
        quadrant = (1, 0)
    else:
        quadrant = (1, 1)
        x_start += half_n
        y_start += half_n

    # Recursively fill each quadrant
    for i in range(4):
        x_quadrant = x_start + (i // 2) * half_n
        y_quadrant = y_start + (i % 2) * half_n
        if quadrant == (i // 2, i % 2):
            figures[i] = -1
        else:
            figures[i] = fill_board(board, half_n, x_quadrant, y_quadrant)
            if figures[i] == -1:
                return -1

    # Assign a new figure to the quadrant that contains the deleted cell
    if quadrant != (0, 0):
        new_figure = max(figures) + 1
        board[x_start + half_n - 1][y_start + half_n - 1] = new_figure
    else:
        new_figure = figures[0]

    # Assign figures to the other three quadrants
    for i in range(4):
        if quadrant == (i // 2, i % 2):
            continue
        elif figures[i] == new_figure:
            return -1
        else:
            for row in range(x_quadrant, x_quadrant + half_n):
                for col in range(y_quadrant, y_quadrant + half_n):
                    board[row][col] = figures[i]

    return new_figure

if fill_board(board, n, 0, 0) == -1:
    print(-1)
else:
    for row in board:
        print(' '.join(str(x) for x in row))
