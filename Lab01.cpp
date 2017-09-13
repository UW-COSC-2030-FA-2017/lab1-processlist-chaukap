// Lab01.cpp 
// Chandler Haukap
// COSC 2030 Fall 17

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<fstream>
using std::ifstream;

#include<string>
using std::string;
using std::getline;

void printResults(double num1, double num2, double num3, double num4, int counter)
{
	cout << "This file contained " << counter;  //every outcome should print this
	if (counter == 0)
	{
		cout << " numbers." << endl;
	}
	else if (counter == 1)
	{
		cout << " number: " << num1 << endl;
	}
	else if (counter == 2)
	{
		cout << " numbers: " << num1 << " and " << num2 << " (in that order)" << endl;
	}
	else if (counter == 3)
	{
		cout << " numbers: " << num1 << "," << num2 << "," << num3 << " (in that order)" << endl;
	}
	else if (counter == 4)
	{
		cout << " numbers: " << num1 << "," << num2 << "," << num3 << "," << num4 << " (in that order)" << endl;
	}
	else
	{
		cout << " numbers. " << endl << "The first two are " << num1 << " and " << num2 << "." << endl
			<< "And the last two are " << num3 << " and " << num4 << "." << endl;
	}
	return;
}


int main()
{
	string fileName;
	ifstream inFile; //the file we will read from
	double num1(0), num2(0), num3(0), num4(0), number; //store the numbers (num1 num2...) and a temporary double called number
	int counter(0);  //records how many numbers have been read

	while (!(inFile.is_open())) //make sure a file is opened
	{
		cout << "Enter file name: " << endl;
		getline(cin, fileName);
		inFile.open(fileName);
	}
	
	while (!(inFile.eof()))
	{
		if (!(inFile >> number)) //If a double cannot be read.
		{
			inFile.clear(); //clear the error
			inFile.ignore(); //ignore that character
		}
		else //if a double was read.
		{
			if (counter == 0) //if no numbers have been recorded
			{
				num1 = number; //save the first one as num1
			}
			else if(counter == 1) //if one other number has been recorded
			{
				num2 = number; //save the second number as num2
			}
			else //will save the rest of the numbers until we reach the end of the file
			{
				num3 = num4; //push the numbers back one
				num4 = number; //this will give me the last 2 numbers
			} //the above block WILL NOT behave if there are 3 numbers in the file. Solution to this below.
			counter++;
		}
	}
	if (counter == 3) //The latest number is stored as num4, therefore num3 will not be assigned if 3 numbers are in the file.
	{
		num3 = num4;
	}

	printResults(num1, num2, num3, num4, counter);

	return 0;
}



