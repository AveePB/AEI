import turtle

# Constants
SIZE = 200

# Objects
t = turtle.Turtle()

# Function to draw a triangle
def draw_triangle(size: int):
    if (size < 20): return

    # Draw parent triangle
    for _ in range(3):
        t.forward(size)
        draw_triangle(size/2)
        t.right(120)

# Set up a turtle
t.penup(); t.goto((100, -100)); t.pendown()
t.speed(0); t.left(180); t.width(2)

# Run turtle
draw_triangle(SIZE)
t.forward(SIZE)
t.right(120)
turtle.done()
