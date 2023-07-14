/***************************************************************
  Student Name: Alex Reichel
  File Name: LCSMethodOne.cpp
  Assignment number Project 05

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "LCSMethodOne.hpp"

LCSMethodOne::LCSMethodOne() {
	// TODO Auto-generated constructor stub

}

void LCSMethodOne::readFile(){
			cout<<"Implementing First Algorithm"<<endl;
	        ifstream inFile;
	        string testString;
	        lcsSize=0;
			inFile.open("twoStrings.txt");

			if(!inFile){
			  cout<<"unable to open"<<endl;
		     }else{


			while(inFile >> testString){
				stringHolder.push_back(testString);


			}
			inFile.close();

}
}

void LCSMethodOne::convert(){
	string firstWord = stringHolder[0];
	int firstWordSize = firstWord.length();
	char firstWordArray[firstWordSize + 1];
	strcpy(firstWordArray, firstWord.c_str());
	wordOne = firstWordArray;


	string secondWord = stringHolder[1];
	int secondWordSize = secondWord.length();
    char secondWordArray[secondWordSize + 1];
	strcpy(secondWordArray, secondWord.c_str());
	wordTwo = secondWordArray;

	lcs(wordOne,wordTwo,firstWordSize,secondWordSize);

	cout<<endl;
}


void LCSMethodOne::lcs(char* X, char* Y, int m, int n)
{
    int array[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                array[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                array[i][j] = array[i - 1][j - 1] + 1;
            else
                array[i][j] = max(array[i - 1][j], array[i][j - 1]);
        }
    }


    int index = array[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {

        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1]
                = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (array[i - 1][j] > array[i][j - 1])
            i--;
        else
            j--;
    }


    cout<<"First word: " << X <<endl;
    cout<<"Second word: " << Y <<endl;
    cout << "Longest common subsequence  is " << lcs<<endl;
    int lcsSize = strlen(lcs);
    cout<<"Size of LCS is: " << lcsSize << endl;
}


LCSMethodOne::~LCSMethodOne() {
	// TODO Auto-generated destructor stub
}

