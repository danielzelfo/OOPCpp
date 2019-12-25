#pragma once
#include <math.h>
#include "Polygon.h"

class Triangle : public Polygon {
private:
	//data members
	static const int sides = 3;
	string name = "Triangle";

	
	//this function is used to validate a tringle. If the largest side is largest than the sum of the two other sides, the triangle is not valid
	bool validateTriangle(float newSideLengths[]) {
		int indexOfLargestSide = largestSideIndex(newSideLengths, sides);
		if (newSideLengths[indexOfLargestSide] > (newSideLengths[(indexOfLargestSide + 1) % sides] + newSideLengths[(indexOfLargestSide + 2) % sides]))
			return false;
		return true;

	}

	//this function substracts the vectors of the first two parameters and sets the result to the third parameter (i will use this to get the vector that represents the third side of a triangle)
	void substractVectors(float vector1[2], float vector2[2], float result[2]) {
		result[0] = vector2[0] - vector1[0];
		result[1] = vector2[1] - vector1[1];
	}

public:
	//default constructor
	Triangle() {}

	//overload constructor with parameter that is a float array of the side lengths
	Triangle(float newSideLengths[]) {
		if (validateTriangle(newSideLengths)) {
			setPerimeter(perimeter(newSideLengths, sides));
			setSideLengths(newSideLengths, sides);
			setSides(sides);
			setArea(area(newSideLengths));
			setName(sides);
		}else
			setName("Invalid " + name);
	}

	Triangle(float vertices[sides][2]) {
		float newSideLengths[sides];
		float vectors[2][2];
		float vector3[2];

		verticesToVectors(vertices, vectors);
		newSideLengths[0] = vectorMagnitude(vectors[0]);
		newSideLengths[1] = vectorMagnitude(vectors[1]);
		substractVectors(vectors[0], vectors[1], vector3);
		newSideLengths[2] = vectorMagnitude(vector3);

		//validating the triangle
		if (validateTriangle(newSideLengths)) {
			

			setVertices(vertices, sides);
			isVertexDefined();
			setPerimeter(perimeter(newSideLengths, sides));
			setSideLengths(newSideLengths, sides);
			setSides(sides);
			setArea(area(vectors));
			setName(sides);
		}
		else {
			setName("Invalid " + name);
		}
	}

	//this function returns the biggest side of a triangle. This is used to find the hypotenuse of a right triangle
	int largestSideIndex(float newSideLengths[], int newSides) {
		int heightestIndex = 0;
		for (int i = 1; i < newSides; i++)
			if (newSideLengths[i] > newSideLengths[heightestIndex])
				heightestIndex = i;
		return heightestIndex;
	}
	
	//area function which is also abstract so that the subclasses can override it
	virtual float area(float newSideLengths[]) {
		float halfPerimeter = getPerimeter() / 2, areaSquared = halfPerimeter;
		for (int i = 0; i < sides; i++)
			areaSquared *= (halfPerimeter - newSideLengths[i]);
		return sqrt(areaSquared);
	}

	float area(float vectors[2][2]) {
		return CrossProduct(vectors[0], vectors[1])/2;
	}

	//this function is used to set the sidelengths of an equilateral triangle
	void setTriSideLengths(float sideLength) {
		float sideLengths[3];
		for (int i = 0; i < sides; i++)
			sideLengths[i] = sideLength;
		setSideLengths(sideLengths, sides);
	}
};
