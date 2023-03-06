#include <iostream>
#include <iomanip>
#include <fstream>

#include <strstream>

using namespace std;

int main()
{
    int a = 1024;
    double b = 3.1415926535;
    cout << setbase(16) << a << endl;
    cout.setf(ios::hex);
    cout << a << endl;
    cout << setprecision(6) << b << endl;


    ofstream outfile;
    outfile.open("data.dat", ios::out);
    ofstream outfile1("data.dat", ios::out);

    char ch[90];
    istrstream instr(ch, sizeof(ch));
    string mystr = "newbingdslakjmdklasdlas";
    instr>>mystr;
    cout<<ch<<endl;

    return 0;
}