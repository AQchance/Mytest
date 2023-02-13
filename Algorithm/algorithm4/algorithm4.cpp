#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <streambuf>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

const int MAX_CHAR_ASCLL = 255;
int shift[MAX_CHAR_ASCLL];
// Sunday算法的实现
int Sunday(const string &thestring, const string &mystring)
{
    int length1 = thestring.size();
    int length2 = mystring.size();
    for (int i = 0; i < MAX_CHAR_ASCLL; i++)
    {
        shift[i] = length2 + 1;
    }
    for (int i = 0; i < length2; i++)
    {
        shift[mystring[i]] = length2 - i;
    }
    int i = 0;
    int j;
    while (i <= length1 - length2)
    {
        j = 0;
        while (thestring[i + j] == mystring[j])
        {
            j++;
            if (j >= length2)
                return i;
        }
        i += shift[thestring[i + length2]];
    }
    return -1;
}

int calculate_index(int k, string txt)
{
    if (k == -1)
        return -1;
    int j = 1;
    for (int i = 0; i <= k; i++)
    {
        if (txt[i] == ' ')
            j++;
    }
    return j;
}

// 使用更加高效的Sunday算法来进行模式匹配
int main()
{
    std::ifstream in("C:\\Users\\lenovo\\Desktop\\message.txt");
    string txt((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    string mystring;
    while (1)
    {
        getline(cin, mystring);
        if (mystring == "-1")
            return 0;
        int k = Sunday(txt, mystring);
        k = calculate_index(k, txt);
        cout << k << "  " << mystring << endl;
    }
    return 0;
}