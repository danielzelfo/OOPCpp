/*
* Author: Daniel Zelfo
* Class: CSCI 140
* Program: Huge Integers
* Date: 11/20/2019
* Descrip/ion: This program includes a HugeInt class which encapsulates an integer that can be over 32 bits. 
* 			   The HugeInt class can do mathematical operations on huge integers, compare them, and output them.
*/

#include "HugeInt.hpp"

void outputOperations(HugeInt*, HugeInt*);

void hugeIntegerMain()
{
	HugeInt *A = new HugeInt(123);
	HugeInt *B = new HugeInt(999);

	outputOperations(A, B);

	delete A; delete B;
	A = new HugeInt("12345654321");
	B = new HugeInt(111);

	outputOperations(A, B);

	delete A; delete B;
	A = new HugeInt("11111111114444444444");
	B = new HugeInt(222);

	outputOperations(A, B);

	delete A; delete B;
	A = new HugeInt("99999999991111111111888888888822222222225555555555");
	B = new HugeInt("22222222228888888888444444444477777777776666666666");
	
	outputOperations(A, B);
}

void outputOperations(HugeInt* A, HugeInt* B) {
	cout << *A << " + " << *B << " = ";
	try { cout << *A + *B << endl; } catch(string err) { cerr << err << endl; }
	cout << *A << " - " << *B << " = " << *A - *B << endl;
	cout << *A << " * " << *B << " = ";
	try { cout << *A * *B << endl; } catch(string err) { cerr << err << endl; }
	cout << *A << " / " << *B << " = " << *A / *B << endl;
	cout << boolalpha << *A << " == " << *B << " ? " << (*A == *B) << "\n\n";
}