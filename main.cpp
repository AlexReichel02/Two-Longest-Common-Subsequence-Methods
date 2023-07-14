/***************************************************************
  Student Name: Alex Reichel
  File Name: main.cpp
  Assignment number Project 05

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/
#include <iostream>
#include "LCSMethodOne.hpp"
#include "LCSMethodTwo.hpp"
using namespace std;

int main() {

	LCSMethodOne firstMethod;
	LCSMethodTwo secondMethod;
	firstMethod.readFile();
	firstMethod.convert();

	secondMethod.readFile();
	secondMethod.directAccess();
	secondMethod.printTable();
	cout<<endl;

	return 0;
}
