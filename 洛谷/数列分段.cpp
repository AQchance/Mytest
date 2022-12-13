#include<bits/stdc++.h>

using namespace std;

int main()
{
    int left=0,right=0,mid,sum;
    int ans,i,m,n,cnt;
    int a[100010]={0};
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(left<a[i]) left=a[i];
        right+=a[i];
    }
    while(left<=right){
        cnt=1;
        mid=(left+right)/2;
        for(i=0,sum=0;i<n;i++){
            if(sum+a[i]<mid){
                sum+=a[i];
            }
            else if(sum+a[i]==mid){
                sum=0;
                if(i+1<n) cnt++;
            }
            else{
                sum=a[i];
                cnt++;
            }
        }
        if(cnt>m) left=mid+1;
        else {
            ans=mid;
            right=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}