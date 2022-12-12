#include <bits/stdc++.h>

using namespace std;

int partition (int a[],int low,int high){
    int i=low,j=high+1;
    int v=a[low];
    while(1){
        while(a[++i]<v){
            if(i==high) break;
        }
        while(v<a[--j]){
            if(j==low) break;
        }
        if(i>=j) break;
        swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}

void sort(int a[],int low,int high){
    if(high<=low) return;
    int j=partition(a,low,high);
    sort(a,low,j-1);
    sort(a,j+1,high);
}

void sort3way(int a[],int low,int high){
    if(high<=low) return;
    int left=low,i=low+1,right=high;
    int v=a[low];
    while(i<=right){
        if(a[i]<v) swap(a[i++],a[left++]);
        else if(a[i]>v) swap(a[i],a[right--]);
        else i++;
    }
    sort(a,low,left-1);
    sort(a,right+1,high);
}

int main()
{
    int a[100];
    for(int i=0;i<100;i++){
        a[i]=i;
    }
    random_shuffle(a,a+100);
    sort3way(a,0,99);
    for(int i=0;i<100;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}