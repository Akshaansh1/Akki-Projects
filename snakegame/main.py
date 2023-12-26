from turtle import Screen
import time
from snake import Snake
from food import Food
from scoreboard import ScoreBoard

screen = Screen()

screen.setup(width=600, height=600)
screen.bgcolor("black")
screen.title("My Snake Game")
screen.tracer(0)

snake_1 = Snake()
food = Food()
score = ScoreBoard()

screen.listen()
screen.onkey(snake_1.up, "Up")
screen.onkey(snake_1.left, "Left")
screen.onkey(snake_1.right, "Right")
screen.onkey(snake_1.down, "Down")

game_is_on = True

while game_is_on:
    screen.update()
    time.sleep(0.1)

    snake_1.move()

    if snake_1.head.distance(food) < 15:
        food.refresh()
        snake_1.extend()
        score.increase_score()
    
    if snake_1.head.xcor() > 280 or snake_1.head.xcor() < -280 or snake_1.head.ycor() > 280 or snake_1.head.ycor() < -280:
        game_is_on = False
        score.game_over()

    for seg in snake_1.segments:
        if seg == snake_1.head:
            pass
        elif snake_1.head.distance(seg) < 10:
            game_is_on = False
            score.game_over()




screen.exitonclick()
