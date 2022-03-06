// /////////////////2887(3)
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// const int  MAX_V=1e5;
// int n;
// vector<pair<int,int>> arr[3];
// struct DisjointSet{
//     vector<int> parent;
//     DisjointSet(int n):parent(n){
//         for(int i=0;i<n;i++)
//             parent[i]=i;
//     }
//     int find(int u){
//         if(u==parent[u])
//             return u;
//         return parent[u]=find(parent[u]);
//     }
//     void merge(int u, int v){
//         u=find(u);v=find(v);
//         if(u==v)
//             return;
//         if(u>v)
//             swap(u,v);
//         parent[v]=u;
//     }
// };

// int kruskal(){
//     vector<pair<int,pair<int,int>>> edges;

//     sort(arr[0].begin(),arr[0].end());
//     sort(arr[1].begin(),arr[1].end());
//     sort(arr[2].begin(),arr[2].end());
//     for(int i=0;i<n-1;i++){
//         int x=arr[0][i+1].first-arr[0][i].first;
//         edges.push_back({x,{arr[0][i].second,arr[0][i+1].second}});
        
//         int y=arr[1][i+1].first-arr[1][i].first;
//         edges.push_back({y,{arr[1][i].second,arr[1][i+1].second}});
        
//         int z=arr[2][i+1].first-arr[2][i].first;
//         edges.push_back({z,{arr[2][i].second,arr[2][i+1].second}});
        
//     }
//     sort(edges.begin(),edges.end());
//     DisjointSet sets(n);
//     long long answer=0;
//     for(int i=0;i<edges.size();i++){
//         int cost=edges[i].first;
//         int u=edges[i].second.first,v=edges[i].second.second;
//         if(sets.find(u)==sets.find(v))
//             continue;
//         sets.merge(u,v);
//         answer+=cost;
//     }
//     return answer;
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int a,b,c;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>a>>b>>c;
//         arr[0].push_back({a,i});
//         arr[1].push_back({b,i});
//         arr[2].push_back({c,i});
//     }
//     cout<<kruskal()<<"\n";
//     return 0;
// }

// // /////////////////11404 (2)
// // // #include <iostream>
// // // #include <string.h>

// // // using namespace std;
// // // const int MAX_V=101;
// // // const int INF=1e9;
// // // int adj[MAX_V][MAX_V];
// // // int n,m;
// // // void floyd(){
// // //     for(int i=1;i<=n;i++)
// // //         adj[i][i]=0;
    
// // //     for(int k=1;k<=n;k++)
// // //         for(int i=1;i<=n;i++)
// // //             for(int j=1;j<=n;j++)
// // //                 adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
        
// // // }
// // // int main(void){
// // //     ios_base::sync_with_stdio(0);
// // //     cin.tie(0);cout.tie(0);
    
    
// // //     cin>>n>>m;
// // //     for(int i=1;i<=n;i++)
// // //         for(int j=1;j<=n;j++)
// // //             adj[i][j]=INF;
    
// // //     int a,b,c;
// // //     for(int i=0;i<m;i++){
// // //         cin>>a>>b>>c;
// // //         adj[a][b]=min(adj[a][b],c);
// // //     }
    
// // //     floyd();
// // //     for(int i= 1;i<=n;i++){
// // //         for(int j=1;j<=n;j++)
// // //             cout<<(adj[i][j]!=INF? adj[i][j]:0)<<" ";
// // //         cout<<"\n";
// // //     }
// // //     return 0;

// // // }
// // // ////////////////11657 (1)
// // #include <iostream>
// // #include <vector>
// // using namespace std;
// // const long long INF=2100000000;
// // const int MAX_V=501;
// // int n,m;
// // int adj[MAX_V][MAX_V];
// // vector<long long> bellmanFord(){
// //     vector<long long> upper(n+1,INF);
// //     upper[1]=0;
// //     bool updated;
    
// //     for(int k=0;k<n;k++){
// //         updated=false;
// //         for(int u=1;u<=n;u++){
// //             for(int v=1;v<=n;v++)
// //             ///////upper[u]가 INF 인 이고 cost가 -1000정도 될때 upper[v]보다 작으며
// //             ///갱신 되기 때문에 upper[u]!=INF 여야한다.
// //                 if(upper[u]!=INF && upper[v]>upper[u]+adj[u][v]){
// //                     upper[v]=upper[u]+adj[u][v];
// //                     updated=true;
// //                 }
            
// //         }
// //         if(!updated)
// //             break;
// //     }
    
// //     if(updated)
// //         upper.clear();

// //     return upper;
// // }
// // int main(void){
// //     int a,b,c;
// //     cin>>n>>m;
// //     for(int i=1;i<=n;i++)
// //         for(int j=1;j<=n;j++)
// //             adj[i][j]=INF;
// //     for(int i=0;i<m;i++){
// //         cin>>a>>b>>c;
// //         adj[a][b]=min(adj[a][b],c);
// //     }
// //     vector<long long> answer=bellmanFord();
// //     if(answer.size()==0){
// //         cout<<-1<<"\n";
// //         return 0;
// //     }
// //     for(int i=2;i<=n;i++)
// //         cout<<(answer[i]!=INF?answer[i]:-1)<<"\n";
// //     return 0;
// // }





// // // #include <iostream>
// // // #include <vector>

// // // using namespace std;

// // // const int MAX_V=501;
// // // const long long INF=2100000000;
// // // int n,m;
// // // vector<pair<int,int>> adj[MAX_V];
// // // vector<long long> bellmanford(int src){
// // //     //underflow 발생으로 인해 long long으로 수정해줌
// // //     vector<long long> upper(n+1,INF);
// // //     upper[src]=0;
// // //     bool updated;

// // //     for(int k=0;k<n;k++){
// // //         updated=false;
// // //         for(int now=1;now<=n;now++){
// // //             for(int i=0;i<adj[now].size();i++){
// // //                 int next=adj[now][i].first;
// // //                 int cost=adj[now][i].second;
// // //                 if(upper[now]!=INF &&cost+upper[now]<upper[next]){
// // //                     upper[next]=cost+upper[now];
// // //                     updated=true;
// // //                 }
// // //             }
// // //         }
// // //         if(!updated)
// // //             break;
        
// // //     }
// // //     if(updated)
// // //         upper.clear();
// // //     return upper;
// // // }
// // // int main(void){
// // //     ios_base::sync_with_stdio(0);
// // //     cin.tie(0);cout.tie(0);
// // //     int a,b,c;
// // //     cin>>n>>m;
// // //     for(int i=0;i<m;i++){
// // //         cin>>a>>b>>c;
// // //         adj[a].push_back({b,c});
// // //     }

// // //     vector<long long> answer=bellmanford(1);
// // //     if(answer.size()==0){
// // //         cout<<-1<<"\n";
// // //         return 0;
// // //     }
// // //     for(int i=2;i<=n;i++)
// // //         cout<<(answer[i]!=INF? answer[i]:-1)<<"\n";

// // //     return 0;
// // // }