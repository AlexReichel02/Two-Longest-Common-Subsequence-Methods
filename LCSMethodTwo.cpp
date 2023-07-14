/***************************************************************
  Student Name: Alex Reichel
  File Name: LCSMethodTwo.cpp
  Assignment number Project 05

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "LCSMethodTwo.hpp"

LCSMethodTwo::LCSMethodTwo() {
	// TODO Auto-generated constructor stub

}

void LCSMethodTwo::readFile(){
	  ifstream in;
	  char line[LINELEN];
	  cout<<"Implementing Second Algorithm"<<endl;
	  in.open("multiStrings.txt");
	  positions[0] = 0;
	  while(in.getline(line, LINELEN))
	  {
	    positions[totStrings] = strlen(line)+1;
	    positions[totStrings++];
	    line[strlen(line)] = '\0';
	    string temp(line);
	    stringHolder.push_back(temp);


	  }
	  in.close();
}


void LCSMethodTwo::directAccess()
{


   int i, j, currentPos = positions[0];
   char line[LINELEN];
   char *firstWord;
   char *otherWords;

   ifstream in;
   in.open("multiStrings.txt");
   in.seekg(currentPos);
   for(i = 1; i < totStrings-1; i++)
   {
     in.getline(line, LINELEN);
     line[strlen(line)] = '\0';

    firstWord = line;

    int n = stringHolder[i].length();


        char char_array[n + 1];

        strcpy(char_array, stringHolder[i].c_str());
        int m = strlen(char_array);


     for(j = i+1; j < totStrings; j++)
     {

       in.getline(line, LINELEN);
       line[strlen(line)] = '\0';
       otherWords = line;
       int otherSize = strlen(line);



      lcs(char_array,otherWords,m,otherSize,i,j);

     }
     currentPos += positions[i];
     in.seekg(currentPos);
   }


}

void LCSMethodTwo::lcs(char* X, char* Y, int m, int n,int indexX, int indexY)
{
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }


    int index = L[m][n];


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


        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    string str(X);
    string str2(Y);
    int firstSize = str.length();
    int secondSize = str2.length();
    int lcsSize = strlen(lcs);

   if(firstSize > secondSize){

	   	   double LCSpercent = (double)lcsSize / (double)secondSize;
		   double sizePercent = (double)secondSize /(double)firstSize;

		   if(LCSpercent >= 0.90 && sizePercent >= 0.90){

			   fillTable(indexX,indexY,'H');
		   }else if (sizePercent >= 0.80 && LCSpercent >= 0.80 ){

			   fillTable(indexX,indexY,'M');
		   }else if(sizePercent >= 0.50 && LCSpercent >= 0.50 ){

			   fillTable(indexX,indexY,'L');
		   }else{

			   fillTable(indexX,indexY,'D');
		   }


   }else{


	   double LCSpercent2 = (double)lcsSize / (double)firstSize;
	   double sizePercent2 = (double)firstSize /(double)secondSize;

	   if(LCSpercent2 >= 0.90 && sizePercent2 >= 0.90){

		   fillTable(indexX,indexY,'H');
	   }else if (sizePercent2 >= 0.80 && LCSpercent2 >= 0.80 ){

		   fillTable(indexX,indexY,'M');
	   }else if(sizePercent2 >= 0.50 && LCSpercent2 >= 0.50 ){

		   fillTable(indexX,indexY,'L');
	   }else{

		   fillTable(indexX,indexY,'D');
	   }

   }
}


void LCSMethodTwo::printTable(){
	cout<<"Strings: 1,2,3,4,5,6,7,8"<<endl;
	for(int i=0;i<8;i++){

		cout<<"String:" <<  i+1 << " ";

		for(int j=0;j<8;j++){


			if(game[i][j]!='D' && game[i][j]!='L' && game[i][j]!='M' && game[i][j]!='H' ){
				game[i][j] = '-';
			}
			cout<<game[i][j] << " ";
			}


		cout<<endl;
	}
}

void LCSMethodTwo::fillTable(int i,int j, char temp){
		i = i-1;
		j = j-1;
		game[i][j] = temp;


	}

LCSMethodTwo::~LCSMethodTwo() {
	// TODO Auto-generated destructor stub
}

