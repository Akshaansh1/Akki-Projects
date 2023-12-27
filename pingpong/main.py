from turtle import Screen
import time
from striker import paddle
from ball import Ball
from scoreboard import score

screen = Screen()
screen.setup(width=800,height=600)
screen.bgcolor("black")
screen.title("PING PONG")
screen.tracer(0)

r_pad = paddle(350,0)
l_pad = paddle(-350,0)
ball = Ball()
Score = score()

screen.listen()
screen.onkeypress(r_pad.move_up,"Up")
screen.onkeypress(r_pad.move_down,"Down")
screen.onkeypress(l_pad.move_up,"w")
screen.onkeypress(l_pad.move_down,"s")

game_is_on = True

while game_is_on:
    time.sleep(ball.move_speed)
    screen.update()
    ball.move()

    if ball.ycor() > 280 or ball.ycor() < -280:
        ball.bounce_y()
    
    if ball.distance(r_pad) < 50 and ball.xcor() > 320 or ball.distance(l_pad) < 50 and ball.xcor() < -320 :
        ball.bounce_x()
    
    if ball.xcor() > 380:
        ball.reset_pos()
        Score.lpoint()
    
    if ball.xcor() < -380:
        ball.reset_pos()
        Score.rpoint()
    
screen.exitonclick()
