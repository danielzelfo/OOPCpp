#pragma once
#include <math.h>
#include "Polygon.hpp"

class Parallelogram : public Polygon {
private:
	//data members
	static const int sides = 4;
	float height = 0, width = 0;
	string name = "Parallelogram";


public:
	//default constructor
	Parallelogram() {}
	//constructor with parameter that is an array of four vertex arrays with two elements (x coordinate and y coordinate)
	Parallelogram(float vertices[sides][2]) {
		float newSideLengths[sides];
		float vectors[2][2];
		
		//validating that the sides are either only two different lenghts or all equal
		if (Polygon::validateRectangle(newSideLengths, sides) || (newSideLengths[0] == newSideLengths[1] && newSideLengths[1] == newSideLengths[2] && newSideLengths[2] == newSideLengths[3])) {
			verticesToVectors(vertices, vectors);
			newSideLengths[0] = vectorMagnitude(vectors[0]);
			newSideLengths[1] = vectorMagnitude(vectors[1]);
			newSideLengths[2] = newSideLengths[0];
			newSideLengths[3] = newSideLengths[1];

			setVertices(vertices, sides);
			isVertexDefined();
			setPerimeter(perimeter(newSideLengths, sides));
			setSideLengths(newSideLengths, sides);
			setSides(sides);
			setArea(area(vectors));
			setName(name);
		}
		else {
			setName("Invalid " + name);
		}
	}

	//the area function which is also abstract so that the subclasses can override it
	float area(float vectors[2][2]) {
		return CrossProduct(vectors[0], vectors[1]);
	}
};
