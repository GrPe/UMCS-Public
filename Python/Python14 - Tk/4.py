from tkinter import *
import time

window = Tk()

window.geometry("800x800")

c = Canvas(window, width = 800, height= 800)
c.pack()

oval = c.create_oval(5,5,60,60, fill="pink")
a = 3
b = 3
for x in range(0, 100):
    c.move(oval, a, b)
    window.update()
    time.sleep(0.02)

window.title("Animacja")
window.mainloop()