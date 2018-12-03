// Main.cpp
// Jordan Pierson
// COSC 2030 Fall 2018
// Lab 09 Driver File

#include <iostream>
#include<map>
#include<fstream>
#include<string>
using std::string;
using std::map;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;


int main()
{
	cout << "Type in a text file name: " << endl;
	string file, word;
	cin >> file;
	ifstream myfile;
	myfile.open(file);
	map<string, int> myMap;
	// Code below taken from cplusplus.cvom/doc/tutorial/files/
	if (myfile.is_open())
	{
		int index = 0;
		while (myfile >> word)
		{
			++myMap[word];
		}
		myfile.close();
	}
	else cout << "Unable to open file";


	ofstream outfile("output.txt");
	// Code below taken from http://www.cplusplus.com/reference/map/map/begin/
	for (std::map<string, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
	{
		for (int i = 0; i < it->second; i++)
		{
			outfile << it->first;
		}
	}
	cout << "output.txt now contains the info from the map" << endl;

	outfile.close();
	system("pause");
	return 0;
}