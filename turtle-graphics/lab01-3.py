import turtle

# Constants
SIZE = 120

# Objects
t = turtle.Turtle()

# Function to draw branches
def draw_branch(size: int, turn_left: bool):
    if (size < 10): return

    # Draw branch
    if (turn_left): t.left(15)
    else: t.right(15)
    t.forward(size)

    # Draw children
    draw_branch(size*0.8, turn_left)
    draw_branch(size*0.8, not turn_left)
    
    # Go back
    t.backward(size)
    if (turn_left): t.right(15)
    else: t.left(15)

# Set up turtle
t.penup(); t.setpos(0, -300); t.pendown()
t.left(75); t.speed(0); t.width(2)

# Run turtle
draw_branch(SIZE, turn_left=True)
turtle.done()