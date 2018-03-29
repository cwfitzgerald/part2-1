#include "funcs.hpp"
#include <cctype>
#include <iostream>

// NO!
using namespace std;

// stop copying your variables everywhere
string removeLeadingSpaces(string line)
// Takes one line of code as input, removes all leading spaces and tabs
{
	// you don't use this
	string n;
	// initialize your values, what is line length is 0 and the for loop doesn't fire
	int j;
	// iterate using std::size_t
	for (int i = 0; (unsigned) i < line.length(); i++)
		if (isspace(line[i])) {
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
		// use brackets, GNU style will disagree, prevents misleading indentation
		if (h == c)
			count++;
	return count;
}

int main() {
	std::string line(std::istreambuf_iterator<char>(std::cin), {});
	// // You need to read this from std::cin

	// if (fin.fail()) {
	// 	cerr << "File cannot be opened for reading.\n";
	// 	// just return, you're in main.
	// 	exit(1); // exit if fail
	// }

	// there needs to be a way to both indent and dedent
	// cout << removeLeadingSpaces(" o c e a n 	 m a n ") << "\n";
	// cout << countChar("oceanman", 'n') << "\n";

	std::cout << redent(dedent(line));
	return 0;
}