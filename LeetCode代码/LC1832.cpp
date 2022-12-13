#include <iostream>
#include <set>

using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        std::set<char> s;
        int length = sentence.size();
        for (int i = 0; i < length; i++)
        {
            s.insert(sentence[i]);
        }
        if (s.size() == 26)
            return true;
        else
            return false;
    }
};

int main(){
    string str="abcdefghijkll";
    Solution sol;
    bool flag=sol.checkIfPangram(str);
    cout<<flag<<endl;
    return 0;
}