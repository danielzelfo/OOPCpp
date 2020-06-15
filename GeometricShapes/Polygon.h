#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

const float defaultLen = -1.0;
class Polygon {
private:
	int sides;
	vector<float> sideLengths;
	string name;
	float perimeterVal;
	float areaVal;
	bool vertexDefined = false;
	vector<vector<float>> polyVertices;

	//This will be used to find out if a polygon is a square of isosceles triangle
	bool equalSides(vector<float> sideLengths) {
		for (int i = 1; i < sideLengths.size(); i++) {
			if (sideLengths[i] != sideLengths[(i - 1)])
				return false;
		}
		return true;
	}
public:
	//default constructor
	Polygon() {
		name = "Polygon";
	}
	//overload constructor with parameter for number of sides in the polygon and an array including all the side lengths
	Polygon(int newSides, float newSideLengths[]) {
		perimeterVal = perimeter(newSideLengths, newSides);
		setSideLengths(newSideLengths, newSides);
		sides = newSides;
		setName(newSides);
		areaVal = area(newSideLengths);
	}

	//virtual functions
	virtual float perimeter(float newSideLengths[], int newSides) {
		float tempPerimeter = 0;

		for (int i = 0; i < newSides; i++)
			tempPerimeter += newSideLengths[i];
		return tempPerimeter;
	}
	virtual float area(float newSideLengths[]) { 

		return -1;
	}


	//this function takes an array of vertices and returns vectors along those vertices
	void verticesToVectors(float vertices[][2], float vectors[][2]) {
		for (int i = 0; i < 2; i++) {
			vectors[i][0] = vertices[i + 1][0] - vertices[i][0];
			vectors[i][1] = vertices[i + 1][1] - vertices[i][1];
		}
	}

	//this function returns the magnitude of the cross product of two vectors (in 2-D) [ I WILL USE THIS TO FIND THE AREA OF POLYGONS ]
	float CrossProduct(float vector1[2], float vector2[2]) {
		return abs(vector1[0] * vector2[1] - vector1[1] * vector2[0]);
	}

	//this function returns the magnitude of a vector
	float vectorMagnitude(float vector[2]) {
		return sqrt(pow(vector[0], 2) + pow(vector[1], 2));
	}

	
	
	

	//destructor
	virtual ~Polygon() { }

	//print function
	void printPolygon();

	//this function will be used to count the occurances of a float value in a float array
	static int count(float arr[], int size, float tar) {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] == tar)
				count++;
		}
		return count;
	}
	
	//this function will be used to count the occurances of a float value in a float array
	int count(vector <float> arr, int size, float tar) {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] == tar)
				count++;
		}
		return count;
	}
	

	//this function returns the biggest side of a triangle. This is used to find the hypotenuse of a right triangle
	int largestSideIndex(vector<float> newSideLengths, int newSides) {
		int heightestIndex = 0;
		for (int i = 1; i < newSides; i++)
			if (newSideLengths[i] > newSideLengths[heightestIndex])
				heightestIndex = i;
		return heightestIndex;
	}

	
	


	//this function is used to validate a triangle. If the largest side is largest than the sum of the two other sides, the triangle is not valid
	bool validateTriangle(vector<float> newSideLengths) {
		int indexOfLargestSide = largestSideIndex(newSideLengths, sides);
		if (newSideLengths[indexOfLargestSide] > ((newSideLengths[(indexOfLargestSide + 1) % newSideLengths.size()]) + (newSideLengths[(indexOfLargestSide + 2) % newSideLengths.size()])))
			return false;
		return true;

	}
	//this function is used to validate that the rectangle being created is valid
	
	bool validateRectangle(float newSideLengths[], float& width, float& height, int newSides) {
		width = newSideLengths[0], height = newSideLengths[0];
		for (int i = 1; i < newSides - 1; i++)
			if (newSideLengths[i] != width) {
				height = newSideLengths[i];
				break;
			}
		return validateRectangle(newSideLengths, newSides);
	}

	//this function is used to validate that a an array of sides represents a rectangle
	static bool validateRectangle(float newSideLengths[], int newSides) {
		float width = newSideLengths[0], height = -1;
		for (int i = 1; i < newSides - 1; i++)
			if (newSideLengths[i] != width) {
				height = newSideLengths[i];
				break;
			}
		if (count(newSideLengths, newSides, width) == 2 && count(newSideLengths, newSides, height) == 2)
			return true;
		return false;
	}

	//this function is used to validate that the rectangle being created is valid
	bool validateRectangle(vector<float> newSideLengths) {
		float width = newSideLengths[0], height = -1;
		for (int i = 1; i < sides - 1; i++)
			if (newSideLengths[i] != width) {
				height = newSideLengths[i];
				break;
			}
		if (count(newSideLengths, sides, width) == 2 && count(newSideLengths, sides, height) == 2)
			return true;
		return false;
	}
	//this function is used to find out if a polygon is an isosceles triangle
	bool isIsoTriangle(vector<float> newSideLengths) {
		if (newSideLengths.size() != 3)
			return false;
		if (equalSides(newSideLengths))
			return false;
		if (newSideLengths[0] != newSideLengths[1] && newSideLengths[0] != newSideLengths[2]   && newSideLengths[1] != newSideLengths[2])
			return false;
		return true;
	}

	//this method returns the highest value in a float vector. This will be used to return the hypotenuse of a right triangle
	int cIndex(vector<float> newSideLengths) {
		int heightestIndex = 0;
		for (int i = 1; i < sides; i++)
			if (newSideLengths[i] > newSideLengths[heightestIndex])
				heightestIndex = i;
		return heightestIndex;
	}

	//this method is used to validate if a polygon is a right triangle
	bool isRightTriangle(vector<float> newSideLengths) {
		int indexOfC = cIndex(newSideLengths);
		if (newSideLengths.size() != 3)
			return false;
		if (equalSides(newSideLengths))
			return false;
		if ((pow(newSideLengths[(indexOfC + 1) % sides], 2) + pow(newSideLengths[(indexOfC + 2) % sides], 2)) != pow(newSideLengths[indexOfC], 2))
			return false;
		return true;
	}


	/*
	 * I will use the below functions to format my numbers
	 */

	 //this function is used to print the vertices
	string verticesToString(vector<vector<float>> newVertices) {
		string sides = "";
		for (int i = 0; i < newVertices.size(); i++)
			sides += ("(" + formatNum(newVertices[i][0]) + ", " + formatNum(newVertices[i][1]) + ")" + ((i < (newVertices.size() - 1)) ? ", " : ""));
		return sides;
	}

	//this functions splits a string of a float into an array with the numbers before and after the decimal point
	void split(string result[2], string data, char tar) {
		int prevEnd = 0;
		for (int i = 0; i < data.length(); i++)
			if (data[i] == tar) {
				result[0] = data.substr(prevEnd, i);
				prevEnd = i + 1;
				break;
			}
		result[1] = data.substr(prevEnd, data.length());
	}
	// this function returns a float value as a string with two decimal points
	string formatNum(float val) {
		string splitVal[2];
		split(splitVal, to_string(val), '.');
		return splitVal[0] + "." + splitVal[1].substr(0, 2);
	}
	//i use this method to convert the side lengths vector into a string
	string sidesToString(vector<float> newSideLengths) {
		string sides = "";
		for (int i = 0; i < newSideLengths.size(); i++)
			sides += (formatNum(newSideLengths[i]) + ( (i < (newSideLengths.size()-1) ) ? ", " : ""));
		return sides;
	}

	

	//getters and setters
	void isVertexDefined() {
		vertexDefined = true;
	}
	string getName() {
		return name;
	}
	int getSides() {
		return sides;
	}
	vector<float> getSideLengths() {
		return sideLengths;
	}
	float getPerimeter() {
		return perimeterVal;
	}
	float getArea() {
		return areaVal;
	}
	void setArea(float newArea) {
		areaVal = newArea;
	}

	vector<vector<float>> getPolyVertices() {
		return polyVertices;
	}

	void setSideLengths(float newSideLengths[], int newSides) {
		for (int i = 0; i < newSides; i++)
			sideLengths.push_back(newSideLengths[i]);
	}
	void setVertices(float vertices[][2], int newSides) {
		for (int i = 0; i < newSides; i++) {
			vector<float> coordinates{ vertices[i][0], vertices[i][1] };
			polyVertices.push_back(coordinates);
		}
	}
	void setName(string newName) {
		name = newName;
	}
	void setName(int newSides) { //THIS NAME SETTER USES THE NUMBER OF SIDES INSTEAD OF A STRING VALUE
		if (newSides == 3) {
			if (equalSides(sideLengths))
				name = "Equilateral Triangle";
			else if (isIsoTriangle(sideLengths))
				name = "Isosceles Triangle";
			else if (isRightTriangle(sideLengths))
				name = "Right Triangle";
			else if (validateTriangle(sideLengths))
				name = "Triangle";
			else
				name = "Invalid Triangle";
			
		} else if (newSides == 4) {
			if (equalSides(sideLengths))
				name = "Square";
			else if (validateRectangle(sideLengths)) //WE WILL ASSUME IT IS A RECTANGLE INSTEAD OF A PARALLELOGRAM IF IT IS CONSTRUCTED USING THE SIDE LENGTHS (SINCE WE DO NOT HAVE ENOUGH INFORMATION)
				name = "Rectangle";
			else
				name = "Quadrilateral";
		}else
			name = "Polygon";
	}
	void setPerimeter(float newPerimeter) {
		perimeterVal = newPerimeter;
	}
	void setSides(int newSides) {
		sides = newSides;
	}

	
};

//the print function
void Polygon::printPolygon() {
	string polyName = getName();
	cout << "The following is " << ( ( char( tolower(polyName.at(0) ) ) == 'a' || char(tolower(polyName.at(0))) == 'e' || char(tolower(polyName.at(0)) ) == 'i' || char (tolower(polyName.at(0)) ) == 'o' || char(tolower(polyName.at(0))) == 'u') ? "an " : "a ") << name << endl;
	cout << "\tNumber of sides: " << getSides() << endl;
	cout << "\tThe Side Lengths: " << sidesToString(getSideLengths()) << endl;
	if (vertexDefined) cout << "\tVertices: " << verticesToString(getPolyVertices()) << endl;
	cout << "\tPerimeter: " << getPerimeter() << endl;
	if(areaVal != -1) cout << "\tArea: " << formatNum(getArea()) << endl;
}