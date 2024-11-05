import turtle

# Constants
SIZE = 120
TURN1_DEGREE = 112.5
TURN2_DEGREE = 45

# Objects
t = turtle.Turtle()

# Function to draw dandelion
def draw_dandelion(size: int):
    # Stalk is too small
    if (size < 5): return

    # Draw stalk
    t.forward(size)
    t.left(TURN1_DEGREE)

    # Draw subelements
    for _ in range(6):
        draw_dandelion(size/2)
        t.right(TURN2_DEGREE)

    # Go back
    t.right(TURN1_DEGREE + 90)
    t.backward(size)

# Set up turtle
t.penup(); t.setpos(0, -100); t.pendown()
t.left(90); t.speed(0); t.width(2)

# Run turtle
draw_dandelion(SIZE)
turtle.done()