////////////////11000
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n;
pair<int,int> arr[200000];
int getClassroom(){
  priority_queue<int> pq;
  pq.push(-arr[0].second);
  for(int i=1;i<n;i++){
    int now=-pq.top();
    if(arr[i].first>=now)
      pq.pop();
    pq.push(-arr[i].second);
  }
  return pq.size();
}
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>arr[i].first>>arr[i].second;
  
  sort(arr,arr+n);
  cout<<getClassroom()<<"\n";
  return 0;
}

// ////////////1449
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int n,l,leak[1000];
// int main(void){
//   cin>>n>>l;
//   for(int i=0;i<n;i++)
//     cin>>leak[i];
//   sort(leak,leak+n);
//   int current=leak[0];
//   int answer=1;
//   for(int i=0;i<n;i++){
//     if(leak[i]<current+l)
//       continue;
//     current=leak[i];
//     answer++;
//   }
//   cout<<answer<<"\n";
//   return 0;
// }
// ///////////4796
// #include <iostream>

// using namespace std;
// int main(void){
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);cout.tie(0);
//   long long L,P,V;
//   int i=1;
//   while(true){
//     cin>>L>>P>>V;
//     if(L==0 &&P==0&&V==0)
//       break;
//     int answer=V/P*L;
//     if(V%P>=L)
//       answer+=L;
//     else
//       answer+=V%P;

//     cout<<"Case "<<i<<": "<<answer<<"\n";
//     i++;
//   }
//   return 0;
// }