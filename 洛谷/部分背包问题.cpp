#include <bits/stdc++.h>

using namespace std;

typedef struct SNumber{
    double v;
    double m;
}Number;

bool cmp(Number a,Number b){
    return a.v/a.m>b.v/b.m;
}

int main()
{
    int i,n;
    double t,sum=0;
    Number number[100];
    cin>>n>>t;
    for(i=0;i<n;i++){
        cin>>number[i].m>>number[i].v;
    }
    sort(number,number+n,cmp);
    i=0;
    while(t>0&&i<n){
        if(t>=number[i].m){
            sum+=number[i].v;
            t-=number[i].m;
        }
        else{
            sum+=t*number[i].v/number[i].m;
            t=0;
        }
        i++; 
    }
    printf("%.2lf\n",sum);
    return 0;
}