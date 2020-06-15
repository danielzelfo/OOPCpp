#pragma once
#include <math.h>
#include "Triangle.h"

class EquilateralTriangle : public Triangle {
private:
	//data members
	static const int sides = 3;
	string name = "Equilateral Triangle";
public:
	//constructor with parameter that is the length of the sides
	EquilateralTriangle(float newSideLength) {
		setPerimeter(sides * newSideLength);
		setTriSideLengths(newSideLength);
		setSides(sides);
		setArea(area(newSideLength));
		setName(name);
	}

	EquilateralTriangle(float vertices[sides][2]) : Triangle(vertices) {}

	//the area method
	float area(float sideLength) {
		return ((sqrt(3) / 4) * pow(sideLength, 2));
	}
};
