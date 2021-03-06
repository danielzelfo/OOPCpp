/*
 * Author: Daniel Zelfo
 * Date: 9/7/2019
 * Class: CSCI 220
 * Description: This Program uses the Polygon abstract class to make different polygon subclasses.
				The Triangle and Rectangle classes are subclasses of the Polygon abstract class and are also abstract.
				The Square class is a subclass of the Rectangle Class. The RightTriangle, EquilateralTriangle, and IsoscelesTriangle classes are subclasses of the TriangleClass.
				Each class has its own area function that overrode the area function of the base class. The perimeter function was the same for all the subclasses, so no subclasses overrode the perimeter class.
 v1.1 (EXTRA CREDIT) The program also implements vertices into creating the polygons. A user can create any triangle using three vertices or and parallelogram (including rectangle and square) using 4 vertices.
 */


#include "Polygon.hpp"
#include "Triangle.hpp"
#include "RightTriangle.hpp"
#include "IsoscelesTriangle.hpp"
#include "EquilateralTriangle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Parallelogram.hpp"

using namespace std;

void geometricShapesMain()
{
	//I will make a Polygon object array of size 14
	Polygon* polygons[10];

	//these are the values of equal to the side lengths of the different polygons which i will use to create the objects
	int triangleSides = 3, rectangleSides = 4;

	float parallelogramVertices[4][2] = { {-3, 0}, {-1, 3}, {5, 2}, {3, -1} },
		  userDefinedVertices[10][2];

	string polyContinue = "y", vertexContinue;
	int vertexIndex, polyIndex = 0;

	cout << "A parallelogram: using the Parallelogram Constructor (with vertices) \n";
	polygons[0] = new Parallelogram(parallelogramVertices);
	polygons[0]->printPolygon();
	cout << endl;

	//NOW I WILL ALLOW THE USER TO CREATE THEIR OWN POLYGON USING VERTICES
	cout << "Please enter the coordinates of the vertices of your polygon.\n";
	
	while (polyContinue == "y") {
		polyIndex++;
		vertexContinue = "y";
		vertexIndex = -1;
		while (vertexContinue == "y") {
			cout << "Please enter the x-coordinate of vertex number " << (++vertexIndex)+1 << ": ";
			cin >> userDefinedVertices[vertexIndex][0];
			cout << "Please enter the y-coordinate of vertex number " << (vertexIndex) + 1 << ": ";
			cin >> userDefinedVertices[vertexIndex][1];
			if (vertexIndex >= 2) {
				cout << "Would you like to enter more vertices (y/n): ";
				cin >> vertexContinue;
			}
			if (vertexIndex >= 3) break;
		}

		cout << "Printing your polygon: \n";
		if (vertexIndex == 2)
			polygons[polyIndex] = new Triangle(userDefinedVertices);
		else
			polygons[polyIndex] = new Parallelogram(userDefinedVertices);

		polygons[polyIndex]->printPolygon();
		cout << endl;

		cout << "Would you like to create more polygons (y/n): ";
		cin >> polyContinue;

		if (polyIndex >= 9) break;
	}

	cout << "Thank you for using my program." << endl;
}