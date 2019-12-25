# Game Scores Program
C++ Program for Game Scores

This program uses the two classes, GameScore and GameEntry. 
The GameEntry class is used to create game entries with specific names, scores, and dates.
The GameScore class is used to keep track of up to 5 top scored game entries.

User can construct a new GameScores object using a file name. 
The constructor will open that file and create game entries using the information isnide it. 
Also Uses a text file to save the top 5 scores game.

The GameScore class can remove all entries before a given date using remove(string date)

[![Run on Repl.it](https://repl.it/badge/github/danielzelfo/GameScores)](https://repl.it/GameScores)
