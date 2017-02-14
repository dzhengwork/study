#include <iostream>

using namespace std;
int main()
{
	cout << "size: ";
	int num;
	cin >> num;
	for (int i=0; i<num; i++) {
		for (int c=0; c<(i+1); c++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
	for (int i=0; i<num; i++) {
		for (int c=0; c<(num-i); c++) {
			cout << " ";
		}
		for (int c=0; c<(i+1); c++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
	for (int i=0; i<num; i++) {
		for (int c=0; c<(num-i); c++) {
			cout << " ";
		}
		for (int c=0; c<(i*2+1); c++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
