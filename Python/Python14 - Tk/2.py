from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox
import time

def chk():
    label.configure(text=str(chk_state.get()))


def clicked():
    result = messagebox.askyesno("Komunikat", "UWAGA!")
    print(result)


window = Tk()
window.geometry('500x300')
window.title("pierwsze okienko")

label = Label(window, text="False")
label.pack()

button = Button(window, text="Check", command = chk)
button.pack()

chk_state = BooleanVar()
chk_state.set(False)
check = Checkbutton(window, text="Choose", variable=chk_state, onvalue=True, offvalue=False)
check.pack()


x = IntVar()

rad1 = Radiobutton(window, text="First", value = 1, variable = x)
rad2 = Radiobutton(window, text="Second", value = 2, variable = x)
rad3 = Radiobutton(window, text="Third", value = 3, variable = x)

rad1.pack(anchor=W)
rad2.pack(anchor=W)
rad3.pack(anchor=W)

button2 = Button(window, text="Info", command=clicked)
button2.pack()


progress = Progressbar(window, orient=HORIZONTAL, length=100, mode="indeterminate")
progress.pack(pady = 10)

lab = Label(window, text='0')
lab.pack(pady = 10)

for i in range(1, 101):
    progress['value'] = i
    window.update()
    lab.configure(text=str(i))
    time.sleep(0.05)


window.mainloop()
