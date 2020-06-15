# OOPCpp
A Collection of Object Oriented Programs in C++

[![Run on Repl.it](https://repl.it/badge/github/danielzelfo/OOPCpp)](https://repl.it/github/danielzelfo/OOPCpp)

## HugeInteger
C++ Huge Integer Program

This program includes a HugeInt class which ecapsulates an integer than can be over 32 bits. The HugeInt class can do mathematical operations on huge integers, compare them, and output them.


## RationalNumber
C++ Rational Number Program

This program includes a RationalNumber class whiche ecapsulates a rational number. The RationalNumber class can reduce fractions. It can also add, subtract, multiply, and divide rational numbers expressed as fractions.


## RandomClasses
C++ Random Classes Program

Includes a random date class, a random time class, a random lottery number class, a random message class, and a random string class.

Includes a simulation for the lottery and uses the randlotto class to generate random lottery numbers to find the probability to win the lottery.

Includes the classroom birthday simulation. It uses the randDay class to generate random birthdays in the same year and runs 6 different simulations for class sizes 20-25 and finds the probability that a birthday repeats for each class size.


## GeometricShapes
C++ Geometric Shapes Program

This Program uses the Polygon abstract class to make a subclass which are different polygons.

The Triangle and Rectangle classes are subclasses of the Polygon abstract class and are also abstract.

The Square class is a subclass of the Rectangle Class. The RightTriangle, EquilateralTriangle, and IsoscelesTriangle classes are subclasses of the TriangleClass.

Each class has their own area function that overrode the area function of the base class. The perimeter function was the same for all the subclasses, so no subclasses overrode the perimeter class.

the program also implements vertices into creating the polygons

a user is able to create any triangle using three vertices or and parallelogram (including rectangle and square) using 4 vertices


## GameScores
C++ Program for Game Scores

This program uses the two classes, GameScore and GameEntry. The GameEntry class is used to create game entries with specific names, scores, and dates. The GameScore class is used to keep track of up to 5 top scored game entries.

User can construct a new GameScores object using a file name. The constructor will open that file and create game entries using the information isnide it. Also Uses a text file to save the top 5 scores game.

The GameScore class can remove all entries before a given date using remove(string date)