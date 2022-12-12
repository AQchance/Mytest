#include <bits/stdc++.h>

using namespace std;

const int N=100;

void sort(int a[]){
    for(int i=1;i<N;i++){
        for(int j=i;j>0&&a[j]<a[j-1];j--){
            swap(a[j],a[j-1]);
        }
    }
}

int main()
{
    int a[N];
    for(int i=0;i<N;i++){
        a[i]=i;
    }
    sort(a);
    for(int i=0;i<N;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
