#include<iostream>
#include<utility>
#include<array>
using namespace std;
void merge(int a[],int low,int mid,int high,int n){
    int left=low,right=mid+1,arr[n],cnt=0;//or make vector<int> &a where ...vec(a,a+n)
    while(left<=mid && right<=high){
        if(a[left]<=a[right]){arr[cnt++]=a[left++];}
        else arr[cnt++]=a[right++];
    }
    while(left<=mid)arr[cnt++]=a[left++];
    while(right<=high)arr[cnt++]=a[right++];
    for(int i=low;i<=high;++i)a[i]=arr[i-low];
}
void mergesort(int a[],int low,int high,int n)
{
    if (low>=high) return;//base case
    int mid=(low+high)/2;
    mergesort(a,low,mid,n);mergesort(a,mid+1,high,n);
    merge(a,low,mid,high,n);

}
/*     int left_ind=low,right_ind=mid+1;
    while(left_ind<=mid && right_ind<=high){
        if(a[left_ind]<=a[right_ind])left_ind++;
        else{int temp=a[right_ind];
            for(int i=right_ind;i>left_ind;--i){a[i]=a[i-1];}
            a[left_ind]=temp;left_ind++;right_ind++;mid++;}
    }*/
int main(){
    int n;
    cin>>n;int a[n];
    for(int i=0;i<n;++i){cin>>a[i];}
    //vector<int> vec(a,a+size)
    mergesort(a,0,n-1,n);
    for(int i=0;i<n;++i)cout<<a[i]<<"\n";
}