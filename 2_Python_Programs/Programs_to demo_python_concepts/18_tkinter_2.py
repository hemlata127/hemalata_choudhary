from tkinter import *;

topwindow = Tk();

name = Label(topwindow, text = "Name").grid(row = 0, column = 0);
t1 = Entry(topwindow).grid(row = 0, column = 1);


password = Label(topwindow, text = "Password").grid(row = 1, column = 0);
t2 = Entry(topwindow).grid(row = 1, column = 1);


submit = Button(topwindow, text = "Submit").grid(row = 4, column = 0);

topwindow.mainloop();