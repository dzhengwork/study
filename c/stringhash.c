#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int main() {
    unsigned long num = 0;
    string a;
    cin >> a;
    int i = 0;
    while ( num < ULONG_MAX && i < a.length()) {
        num = num << 8;
        num += a.c_str()[i++];
    }

    cout << num << endl;
    return 0;
}
