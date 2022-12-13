#include<bits/stdc++.h>

using namespace std;

typedef struct SNumber{
    int a;
    int b;
}Number;

bool cmp(Number a,Number b){
    return a.a<b.a;
}

int main()
{
    int n,i,j;
    Number number[1001];
    double sum=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>number[i].a;
        number[i].b=i+1;
    }
    sort(number,number+n,cmp);
    for(i=0;i<n;i++){
        cout<<number[i].b<<" ";
    }
    cout<<endl;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            sum+=number[j].a;
        }
    }
    sum/=n;
    printf("%.2lf\n",sum);
    return 0;
}