#include<iostream>
using namespace std;
void reverse(int a[],int l,int h){
    for(int i=l;i<l+(h-l)/2;++i)swap(a[i],a[h-1-(i-l)]);
}
void rotatear(int a[],int n,int k){
/*     int rot=k%n,temp[rot];              //O(n+k%n),O(n)
    for(int j=0;j<rot;++j)temp[j]=a[j];
    for(int j=0;j<n-rot;++j)a[j]=a[j+rot];
    for(int i=n-rot;i<n;++i)a[i]=temp[i-n+rot]; */
    int rot=k%n;
    reverse(a,0,rot);reverse(a,rot,n);reverse(a,0,n);   //O(2n),O(1)
}
int main(){
    int k,n;cin>>n;
    int a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    cout<<"Enter the number of places array has to be left rotated by:";
    cin>>k;
    rotatear(a,n,k);
    for(int i=0;i<n;++i)cout<<a[i]<<" ";
}