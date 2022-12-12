#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,n,a[100000]={0},b[100000]={0};
    cin>>m>>n;
    int i,j,left,right,mid;
    long sum=0;
    for(i=0;i<m;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a,a+m);
    for(i=0;i<n;i++){
        left=0;
        right=m-1;
        while(left<right){
            mid=(left+right)/2;
            if(b[i]<a[mid]) right=mid;
            else left=mid+1;
        }
        if(m==1){
            sum+=abs(a[left]-b[i]);
        }
        else{
            if(left==0){
                sum+=min(abs(a[left]-b[i]),abs(a[left+1]-b[i]));
            }
            else if(left==n-1){
                sum+=min(abs(a[left]-b[i]),abs(a[left-1]-b[i]));
            }
            else{
                j=min(abs(a[left]-b[i]),abs(a[left-1]-b[i]));
                sum+=min(j,abs(a[left+1]-b[i]));
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}