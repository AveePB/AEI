import turtle

# Objects
t = turtle.Turtle()

# Function to draw squares 
def draw_square(size: int, turn_left: bool):
    if (size < 10): return

    # Draw parent square
    for i in range(4):
        t.forward(size)

        # Draw child squre
        if (i in [0, 2]):
            draw_square(size/2, not turn_left)

        # Turn turtle
        if (turn_left): t.left(90)
        else: t.right(90)

# Set up turtle
t.penup(); t.setpos(-100, -100); t.pendown()
t.speed(0); t.width(2)

# Run turtle
draw_square(200, True)
turtle.done()