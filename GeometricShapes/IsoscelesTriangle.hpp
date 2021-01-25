#pragma once
#include <math.h>
#include "Triangle.hpp"

class IsoscelesTriangle : public Triangle {
private:
	//data members
	static const int sides = 3;
	float side1 = 0, side2 = 0;
	string name = "Isosceles Triangle";

	//this function is used to validate an isoscles triangle
	bool validateIsoTri(float newSideLengths[]) {
		side1 = newSideLengths[0];
		side2 = -1;
		for (int i = 1; i < sides - 1; i++)
			if (newSideLengths[i] != side1) {
				side2 = newSideLengths[i];
				break;
			}
		if (count(newSideLengths, sides, side1) == 2 && count(newSideLengths, sides, side2) == 1 ||
			count(newSideLengths, sides, side1) == 1 && count(newSideLengths, sides, side2) == 2)
			return true;
		return false;
	}

public:
	//constructor with parameter that is an array of the side lengths
	IsoscelesTriangle(float newSideLengths[]) {
		if (validateIsoTri(newSideLengths)) {
			setPerimeter(perimeter(newSideLengths, sides));
			setSideLengths(newSideLengths, sides);
			setSides(sides);
			setArea(area(newSideLengths));
			setName(name);
		}
	}

	IsoscelesTriangle(float vertices[sides][2]) : Triangle(vertices) {}

	//the area function
	float area(float sideLengths[]) {
		if (count(sideLengths, sides, side1) == 2)
			return side2 * sqrt(pow(side1, 2) - pow(side2, 2) / 4);
		return side1 * sqrt(pow(side2, 2) - pow(side1, 2) / 4);
	}
};
