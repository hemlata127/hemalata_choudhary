from tkinter import *;
top = Tk();

redButton = Button(top, text = "Red", fg = "red");
redButton.pack(side = LEFT);

blueButton = Button(top, text = "Blue", fg = "blue");
blueButton.pack(side = RIGHT);

greenButton = Button(top, text = "Green", fg = "green");
greenButton.pack(side = TOP);

yellowButton = Button(top, text = "Yellow", fg = "yellow");
yellowButton.pack(side = BOTTOM);

top.mainloop();