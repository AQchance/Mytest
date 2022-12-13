#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    int *a=new int[N];
    for(int i=0;i<N;i++){
	cin>>a[i];
    }
    for(int i=0;i<M;i++){
	next_permutation(a,a+N);
    }
    for(int i=0;i<N;i++){
	cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
