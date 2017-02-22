#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    string b;
    cout << "first: ";
    cin >> a;
    
    cout << "second: ";
    cin >> b;

    int first[26] = {0};
    int second[26] = {0};
    
    for(int i=0; i<a.size(); i++){
        first[a[i]-'a'] ++;
    }
    for(int i=0; i<b.size(); i++){
        second[b[i]-'a'] ++;
    }

    bool t = true;
    for(int i=0; i<26; i++) {
        if(first[i] != second[i]) {
            t = false;
            break;
        }
    }

    if(t) cout << "True" << endl;
    else cout << "False" << endl;
    
    return 0;
}

