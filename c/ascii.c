#include <iostream>

using namespace std;

int main()
{
	const char *a = "aaa";
	char b[] = "bbb";
	int foo;
	decltype(foo) bar;
	string str;
	cout << "Enter string: ";
	cin >> str;
	for ( auto c : str ) {
		cout << c << "[" << int(c) << "]";
	}
	cout << endl;
	return 0;
}
