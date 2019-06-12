from tkinter import *

def paint(event):
    python_green = "#476042"
    x1, y1 = (event.x - 2), (event.y - 2)
    x2, y2 = (event.x + 2), (event.y + 2)
    w.create_oval(x1, y1, x2, y2, fill= python_green)


window = Tk()

w = Canvas(window, width = 300  , height= 300)
w.pack(expand=YES, fill=BOTH)

w.bind("<B1-Motion>", paint)


# w = Canvas(window, width = 400, height=300)
#w.pack()

#w.create_line(0,0, 400, 400)
#w.create_line(0,100, 200, 0, fill="red", dash=(4, 4))
#w.create_rectangle(50, 50, 150, 75, fill="yellow")
#w.create_oval(270, 170, 90, 100, fill="magenta", width=10)

#points = [100, 140,110, 140, 100, 110, 90, 100, 60, 90, 90, 100, 90, 110]
#w.create_polygon(points, outline="red", fill="yellow", width = 3)

#w.create_text(300, 200, text="Python", font=("", 20))

mainloop()