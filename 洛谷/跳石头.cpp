#include<bits/stdc++.h>

using namespace std;

int main()
{
    int l,n,m,a[50005]={0},now,i,left,right,mid,cnt,ans;
    cin>>l>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=l;
    left=0,right=l;
    while(left<=right){
        cnt=0;
        mid=(left+right)/2;
        for(i=1,now=0;i<=n+1;i++){
            if(a[i]-a[now]<mid){
                cnt++;
                continue;
            }
            else{
                now=i;
            }
        }
        if(cnt>m) right=mid-1;
        else {
            ans=mid;
            left=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
    