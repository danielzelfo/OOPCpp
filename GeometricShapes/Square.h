#pragma once
#include <math.h>

#include "Rectangle.h"

class Square : public Rectangle {
private:
	//data members
	static const int sides = 4;
	float height, width;
	string name = "Square";

public:
	//constructor with parameter which is a float equal to the length of the sides of the square
	Square(float sideLength) {
		setPerimeter(sides*sideLength);
		setRecSideLengths(sideLength);
		setArea(area(sideLength));
		setName(name);
		setSides(sides);
	}

	//CONSTRUCTING A SQUARE WITH VERTICES
	Square(float vertices[sides][2]): Rectangle(vertices) {}

	//the area function
	float area(float sideLength) {
		return sideLength * sideLength;
	}
};
