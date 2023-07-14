/***************************************************************
  Student Name: Alex Reichel
  File Name: LCSMethodOne.hpp
  Assignment number Project 05

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#ifndef LCSMETHODONE_HPP_
#define LCSMETHODONE_HPP_
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class LCSMethodOne {
public:

	/**
	Basic empty constructor
	*/
	LCSMethodOne();

	/**
	Function use to convert strings into char pointer
	*/
	void convert();

	/**
	Function that prints the LCS
	@param int size of array
	@param int size of array
	@param char* represents first word
	@param char* represents second word
	*/
	void lcs(char* X, char* Y, int m, int n);

	/**
	Function that reads and extracts data from file
	*/
	void readFile();


	/**
	Size of LCS
	*/
	int lcsSize;

	/**
	Vector of the two strings
	*/
	vector<string> stringHolder;

	/**
	Char pointer representing first word
	*/
	char *wordOne;

	/**
	Char pointer representing second word
	*/
	char *wordTwo;

	virtual ~LCSMethodOne();
};

#endif /* LCSMETHODONE_HPP_ */
