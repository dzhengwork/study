#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool is_palindrome(string const& s)
{
	string str = s;
	for(auto & c : str) {
		c = toupper(c);
	}
	return equal(str.begin(), str.end(), str.rbegin());
}

int main()
{
	string str;
	cout << "enter string: ";
	getline(cin, str);
	if (is_palindrome(str)){
		cout << str << " is a palindrome" << endl;
	}
	else {
		cout << str << " is not a palindrome" << endl;
	}
	return 0;
}
