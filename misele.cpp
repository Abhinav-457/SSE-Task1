#include<iostream>
#include<vector>
using namespace std;
int sumele(vector<int> a){
    int n=a.size(),sum=0,isum=n*(n+1)/2;        //O(n),O(1)
    for(int i=0;i<n;++i)sum+=a[i];
    if(isum==sum)return 0;
    else return isum-sum;
}
int xorele(vector<int> a){
    int n=a.size();int xor1=0,xor2=0;        //O(n),O(1)   //this XOR method is often preferred over the 
    for(int i=0;i<n;++i){xor1^=i+1;xor2^=a[i];}            //sum method because it avoids integer 
    return xor1^xor2;                                      //overflow for very large n.(isum)
}                                                          //property (a^b)^c=a^(b^c)
int main(){
    int n;cin>>n;int a[n];
    for(int i=0;i<n;++i)cin>>a[i];vector<int> v(a,a+n);
    cout<<sumele(v)<<endl;
    cout<<xorele(v)<<endl;
}