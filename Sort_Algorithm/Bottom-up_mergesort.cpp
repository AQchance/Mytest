#include <bits/stdc++.h>

using namespace std;

const int N=100;
int aux[N];

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

void sort(int a[]){
    for(int size=1;size<N;size+=size){
        for(int low=0;low<N-size;low+=size+size){
            merge(a,low,low+size-1,min(low+size+size-1,N-1));
        }
    }
}

int main()
{
    int a[100];
    for(int i=0;i<100;i++){
        a[i]=i;
    }
    random_shuffle(a,a+100);
    sort(a);
    for(int i=0;i<100;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}