#include<bits/stdc++.h>
using namespace std;
void Quicksort(int a[],int low,int high){
    if(low>=high)return;
    int j=high,i=low,pivot=a[low],part;
    while(i<j){
        while(a[i]<=pivot && i<=high)i++;
        while(a[j]>pivot && j>=low+1)j--;
        if(i<j)swap(a[i],a[j]);
    }swap(a[low],a[j]);part=j;
    Quicksort(a,low,part-1);Quicksort(a,part+1,high);
}
int main(){
    int n;cin>>n;int a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    Quicksort(a,0,n-1);
    for(int i=0;i<n;++i)cout<<a[i]<<"\n";
}