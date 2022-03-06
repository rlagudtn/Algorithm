////1904
#include <iostream>
#include <string.h>
using namespace std;
int n,arr[1000001];

int main(void){
  cin>>n;
  arr[1]=1,arr[2]=2;
  for(int i=3;i<=n;i++)
    arr[i]=(arr[i-1]+arr[i-2])%15746;
  cout<<arr[n]<<"\n";
  return 0;
}


// ///////////////2193
// #include <iostream>

// using namespace std;
// long long cache[91];
// int main(void){
//   int n;
//   cin>>n;
//   cache[1]=cache[2]=1;
//   for(int i=3;i<=n;i++){
//     cache[i]=cache[i-1]+cache[i-2];
//   }
//   cout<<cache[n]<<"\n";
//   return 0;
// }

// ///////1463
// #include <iostream>
// #include <queue>
// #include <string.h>
// using namespace std;
// const int INF=0x3f;
// int n,cache[1000001];
// int main(void){
//   cin>>n;
//   memset(cache,INF,sizeof(cache));
//   queue<pair<int,int>> q;
//   q.push({n,0});
//   cache[n]=0;
//   while(!q.empty()){
//     int now=q.front().first;
//     int dist=q.front().second;
//     q.pop();
//     ///////등호를 넣으면 처음부터 걸러지게 되므로 등호를 뺀다
//     if(dist>cache[now])
//       continue;
//     int nDist=cache[now]+1;
//     for(int i=3;i>=2;i--){
//       int next=now/i;
//       if(now%i==0&&cache[next]>nDist){
//         cache[next]=nDist;
//         q.push({next,nDist});
//       }
//     } 
//     int next=now-1;
//     if(next>=1 &&cache[next]>nDist){
//       cache[next]=nDist;
//       q.push({next,nDist});
//     }
//   }
//   cout<<cache[1]<<"\n";
//   return 0;
// }