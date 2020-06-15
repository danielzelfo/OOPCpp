// driver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "HugeInteger/driver.h"
#include "RationalNumber/driver.h"
//#include "RandomClasses/driver.h"
//#include "GeometricShapes/driver.h"
//#include "GameScores/driver.h"

using namespace std;

int main()
{
    int option;
    string options = "Please enter the number for the program to run\n";
           options += "0. To Exit\n";
           options += "1. HugeInteger\n";
           options += "2. RationalNumber\n";
           options += "3. RandomClasses\n";
           options += "4. GeometricShapes\n";
           options += "5. GameScores\n";

    cout << options << ">";
    cin >> option;

    while (option != 0) {
        switch (option) {
        case 1:
            hugeIntegerMain();
            break;
        case 2:
            rationalNumberMain();
            break;
        case 3:
            //randomClassesMain();
            break;
        case 4:
            //geometricShapesMain();
            break;
        case 5:
            //gameScoresMain();
            break;
        default:
            cout << "Invalid Option (" << option << ")\n";
            break;
        }

        cout << "End.\n\n";

        cout << options << ">";
        cin >> option;
    }

}