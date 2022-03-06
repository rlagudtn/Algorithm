// ///////////////////1504 (6)
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;
// const int MAX_V=801;
// const int INF=1e9;
// vector<pair<int,int>> adj[MAX_V];

// int dijkstra(int s,int e){
//     vector<int> dist(MAX_V,INF);
//     priority_queue<pair<int,int>> pq;
//     pq.push({0,s});
//     dist[s]=0;
//     while(!pq.empty()){
//         int cost=-pq.top().first;
//         int now=pq.top().second;
//         pq.pop();
//         if(cost>dist[now])
//             continue;
//         for(int i=0;i<adj[now].size();i++){
//             int next=adj[now][i].first;
//             int nCost=adj[now][i].second+cost;
//             if(nCost<dist[next]){
//                 dist[next]=nCost;
//                 pq.push({-nCost,next});
//             }
//         }
//     }
//     return dist[e];
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n,e,a,b,c,v1,v2;
//     cin>>n>>e;
//     for(int i=0;i<e;i++){
//         cin>>a>>b>>c;
//         adj[a].push_back({b,c});
//         adj[b].push_back({a,c});
//     }
    
//     cin>>v1>>v2;
//     int v1v2=dijkstra(v1,v2);
//     int sv1=dijkstra(1,v1);
//     int sv2=dijkstra(1,v2);
//     int v1e=dijkstra(v1,n);
//     int v2e=dijkstra(v2,n);
    
//     int answer=INF;
//     if(sv1!=INF && v1v2!=INF &&v2e!=INF){
//         answer=sv1+v1v2+v2e;
//     }
//     if(sv2!=INF &&v1v2!=INF &&v1e!=INF){
//         answer=min(answer,sv2+v1v2+v1e);
//     }
//     if(answer==INF)
//         answer=-1;
//     cout<<answer<<"\n";
    
// }


// /////////////////4485 (5)
// #include <iostream>
// #include <string.h>
// #include <queue>
// struct Node{
//     int cost;
//     int x;
//     int y;
//     Node(int cost,int y,int x):cost(cost),x(x),y(y){}
//     bool operator <(const Node& other) const{
//         return cost<other.cost;
//     }
// };
// using namespace std;
// int n,arr[125][125],dist[125][125];
// const int INF=0x3f;
// int dy[4]={0,0,1,-1};
// int dx[4]={1,-1,0,0};
// int dijkstra(){
//     priority_queue<Node> pq;
//     memset(dist,INF,sizeof(dist));
//     pq.push(Node(-arr[0][0],0,0));
//     dist[0][0]=arr[0][0];
//     while(!pq.empty()){
//         int cost=-pq.top().cost;
//         int cy=pq.top().y;
//         int cx=pq.top().x;
//         pq.pop();
//         if(cost>dist[cy][cx])
//             continue;
//         for(int i=0;i<4;i++){
//             int ny=cy+dy[i];int nx=cx+dx[i];
//             if(ny<0||ny>=n||nx<0 ||nx>=n)
//                 continue;
//             int nCost=cost+arr[ny][nx];
//             if(nCost<dist[ny][nx]){
//                 dist[ny][nx]=nCost;
//                 pq.push(Node(-nCost,ny,nx));
//             }
//         }
//     }
//     return dist[n-1][n-1];
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     vector<int> answer;
//     while(true){
//         cin>>n;
//         if (n == 0)
//             break;
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 cin >> arr[i][j];
//         answer.push_back(dijkstra());
//     }
//     for(int i=1;i<=answer.size();i++)
//         cout<<"Problem "<<i<<": "<<answer[i-1]<<"\n";
//     return 0;
// }



// // /////////1261 (4)
// #include <iostream>
// #include <queue>
// #include <string.h>
// using namespace std;
// const int INF=0x3f;
// int n,m,arr[100][100],cache[100][100];
// int dy[4]={0,0,1,-1};
// int dx[4]={1,-1,0,0};
// int bfs(){
//     queue<pair<int,int>> q;
//     q.push({0,0});
//     cache[0][0]=0;
//     while(!q.empty()){
//         int cy=q.front().first,cx=q.front().second;
//         q.pop();
//         for(int i=0;i<4;i++){
//             int ny=cy+dy[i],nx=cx+dx[i];
//             if(ny<0||ny>=n||nx<0||nx>=m)
//                 continue;
//             if(arr[ny][nx]==1 &&cache[ny][nx]>cache[cy][cx]+1){
//                 cache[ny][nx]=cache[cy][cx]+1;
//                 q.push({ny,nx});
//             }
//             else if(arr[ny][nx]==0 &&cache[ny][nx]>cache[cy][cx]){
//                 cache[ny][nx]=cache[cy][cx];
//                 q.push({ny,nx});
//             }
//         }
//     }
//     return cache[n-1][m-1];
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin>>m>>n;
//     for(int i=0;i<n;i++){
//         string temp;
//         cin>>temp;
//         for(int j=0;j<m;j++)
//             arr[i][j]=temp[j]-'0';
//     }
        

//     memset(cache,INF,sizeof(cache));
//     cout<<bfs()<<"\n";
//     return 0;
// }
// #include <iostream>
// #include <queue>
// #include <string.h>
// using namespace std;
// int n,m,arr[100][100];
// int dy[4]={0,0,1,-1};
// int dx[4]={1,-1,0,0};
// bool bfs(){
//     queue<pair<int,int>> q;
//     int visit[n][m];
//     memset(visit,0,sizeof(visit));
//     q.push({0,0});
//     visit[0][0]=1;
//     while(!q.empty()){
//         int cy=q.front().first;
//         int cx=q.front().second;
//         q.pop();
//         if(cy==n-1 && cx==m-1)
//             return true;
        
//         for(int i=0;i<4;i++){
//             int ny=cy+dy[i];int nx=cx+dx[i];
//             if(ny>=0 &&ny<n &&nx>=0 &&nx<m 
//                 && arr[ny][nx]==0 && visit[ny][nx]==0){
//                     q.push({ny,nx});
//                     visit[ny][nx]=1;
//                 }
//             else if(ny>=0 &&ny<n &&nx>=0 &&nx<m 
//                 && arr[ny][nx]==1 && visit[ny][nx]==0){
//                     arr[ny][nx]=0;
//                     visit[ny][nx]=1;
//                 }
//         }
//     }
//     return false;
// }
// int main(void){
//     cin>>m>>n;
//     for(int i=0;i<n;i++){
//         string temp;
//         cin>>temp;
//         for(int j=0;j<m;j++){
//             arr[i][j]=temp[j]-'0';
//         }
//     }
//     int answer=0;

    
//     while(!bfs()){
//         answer++;
//     }
//     cout<<answer<<"\n";
//     return 0;
// }


// //////////////1238 (3)
// #include <iostream>
// #include <string.h>
// using namespace std;
// const int MAX_V=1001;
// const int INF=0x3f;
// int adj[MAX_V][MAX_V];
// int n,m,x;
// void floyd(){
//     for(int i=1;i<=n;i++)
//         adj[i][i]=0;
    
//     for(int k=1;k<=n;k++)
//         for(int i=1;i<=n;i++)
//             for(int j=1;j<=n;j++)
//                 adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin>>n>>m>>x;
//     int a,b,w;
//     memset(adj,INF,sizeof(adj));
    
//     for(int i=0;i<m;i++){
//         cin>>a>>b>>w;
//         adj[a][b]=w;
//     }
//     floyd();
//     int answer=0;
//     for(int i=1;i<=n;i++){
//         answer=max(answer,adj[x][i]+adj[i][x]);
//     }
//     cout<<answer<<"\n";
//     return 0;
// }

// ///////////////1753 (1)
// #include <iostream>
// #include <queue>

// using namespace std;
// const int INF=1e9;
// const int MAX_V=20001;
// vector<pair<int,int>> adj[MAX_V];
// vector<int> d(MAX_V,INF);
// void dijkstra(int s){
//     d[s]=0;
//     priority_queue<pair<int,int>> pq;
//     pq.push(make_pair(0,s));
//     while(!pq.empty()){
//         int cost=-pq.top().first;
//         int now=pq.top().second;
//         pq.pop();
//         if(d[now]<cost)
//             continue;
        
//         for(int i=0;i<adj[now].size();i++){
//             int next=adj[now][i].first;
//             int nCost=cost+adj[now][i].second;
//             if(nCost<d[next]){
//                 pq.push(make_pair(-nCost,next));
//                 d[next]=nCost;
//             }
//         }
//     }
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int v,e,k,a,b,w;
//     cin>>v>>e>>k;
//     for(int i=0;i<e;i++){
//         cin>>a>>b>>w;
//         adj[a].push_back(make_pair(b,w));
//     }

//     dijkstra(k);
//     for(int i=1;i<=v;i++){
//         if(d[i]==INF)
//             cout<<"INF\n";
//         else
//             cout<<d[i]<<"\n";
//     }
// }   