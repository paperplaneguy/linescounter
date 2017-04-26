#include <iostream> //for std::cout, std::endl
#include <fstream>  //for std::ifstream
#include <vector>   //for std::vector
#include <string>   //for std::string, std::getline
#include <cstdint>  //for uint32_t

using std::cout; using std::endl; using std::ifstream;

uint32_t lineCount(char* filename) {
	ifstream file(filename);
	uint32_t count(0); std::string temp;
	while(std::getline(file, temp)) count++;
	return count;
}
	

int main(int argc, char **argv) {
	//if there are no arguments passed, show an error and exit.
	if (argc == 1) cout << "No arguments passed." << endl;
	else if (argc > 1) {
		//convert the c-style string array into a vector of c-style arrays.
		std::vector<char*> filenames(argv + 1, argv + argc);
		//for every filename
		for (char* filename: filenames) {
			cout << "The file \"" << filename << "\" ";
			//cehck if the filename is valid.
			if(ifstream(filename).good())
				//if it is valid, print out the lines count.
				cout << "contains " << lineCount(filename) << " lines.";
			//if it isn't let the users know.
			else cout << "wasn't found.";
			cout << endl;
		}
	}
	return 0;
}
