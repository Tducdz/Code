import pygame
import random
import sys

# Khởi tạo Pygame
pygame.init()

# Kích thước màn hình game
screen_width = 600
screen_height = 400
screen = pygame.display.set_mode((screen_width, screen_height))

# Màu sắc
white = (255, 255, 255)
black = (0, 0, 0)
red = (213, 50, 80)
green = (0, 255, 0)
yellow = (255, 255, 0)  # Màu đầu rắn

# FPS và khung thời gian
clock = pygame.time.Clock()
snake_speed = 15

# Kích thước ô lưới
block_size = 20

# Font chữ
font = pygame.font.SysFont("bahnschrift", 25)

# Hàm hiển thị điểm
def show_score(score):
    value = font.render("Điểm: " + str(score), True, white)
    screen.blit(value, [0, 0])

# Hàm tạo con rắn
def snake(snake_block, snake_list):
    for i, x in enumerate(snake_list):
        if i == len(snake_list) - 1:
            # Vẽ đầu rắn bằng màu vàng (màu khác)
            pygame.draw.rect(screen, yellow, [x[0], x[1], snake_block, snake_block])
        else:
            # Vẽ thân rắn bằng màu xanh
            pygame.draw.rect(screen, green, [x[0], x[1], snake_block, snake_block])

# Hàm chính của game
def game_loop():
    game_over = False
    game_close = False

    # Tọa độ ban đầu của con rắn
    x = screen_width / 2
    y = screen_height / 2

    # Tốc độ ban đầu
    x_change = block_size
    y_change = 0

    # Hướng di chuyển ban đầu (phải)
    direction = "RIGHT"

    # Danh sách lưu vị trí của con rắn
    snake_list = []
    snake_length = 1

    # Tạo thức ăn cho rắn
    food_x = round(random.randrange(0, screen_width - block_size) / block_size) * block_size
    food_y = round(random.randrange(0, screen_height - block_size) / block_size) * block_size

    while not game_over:

        while game_close:
            screen.fill(black)
            message = font.render("Thua cuộc! Nhấn C để chơi lại hoặc Q để thoát.", True, red)
            screen.blit(message, [screen_width / 6, screen_height / 3])
            show_score(snake_length - 1)
            pygame.display.update()

            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        game_over = True
                        game_close = False
                    if event.key == pygame.K_c:
                        game_loop()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_over = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT and direction != "RIGHT":
                    x_change = -block_size
                    y_change = 0
                    direction = "LEFT"
                elif event.key == pygame.K_RIGHT and direction != "LEFT":
                    x_change = block_size
                    y_change = 0
                    direction = "RIGHT"
                elif event.key == pygame.K_UP and direction != "DOWN":
                    y_change = -block_size
                    x_change = 0
                    direction = "UP"
                elif event.key == pygame.K_DOWN and direction != "UP":
                    y_change = block_size
                    x_change = 0
                    direction = "DOWN"

        # Cập nhật vị trí của rắn
        x += x_change
        y += y_change

        # Kiểm tra va chạm với tường và đưa rắn sang phía đối diện
        if x >= screen_width:
            x = 0
        elif x < 0:
            x = screen_width - block_size
        if y >= screen_height:
            y = 0
        elif y < 0:
            y = screen_height - block_size

        screen.fill(black)
        pygame.draw.rect(screen, white, [food_x, food_y, block_size, block_size])

        snake_head = []
        snake_head.append(x)
        snake_head.append(y)
        snake_list.append(snake_head)

        if len(snake_list) > snake_length:
            del snake_list[0]

        for segment in snake_list[:-1]:
            if segment == snake_head:
                game_close = True

        # Vẽ rắn với đầu màu khác
        snake(block_size, snake_list)
        show_score(snake_length - 1)

        pygame.display.update()

        if x == food_x and y == food_y:
            food_x = round(random.randrange(0, screen_width - block_size) / block_size) * block_size
            food_y = round(random.randrange(0, screen_height - block_size) / block_size) * block_size
            snake_length += 1

        clock.tick(snake_speed)

    pygame.quit()
    sys.exit()

# Chạy game
game_loop()
