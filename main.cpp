#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string line)
// Takes one line of code as input, removes all leading spaces and tabs
{
	string n;
	int j;
	for (int i = 0; (unsigned) i < line.length(); i++)
		if (isspace(line[i]))
		{
			j = i;
			i = line.length();
		}

	return line.substr(j + 1);
}

int countChar(string line, char c)
// Counts given char
{
	int count = 0;
	for (char h : line)
		if (h == c)
			count++;
	return count;
}

void indent(ifstream& program)
{
	string test;
	getline(program, test);
	cout << test << "\n";
}

int main()
{
	ifstream fin("program");

	if (fin.fail())
	{
		cerr << "File cannot be opened for reading." << "\n";
		exit(1); //exit if fail
	}

	cout << removeLeadingSpaces(" o c e a n 	 m a n ") << "\n";
	cout << countChar("oceanman", 'n') << "\n";
	indent(fin);
	return 0;
}