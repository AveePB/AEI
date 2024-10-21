import turtle

# Objects
t = turtle.Turtle()

# Function to draw a sierpinski triangle recursively
def draw_triangle(side):
    if (side > 10):
        # Draw parent triangle
        for _ in range(3):
            t.forward(side)
            t.left(120)

            # Draw subtriangle
            draw_triangle(side/2)

# Set center position
t.penup(); t.goto((-100, t.ycor())); t.pendown()
t.speed(10)

# Run turtle
draw_triangle(200)
turtle.done()
