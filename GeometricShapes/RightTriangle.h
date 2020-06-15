#pragma once
#include <math.h>
#include "Triangle.h"

class RightTriangle : public Triangle {
private:
	//data members
	static const int sides = 3;
	float sideA, sideB, sideC;
	string name = "Right Triangle";

	

	//this function is used to validate a right triangle
	bool validateRightTri(float newSideLengths[]) {
		int indexOfC = largestSideIndex(newSideLengths, sides);
		sideC = newSideLengths[indexOfC];
		if ((pow(newSideLengths[(indexOfC + 1) % sides], 2) + pow(newSideLengths[(indexOfC + 2) % sides], 2)) == pow(sideC, 2)){
			sideA = newSideLengths[(indexOfC + 1) % sides];
			sideB = newSideLengths[(indexOfC + 2) % sides];
			return true;
		}
		return false;
	}
	
public:
	//constructor with parameter that is a float array of the side lengths
	RightTriangle(float newSideLengths[]) {
		if (validateRightTri(newSideLengths)) {
			setPerimeter(perimeter(newSideLengths, sides));
			setSideLengths(newSideLengths, sides);
			setSides(sides);
			setArea(area(newSideLengths));
			setName(name);
		}
	}

	RightTriangle(float vertices[sides][2]) : Triangle(vertices) {}

	//the area function
	float area(float sideLengths[]) {
		return (sideA * sideB) / 2;
	}
};
