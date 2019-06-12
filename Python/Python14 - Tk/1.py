from tkinter import *
from tkinter.ttk import *


def clicked():
    label2.configure(text="Oh NO")
    button.configure(text="Nie")


def increment():
    counter = int(str(label3['text']))
    counter += 1
    label3.configure(text=str(counter))

def entrycom():
    label1.configure(text="Printed: " +entry.get())
    entry.delete(0, END)

def combo_func(a):
    print("Wybrano: ", combo.get())


def chk():
    label1.configure(chk_state.get())


window = Tk()
window.geometry('500x200')

window.title("pierwsze okienko")

label1 = Label(window, text="Witaj!")
label2 = Label(window, text="Żegnaj", font=("Arial", 24))

# label1.pack(anchor=W)
# label2.pack(anchor=W)

label1.grid(column = 5)
label2.grid(row = 1, column = 1)

button1 = Button(window, text="ok", command=clicked)
button1.grid(row = 2, column = 2)

value = 0
button = Button(window, text="inc", command=increment)
button.grid(row = 3, column = 2)

label3 = Label(window, text="0")
label3.grid(row=3, column =3)

entry = Entry(window, width=20)
entry.focus()
entry.grid(row = 4, column = 4)

button = Button(window, text="save", command=entrycom)
button.grid(row = 4, column = 3)

combo = Combobox(window)
combo['values'] = (1,2,3,4, "Ala", "Kot")
combo.current()
combo.grid(row = 5, column = 1)

combo.bind("<<ComboboxSelected>>", combo_func)

chk_state = BooleanVar()
chk_state.set(False)
check = Checkbutton(window, text="Choose", variable=chk_state, onvalue=True, offvalue=False)
check.grid(row=6, column = 1)



window.mainloop()