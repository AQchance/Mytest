#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a,y,x,mid,left=0,right=5,ans;
    int i,n;
    cin>>x>>y>>n;
    while(right-left>=0.00001){
        a=x;
        mid=(left+right)/2;
        for(i=0;i<n;i++){
            a=a*(1+mid)-y;
        }
        if(a==0){
            printf("%.1lf\n",mid*100);
            return 0;
        }
        if(a<0) left=mid;
        else{
            ans=mid;
            right=mid;
        } 
    }
    printf("%.1lf\n",ans*100);
    return 0;
}