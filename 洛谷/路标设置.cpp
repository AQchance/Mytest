#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ans,l,n,k,a[100003]={0},i,left,right,mid,cnt,now;
    cin>>l>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=l;
    left=0,right=l;
    while(left<=right){
        cnt=0;
        mid=(left+right)/2;
        if(mid==0){
            cout<<1<<endl;
            return 0;
        }
        for(i=1,now=0;i<=n+1;i++){
            if(a[i]-a[now]>mid){
                cnt+=(a[i]-a[now])/mid;
                if((a[i]-a[now])%mid==0) cnt--;
                now=i;
            }
            else now=i;
        }
        if(cnt>k){
            left=mid+1;
        }
        else{
            ans=mid;
            right=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}