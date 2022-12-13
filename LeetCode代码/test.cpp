#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main()
{
    std::vector<int> a(26);
    for(int i=0;i<26;i++){
        a[i]=i;
    }
    cout<<a[25]<<endl;
    return 0;
}