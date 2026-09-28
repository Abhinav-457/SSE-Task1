#include<bits/stdc++.h>
using namespace std;
int longestsub(vector<int>a,long long k){
    /* int i=0,sum=0,max=0,cnt=0;
    while(i<a.size()){ //O((n-1)*(n+2)/2)~O(n*n),O(1)
        if(a[i]<=k){
            if(sum+a[i]<k){++cnt;sum+=a[i];++i;}
            else if(sum+a[i]==k && ++cnt>max){max=cnt;sum=0;i-=cnt-2;cnt=0;}
            else {sum=0;i-=cnt-1;cnt=0;}
        }else ++i;
    }return max; */
    /* set_map<long long,int> hash;   //O(nlogn),O(n)
    long long sum=0;int maxlen=0;         //prefixsum
    for(int i=0;i<a.size();++i){
        sum+=a[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        long long rem=sum-k;
        if(hash.find(rem)!=hash.end()){
            int len=i-hash[rem];
            maxlen=max(maxlen,len);
        }if(hash.find(sum)==hash.end())hash[sum]=i;
    }return maxlen; */
    //For arrays containing non-negative numbers only
    long long sum=0,sum2=0;int maxlen=0;int j=0;                 //O(n),O(1)  //sliding window
    for(int i=0;i<a.size();++i){
        sum+=a[i];
        while(sum>k){
            sum-=a[j];
            if(sum==k)maxlen=max(maxlen,i-j);
            j++;
        }if(sum==k)maxlen=max(maxlen,i-j+1);
    }return maxlen;
}
int main(){
    int n;long long k;cin>>n;int a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    cin>>k;
    vector<int> v(a,a+n);
    cout<<longestsub(v,k);
}