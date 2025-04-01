import pygame
import sys

# Khởi tạo pygame
pygame.init()

# Kích thước cửa sổ game và bàn cờ
WIDTH, HEIGHT = 600, 600  # Kích thước cửa sổ hiển thị
GRID_SIZE = 20  # Kích thước bàn cờ lớn (20x20)
LINE_WIDTH = 2
SQUARE_SIZE = WIDTH // GRID_SIZE
CIRCLE_RADIUS = SQUARE_SIZE // 3
CIRCLE_WIDTH = 15
CROSS_WIDTH = 15
SPACE = SQUARE_SIZE // 4

# Màu sắc
BG_COLOR = (28, 170, 156)
LINE_COLOR = (23, 145, 135)
CIRCLE_COLOR = (239, 231, 200)
CROSS_COLOR = (84, 84, 84)

# Tạo cửa sổ game
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('Tic Tac Toe Vô Hạn (5 điểm)')
screen.fill(BG_COLOR)

# Bàn cờ lớn (20x20)
board = [[None for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]

# Vẽ lưới
def draw_lines():
    for row in range(GRID_SIZE):
        pygame.draw.line(screen, LINE_COLOR, (0, row * SQUARE_SIZE), (WIDTH, row * SQUARE_SIZE), LINE_WIDTH)
        pygame.draw.line(screen, LINE_COLOR, (row * SQUARE_SIZE, 0), (row * SQUARE_SIZE, HEIGHT), LINE_WIDTH)

# Vẽ dấu O
def draw_circle(row, col):
    pygame.draw.circle(screen, CIRCLE_COLOR, (col * SQUARE_SIZE + SQUARE_SIZE // 2, row * SQUARE_SIZE + SQUARE_SIZE // 2), CIRCLE_RADIUS, CIRCLE_WIDTH)

# Vẽ dấu X
def draw_cross(row, col):
    pygame.draw.line(screen, CROSS_COLOR, 
                     (col * SQUARE_SIZE + SPACE, row * SQUARE_SIZE + SQUARE_SIZE - SPACE), 
                     (col * SQUARE_SIZE + SQUARE_SIZE - SPACE, row * SQUARE_SIZE + SPACE), CROSS_WIDTH)
    pygame.draw.line(screen, CROSS_COLOR, 
                     (col * SQUARE_SIZE + SPACE, row * SQUARE_SIZE + SPACE), 
                     (col * SQUARE_SIZE + SQUARE_SIZE - SPACE, row * SQUARE_SIZE + SQUARE_SIZE - SPACE), CROSS_WIDTH)

# Kiểm tra điều kiện thắng (5 dấu liên tiếp)
def check_winner(player):
    # Kiểm tra hàng, cột, và đường chéo
    for row in range(GRID_SIZE):
        for col in range(GRID_SIZE):
            if board[row][col] == player:
                # Kiểm tra hàng ngang (5 dấu liên tiếp)
                if col <= GRID_SIZE - 5 and all(board[row][col + i] == player for i in range(5)):
                    return True
                # Kiểm tra hàng dọc (5 dấu liên tiếp)
                if row <= GRID_SIZE - 5 and all(board[row + i][col] == player for i in range(5)):
                    return True
                # Kiểm tra đường chéo chính (5 dấu liên tiếp)
                if row <= GRID_SIZE - 5 and col <= GRID_SIZE - 5 and all(board[row + i][col + i] == player for i in range(5)):
                    return True
                # Kiểm tra đường chéo phụ (5 dấu liên tiếp)
                if row >= 4 and col <= GRID_SIZE - 5 and all(board[row - i][col + i] == player for i in range(5)):
                    return True
    return False

# Đánh dấu vào ô trống
def mark_square(row, col, player):
    board[row][col] = player

# Kiểm tra ô trống
def available_square(row, col):
    return board[row][col] is None

# Hàm chính điều khiển game
def main():
    player = "X"
    game_over = False

    draw_lines()

    # Vòng lặp game
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            if event.type == pygame.MOUSEBUTTONDOWN and not game_over:
                mouseX = event.pos[0]  # tọa độ X của chuột
                mouseY = event.pos[1]  # tọa độ Y của chuột

                clicked_row = mouseY // SQUARE_SIZE
                clicked_col = mouseX // SQUARE_SIZE

                if available_square(clicked_row, clicked_col):
                    if player == "X":
                        mark_square(clicked_row, clicked_col, "X")
                        draw_cross(clicked_row, clicked_col)
                        if check_winner("X"):
                            print("Người chơi X thắng!")
                            game_over = True
                        player = "O"
                    elif player == "O":
                        mark_square(clicked_row, clicked_col, "O")
                        draw_circle(clicked_row, clicked_col)
                        if check_winner("O"):
                            print("Người chơi O thắng!")
                            game_over = True
                        player = "X"
                
                # Kiểm tra hòa (bàn cờ đầy)
                if all(board[row][col] is not None for row in range(GRID_SIZE) for col in range(GRID_SIZE)) and not game_over:
                    print("Hòa!")
                    game_over = True

        pygame.display.update()

if __name__ == "__main__":
    main()
