////////////////3665(4)
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int MAX_V=501;
int adj[MAX_V][MAX_V];
int t,n,m,arr[MAX_V],indegree[MAX_V];
void topologySort(){
    vector<int> answer;
    queue<int> q;
    
    for(int i=1;i<=n;i++)
        if(indegree[i]==0)
            q.push(i);
    
    while(!q.empty()){
        if(q.size()>=2){
            cout<<"?\n";
            return;
        }
        int now=q.front();
        q.pop();
        answer.push_back(now);
        for(int i=1;i<=n;i++){
            if(adj[now][i]==1){
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }
    }
    if(answer.size()==n){
        for(int i=0;i<n;i++)
            cout<<answer[i]<<" ";
        cout<<"\n";
    }
    else
        cout<<"IMPOSSIBLE\n";
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;
    for (int k = 0; k < t; k++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
            indegree[arr[i]]=i-1;
        }
        memset(adj, 0, sizeof(adj));
        for (int i = 1; i < n; i++)
        {
            int now = arr[i];
            for (int j = i + 1; j <= n; j++)
            {
                int next = arr[j];
                adj[now][next] = 1;
            }
        }
        cin >> m;
        int u, v;

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            if (adj[u][v] == 1)
            {
                adj[u][v] = 0;
                adj[v][u] = 1;
                indegree[v]--;
                indegree[u]++;
            }
            else
            {
                adj[u][v] = 1;
                adj[v][u] = 0;
                indegree[v]++;
                indegree[u]--;
            }
        }
        topologySort();
    }

    return 0;
}

// ///////////////1766(3)
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <string.h>
// using namespace std;

// const int MAX_V=32001;
// int n,m;
// int degree[MAX_V]={0,};
// vector<int> adj[MAX_V];
// vector<int> topologySort(){
//     priority_queue<int> pq;
//     vector<int> answer;

//     for(int i=1;i<=n;i++)
//         if(degree[i]==0)
//             pq.push(-i);

//     while(!pq.empty()){
//         int now=-pq.top();
//         pq.pop();
//         answer.push_back(now);

//         for(int i=0;i<adj[now].size();i++){
//             int next=adj[now][i];
//             degree[next]--;
//             if(degree[next]==0)
//                 pq.push(-next);
            
//         }
//     }
//     return answer;
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int a,b;
//     cin>>n>>m;
//     for(int i=0;i<m;i++){
//         cin>>a>>b;
//         adj[a].push_back(b);
//         degree[b]++;
//     }
//     vector<int> answer=topologySort();
//     for(int i=0;i<answer.size();i++)
//         cout<<answer[i]<<" ";
//     cout<<"\n";
//     return 0;
// }

// // /////////////1005(2)
// // #include <iostream>
// // #include <vector>
// // #include <queue>
// // #include <string.h>
// // using namespace std;
// // const int MAX_V=1001;
// // int t,n,k,x,y,w,arr[MAX_V],degree[MAX_V],cache[MAX_V];

// // int topologySort(vector<int> adj[],int dest){
// //     queue<int> q;
// //     for(int i=1;i<=n;i++)
// //         if(degree[i]==0){
// //             q.push(i);
// //             cache[i]=arr[i];
// //         }
    
// //     while(!q.empty()){
// //         int now=q.front();
// //         q.pop();
// //         if(now==dest)
// //             break;
        
// //         for(int i=0;i<adj[now].size();i++){
// //             int next=adj[now][i];
// //             degree[next]--;
// //             if(degree[next]==0)
// //                 q.push(next);
// //             cache[next]=max(cache[now]+arr[next],cache[next]);
// //         }
// //     }
// //     return cache[dest];
// // }

// // int main(void){
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);cout.tie(0);
// //     cin>>t;
// //     for(int iter=0;iter<t;iter++){
// //         cin>>n>>k;
// //         for(int i=1;i<=n;i++){
// //             cin>>arr[i];
// //         }
// //         vector<int> adj[MAX_V];
        
// //         memset(cache,0,sizeof(cache));
// //         memset(degree,0,sizeof(degree));
// //         for(int i=0;i<k;i++){
// //             cin>>x>>y;
// //             adj[x].push_back(y);
// //             degree[y]++;
// //         }
// //         cin>>w;
// //         cout<<topologySort(adj,w)<<"\n";
// //     }
// //     return 0;
// // }



// // ////////////2252(1)
// // #include <iostream>
// // #include <vector>
// // #include <queue>

// // using namespace std;
// // const int MAX_V=32001;
// // int n,m,degree[MAX_V]={0,};
// // vector<int> adj[MAX_V];
// // vector<int> topology(){
// //     vector<int> answer;
// //     queue<int> q;
// //     for(int i=1;i<=n;i++)
// //         if(degree[i]==0)
// //             q.push(i);
    
// //     while(!q.empty()){
// //         int now=q.front();
// //         q.pop();
        
// //         answer.push_back(now);
// //         for(int i=0;i<adj[now].size();i++){
// //             int next=adj[now][i];
// //             degree[next]--;
// //             if(degree[next]==0)
// //                 q.push(next);
// //         }
// //     }
// //     return answer;
// // }
// // int main(void){
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);

// //     cin>>n>>m;
    
// //     int a,b;
// //     for(int i=0;i<m;i++){
// //         cin>>a>>b;
// //         degree[b]++;
// //         adj[a].push_back(b);
// //     }
// //     vector<int> answer=topology();
// //     for(int i=0;i<n;i++)
// //         cout<<answer[i]<<" ";
// //     cout<<"\n";
// //     return 0;
// // }