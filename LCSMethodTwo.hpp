/***************************************************************
  Student Name: Alex Reichel
  File Name: LCSMethodTwo.hpp
  Assignment number Project 05

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/
#ifndef LCSMETHODTWO_HPP_
#define LCSMETHODTWO_HPP_
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

const int POSLEN = 20;
const int LINELEN = 120;

class LCSMethodTwo {

public:

	/**
	Empty Constructor
	*/
	LCSMethodTwo();

	/**
	Function that reads and extracts data from file
	*/
	void readFile();

	/**
	function used to directly access words from file
	*/
	void directAccess();

	/**
		Function that prints the LCS
		@param int size of array
		@param int size of array
		@param char* represents first word
		@param char* represents second word
		@param int represents index of array
		@param int represents index of array
		*/
	void lcs(char* X, char* Y, int m, int n,int i,int j);

	/**
	Function used to print the table
	*/
	void printTable();

	/**
		Function used to fill the table
		@param int represents index of array
		@param int represents index of array
		@param char* represents element to be placed in table
		*/
	void fillTable(int i,int j, char temp);


	/**
	Vector containing all strings
	*/
	vector<string> stringHolder;

	/**
	2D char array represneting table
	*/
	char game[8][8]={' '};

	/**
	int array of positions
	*/
	int positions[POSLEN];

	/**
	int representing total strings
	*/
	int totStrings = 0;

	virtual ~LCSMethodTwo();
};

#endif /* LCSMETHODTWO_HPP_ */
