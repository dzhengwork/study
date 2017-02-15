#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

    int lengthLongestPath(string input) {

        vector<int> levelV(200);

        levelV[0] = 0;

        int maxlen = 0;

        string line;

        stringstream ss(input);

        while(getline(ss, line, '\n')) {

            // count \t

            int depth = 0;

            for (int i=0; i<line.size(); i++){

                if(line[i] == '\t') depth++;

            }

            int len = line.size() - depth;

            if (line.find('.')) {

                maxlen = max(maxlen, int(levelV[depth] + len));

            }

            else {

                levelV[depth+1] = int(levelV[depth] + len + 1);

            }

        }

        return maxlen;

}

int main()
{
    string a = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    int ret = lengthLongestPath(a);
    cout << ret << endl;
    return 0;
}
