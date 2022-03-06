//////////////2343
#include <iostream>
#include <algorithm>
using namespace std;
const int INF=1e9;
int arr[100000];
int n,m;
int main(void){
  cin>>n>>m;
  int start,end=0,mid,answer;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    end+=arr[i];
  }
  answer=end;
  start=*max_element(arr,arr+n);
  
  while(start<=end){
    mid=(start+end)/2;
    int cnt=1,sum=0;
    for(int i=0;i<n;i++){
      if(sum+arr[i]>mid){
        cnt++;
        sum=0;
      }
      sum+=arr[i];
    }
    if(cnt>m){
      start=mid+1;
    }
    else{
      answer=mid;
      end=mid-1;
    }
  }
  cout<<answer<<"\n";
  
  return 0;
}