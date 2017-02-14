#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int
main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "need one argument" << endl;
		return -1;
	}
	int num;
	stringstream(argv[1]) >> num;
	
	int c = num;
	int count = 0;
	while(c) {
		if (c & 0x1 == 1) count++;
		c = c >> 1;
	}
	cout << "number " << num << " has " << count << " bits set" << endl;
	return 0;

}
