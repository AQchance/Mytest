#include <bits/stdc++.h>

using namespace std;

int aux[100];

void merge(int a[],int low,int mid,int high){
    int i=low,j=mid+1;
    for(int k=low;k<=high;k++){
        aux[k]=a[k];
    }
    for(int k=low;k<=high;k++){
        if(i>mid) a[k]=aux[j++];
        else if(j>high) a[k]=aux[i++];
        else if(aux[j]<aux[i]) a[k]=aux[j++];
        else a[k]=aux[i++];
    }
}

void sort(int a[],int low,int high){
    if(high<=low) return;
    int mid=low+(high-low)/2;
    sort(a,low,mid);
    sort(a,mid+1,high);
    merge(a,low,mid,high);
}

int main()
{
    int a[100];
    for(int i=0;i<100;i++){
        a[i]=i;
    }
    random_shuffle(a,a+100);
    sort(a,0,99);
    for(int i=0;i<100;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}