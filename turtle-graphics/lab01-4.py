import turtle

# Constants
SIZE = 200

# Objects
t = turtle.Turtle()

# Function to draw square
def draw_square(size: int):
    # Side is too small
    if (size < 20): return

    for _ in range(2):
        # Draw 1/4 of side
        t.forward(size/4); t.left(90)

        # Draw subsquare 
        draw_square(size/2)

        # Draw remaining 3/4 of side
        t.right(90); t.forward((size*3)/4)

        # Draw whole side
        t.right(90); t.forward(size); t.right(90)

# Set up turtle
t.penup(); t.setpos(-100, 0); t.pendown()
t.left(90); t.speed(0); t.width(2)

# Run turtle
draw_square(SIZE)
turtle.done()