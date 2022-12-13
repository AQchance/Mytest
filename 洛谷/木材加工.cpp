#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,l,k,n,sum=0;
    int maxlen=0,minlen=0;
    int a[100000]={0};
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        if(maxlen<a[i]) maxlen=a[i];
    }
    while(minlen<maxlen){
        sum=0;
        l=(minlen+maxlen)/2;
        if(maxlen-minlen==1){
            if(l==0){
                for(sum=0,i=0;i<n;i++){
                    sum+=a[i];
                }
                if(sum>=k) cout<<1<<endl;
                else cout<<0<<endl;
            }
            else{
                for(sum=0,i=0;i<n;i++){
                    sum+=a[i]/(l+1);
                }
                if(sum>=k) cout<<l+1<<endl;
                else cout<<l<<endl;
            }
            return 0;
        }
        for(sum=0,i=0;i<n;i++){
            sum+=a[i]/l;
        }
        if(sum>=k) minlen=l;
        else maxlen=l;
    }
    return 0;
}