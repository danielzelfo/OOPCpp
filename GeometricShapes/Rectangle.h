#pragma once
#include <math.h>
#include "Parallelogram.h"
#include "Polygon.h"

class Rectangle : public Parallelogram {
private:
	//data members
	static const int sides = 4;
	float height = 0, width = 0;
	string name = "Rectangle";

public:
	//default constructor
	Rectangle() {}
	//constructor with parameter that is an array of floats equal to the lengths of the sides of the rectangle
	Rectangle(float newSideLengths[]) {
		if (validateRectangle(newSideLengths, width, height, sides) || (newSideLengths[0] == newSideLengths[1] && newSideLengths[1] == newSideLengths[2] && newSideLengths[2] == newSideLengths[3])) {
			setPerimeter(perimeter(newSideLengths, sides));
			setSideLengths(newSideLengths, sides);
			setSides(sides);
			setArea(area(newSideLengths));
			setName(sides);
		}
		else {
			setName("Invalid " + name);
		}
	}

	//CONSTRUCTING A RECTANGLE WITH VERTICES
	Rectangle(float vertices[sides][2]) : Parallelogram(vertices) {}

	//the area function which is also abstract so that the subclasses can override it
	virtual float area(float newSideLengths[]) {
		return width * height;
	}

	//this method is used to set the side lengths of the square subclass, which only has a data member that is a float value of the side lengths (not an array)
	void setRecSideLengths(float sideLength) {
		float sideLengths[4];
		for (int i = 0; i < sides; i++)
			sideLengths[i] = sideLength;
		setSideLengths(sideLengths, sides);
	}
};
