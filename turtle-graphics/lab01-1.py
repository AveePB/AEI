import turtle

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
t.penup(); t.goto((100, t.ycor())); t.pendown()
t.speed(0); t.left(180); t.width(2)

# Run turtle
draw_triangle(200)
turtle.done()
