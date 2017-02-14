#include <iostream>
#include <sstream>
#include <string>

using namespace std;

long factoral(long a)
{
	if (a > 1) {
		return (a * factoral(a - 1));
	}
	else {
		return 1;
	}
}

int main()
{
	long num;
	string str;
	cout << "Enter number: ";
	getline (cin, str);
	stringstream(str) >> num;
	cout << "Factoral of " << num << "! = " << factoral(num) << endl;
	return 0;
}
