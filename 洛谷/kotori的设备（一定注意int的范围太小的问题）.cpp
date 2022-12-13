#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,n,p;
    long sum=0;
    int a[200000]={0},b[200000]={0};
    double maxtime=1e11,mintime=0,midtime,s,ans;
    cin>>n>>p;
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    if(sum<=p){
        cout<<-1<<endl;
        return 0;
    }
    while(maxtime-mintime>0.000001){
        midtime=(mintime+maxtime)/2;
        s=0;
        for(i=0;i<n;i++){
            if(b[i]<a[i]*midtime) s+=(a[i]*midtime-b[i]);
        }
        if(midtime*p<s){
            maxtime=midtime;
        }
        else {
            mintime=midtime;
        }
    }
    cout<<mintime<<endl;
    return 0;
}