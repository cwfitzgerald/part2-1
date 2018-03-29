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

// this doesn't do the thing that the thing it says it does is supposed to have it do with the thing it is supposed to
// do it withs
// std::string dedent_OLD(istream& program) {
// 	std::string ret;

// 	bool newline = true;
// 	for (char c : line) {
// 		if (newline && std::isspace(c) != 0) {
// 		}
// 		else if (c == '\n') {
// 			newline = true;
// 			ret.push_back(c);
// 		}
// 		else {
// 			newline = false;
// 			ret.push_back(c);
// 		}
// 	}
// 	return ret;
// }

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

	std::cout << dedent(line);
	return 0;
}
