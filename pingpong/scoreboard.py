from turtle import Turtle

class score(Turtle) :

    def __init__(self) :
        super().__init__()
        self.color("white")
        self.penup()
        self.hideturtle()
        self.lscore = 0
        self.rscore = 0
        self.update_scoreboard()

    def update_scoreboard(self):
        self.goto(-100,200)
        self.write(self.lscore,align= "center" , font=("Courier" , 60 , "normal"))
        self.goto(100,200)
        self.write(self.rscore,align= "center" , font=("Courier" , 60 , "normal"))

    def lpoint(self):
        self.lscore += 1
        self.clear()
        self.update_scoreboard()
    
    def rpoint(self):
        self.rscore += 1
        self.clear()
        self.update_scoreboard()