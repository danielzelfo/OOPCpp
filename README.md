# OOPCpp
A Collection of Object-oriented Programs in C++

[![Run on Repl.it](https://repl.it/badge/github/danielzelfo/OOPCpp)](https://repl.it/github/danielzelfo/OOPCpp)

## HugeInteger
C++ Huge Integer Program

This program includes a *HugeInt* class which encapsulates an integer that can be over 32 bits. The *HugeInt* class can do mathematical operations on huge integers, compare them, and output them.


## RationalNumber
C++ Rational Number Program

This program includes a *RationalNumber* class which encapsulates a rational number. The *RationalNumber* class can reduce fractions. It can also *add*, *subtract*, *multiply*, and *divide* rational numbers expressed as fractions.


## RandomClasses
C++ Random Classes Program

The program includes the *RandDay* class, the *RandTime* class, the *RandLotto* class, the *RandMsgOfTheDay* class, and the *RandString* class.

The program includes a simulation for the lottery and uses the *RandLotto* class to generate random lottery numbers to find the probability to win the lottery.

The program includes the classroom birthday simulation. It uses the *RandDay* class to generate random birthdays in the same year. It runs 6 different simulations for class sizes 20-25 and finds the probability that a birthday repeats for each class size.


## GeometricShapes
C++ Geometric Shapes Program

This Program uses the Polygon abstract class to make different polygon subclasses.

The *Triangle* and *Rectangle* classes are subclasses of the *Polygon* abstract class and are also abstract.

The *Square* class is a subclass of the *Rectangle* Class. The *RightTriangle*, *EquilateralTriangle*, and *IsoscelesTriangle* classes are subclasses of the *TriangleClass*.

Each class has its own *area* function that overrode the *area* function of the base class. The *perimeter* function was the same for all the subclasses, so no subclasses overrode the *perimeter* class.

The program also implements vertices into creating the polygons. A user can create any triangle using three vertices or and parallelogram (including rectangle and square) using 4 vertices.


## GameScores
C++ Program for Game Scores

This program uses two classes, *GameScore* and *GameEntry*. The *GameEntry* class is used to create game entries with specific names, scores, and dates. The *GameScore* class is used to keep track of up to 5 top-scored game entries.

Users can construct a new *GameScores* object using a file name. The constructor will open that file and create game entries using the information inside it. The class also uses a text file to save the top 5 scores game.

The *GameScore* class can remove all entries before a given date using *remove(string date)*.