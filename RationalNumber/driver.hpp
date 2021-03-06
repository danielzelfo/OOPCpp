/*
* Author: Daniel Zelfo
* Class: CSCI 140
* Program: Rational Numbers
* Date: 11/20/2019
* Description: This program includes a RationalNumber class which encapsulates a rational number.
* 			   The RationalNumber class can reduce fractions. It can also add, subtract, multiply, and divide rational numbers expressed as fractions.
*/

#include "RationalNumber.hpp"
#include <vector>

/*

TEST CASES

Numerator = 4, Denominator = 14
Numerator = 4, Denominator =  0
Numerator = 4, Denominator =-14
Numerator =-4, Denominator =-14
Numerator = 2, Denominator =  3

Test the constructor, overloded +, -, *, /, <, >, <=,>=, ==, !=.

*/
void rationalNumberMain()
{
	//a vector of ratioan numbers for testing
	vector<RationalNumber*> rationalNumbers;

	cout << "Original values: \n\t4/14, 4/0, 4/-14, -4/-14, 2/3\n";

	//populating the vector of rational numbers and catching any exceptions
	try { rationalNumbers.push_back(new RationalNumber(4, 14)); }
	catch (string err) { cerr << err << endl; }
	try { rationalNumbers.push_back(new RationalNumber(4, 0)); }
	catch (string err) { cerr << err << endl; }
	try { rationalNumbers.push_back(new RationalNumber(4, -14)); }
	catch (string err) { cerr << err << endl; }
	try { rationalNumbers.push_back(new RationalNumber(-4, -14)); }
	catch (string err) { cerr << err << endl; }
	try { rationalNumbers.push_back(new RationalNumber(2, 3)); }
	catch (string err) { cerr << err << endl; }

	//testing all the operations on all the rational number objects in the vector
	RationalNumber result;
	for (int i = 0; i < rationalNumbers.size(); ++i) {
		rationalNumbers[i]->printRational();
		cout << "\n\t";

		result = *rationalNumbers[i] + *rationalNumbers[(i + 1) % rationalNumbers.size()];
		rationalNumbers[i]->printRational();
		cout << " + ";
		rationalNumbers[(i + 1) % rationalNumbers.size()]->printRational();
		cout << " = ";
		result.printRational();
		cout << "\n\t";

		result = *rationalNumbers[i] - *rationalNumbers[(i + 1) % rationalNumbers.size()];
		rationalNumbers[i]->printRational();
		cout << " - ";
		rationalNumbers[(i + 1) % rationalNumbers.size()]->printRational();
		cout << " = ";
		result.printRational();
		cout << "\n\t";

		result = *rationalNumbers[i] * *rationalNumbers[(i + 1) % rationalNumbers.size()];
		rationalNumbers[i]->printRational();
		cout << " * ";
		rationalNumbers[(i + 1) % rationalNumbers.size()]->printRational();
		cout << " = ";
		result.printRational();
		cout << "\n\t";

		result = *rationalNumbers[i] / *rationalNumbers[(i + 1) % rationalNumbers.size()];
		rationalNumbers[i]->printRational();
		cout << " / ";
		rationalNumbers[(i + 1) % rationalNumbers.size()]->printRational();
		cout << " = ";
		result.printRational();
		cout << "\n\t";

		rationalNumbers[i]->printRational();
		cout << " < ";
		rationalNumbers[(i + 1) % rationalNumbers.size()]->printRational();
		cout << " ? ";
		cout << boolalpha << (*rationalNumbers[i] < *rationalNumbers[(i + 1) % rationalNumbers.size()]);
		cout << "\n\t";

		rationalNumbers[i]->printRational();
		cout << " > ";
		rationalNumbers[(i + 1) % rationalNumbers.size()]->printRational();
		cout << " ? ";
		cout << (*rationalNumbers[i] > *rationalNumbers[(i + 1) % rationalNumbers.size()]);
		cout << "\n\t";

		rationalNumbers[i]->printRational();
		cout << " <= ";
		rationalNumbers[(i + 1) % rationalNumbers.size()]->printRational();
		cout << " ? ";
		cout << (*rationalNumbers[i] <= *rationalNumbers[(i + 1) % rationalNumbers.size()]);
		cout << "\n\t";

		rationalNumbers[i]->printRational();
		cout << " >= ";
		rationalNumbers[(i + 1) % rationalNumbers.size()]->printRational();
		cout << " ? ";
		cout << (*rationalNumbers[i] >= *rationalNumbers[(i + 1) % rationalNumbers.size()]);
		cout << "\n\t";

		rationalNumbers[i]->printRational();
		cout << " == ";
		rationalNumbers[(i + 1) % rationalNumbers.size()]->printRational();
		cout << " ? ";
		cout << (*rationalNumbers[i] == *rationalNumbers[(i + 1) % rationalNumbers.size()]);
		cout << "\n\t";

		rationalNumbers[i]->printRational();
		cout << " != ";
		rationalNumbers[(i + 1) % rationalNumbers.size()]->printRational();
		cout << " ? ";
		cout << (*rationalNumbers[i] != *rationalNumbers[(i + 1) % rationalNumbers.size()]);
		cout << "\n";
	}
}