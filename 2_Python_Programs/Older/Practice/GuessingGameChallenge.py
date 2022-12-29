'''
Guessing Game Challenge
Let's use while loops to create a guessing game.

The Challenge:

Write a program that picks a random integer from 1 to 100, and has players guess the number. The rules are:

If a player's guess is less than 1 or greater than 100, say "OUT OF BOUNDS"
On a player's first turn, if their guess is
within 10 of the number, return "WARM!"
further than 10 away from the number, return "COLD!"
On all subsequent turns, if a guess is
closer to the number than the previous guess return "WARMER!"
farther from the number than the previous guess, return "COLDER!"
When the player's guess equals the number, tell them they've guessed correctly and how many guesses it took!
'''

from random import *;
computer_pick_number = randint(1,100);
turn = 1;
current_guess = int(input("Guess your number: "));
#print("Computer guess is {}".format(computer_pick_number));
#print("User guess is {}".format(current_guess));
if current_guess>=(computer_pick_number-10) and current_guess<=(computer_pick_number+10):
    print("WARM");
else:
    print("COLD");

turn = turn+1;
while True:
    user_guess = int(input("Guess your number: "));
    #print("Previous guess was {}".format(current_guess));
    #print("Current guess is {}".format(user_guess));
    if user_guess == computer_pick_number:
        print("You made correct guess in {} tries".format(turn));
        exit();
    elif user_guess>=(current_guess-10) and user_guess<=(current_guess+10):
        print("WARMER");
    else:
        print("COLDER");
    current_guess = user_guess;
    turn = turn+1;
