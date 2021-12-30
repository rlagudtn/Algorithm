// //////////3079 (3)
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main(void){
//     long long n,m;
//     cin>>n>>m;
//     long long arr[n];
//     for(int i=0;i<n;i++)
//         cin>>arr[i];
    
//     long long start,end,mid,answer;
//     start=1,end=(*max_element(arr,arr+n))*m;
//     answer=end;
//     while(start<=end){
//         mid=(start+end)/2;
//         long long cnt=0;
//         for(int i=0;i<n;i++){
//             cnt+=mid/arr[i];
//         }

//         if(cnt>=m){
//             end=mid-1;
//             answer=min(answer,mid);
//         }
//         else    
//             start=mid+1;
//     }
//     cout<<answer<<"\n";
//     return 0;
// }


///////// 중량제한

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <string.h>
// using namespace std;
// int n,m;
// vector<vector<int>> edges;
// bool bfs(int fac1,int fac2,int mid){
//     vector<vector<int>> arr(n+1);
//     int visit[n+1]={0,};
//     ////////////이부분은 사실 불필요함-==> 개선 가능
//     for(int i=0;i<m;i++){
//         if(edges[i][2]>=mid){
//             arr[edges[i][0]].push_back(edges[i][1]);
//             arr[edges[i][1]].push_back(edges[i][0]);
//         }
//     }
//     queue<int> q;
//     q.push(fac1);
//     visit[fac1]=1;
//     while(!q.empty()){
//         int now=q.front();
//         q.pop();
//         if(now==fac2)
//             return true;
        
//         for(int i=0;i<arr[now].size();i++){
//             if(visit[arr[now][i]]==0){
//                 visit[arr[now][i]]=1;
//                 q.push(arr[now][i]);
//             }
//         }
//     }
//     return false;
// }
// int main(void){
//     int fac1,fac2;
//     cin>>n>>m;

//     int a,b,c;
//     for(int i=0;i<m;i++){
//         cin>>a>>b>>c;
//         edges.push_back({a,b,c});
//     }
//     cin>>fac1>>fac2;

//     int visit[n+1];
    
//     int start,end,mid,answer;
//     answer=0;
//     start=1;
//     end=int(1e9);
//     while(start<=end){
//         mid=(start+end)/2;
        
//         if(bfs(fac1,fac2,mid)){
//             start=mid+1;
//             answer=max(answer,mid);
//         }
//         else
//             end=mid-1;
//     }
//     cout<<answer<<"\n";
//     return 0;
// }