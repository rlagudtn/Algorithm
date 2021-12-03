
// #include <stdio.h>
// #include <queue>

// using namespace std;
// const int MAX=100;
// int n,m;
// int visit[MAX+1];

// vector<vector<int>> edges;
// int bfs(){
//     queue<int> q;
//     int ret=0;
//     q.push(1);
//     visit[1]=1;
//     while(!q.empty()){
//         int idx=q.front();
//         q.pop();
//         for(int i=0;i<edges[idx].size();i++){
//             if(visit[edges[idx][i]]==0){
//                 visit[edges[idx][i]]=1;
//                 q.push(edges[idx][i]);
//                 ret++;

//             }
//         }
//     }
//     return ret;
// }
// int main(void){
//     scanf("%d",&n);
//     scanf("%d",&m);
//     vector<int> temp;
//     for(int i=0;i<n+1;i++)
//         edges.push_back(temp);
//     for(int i=0;i<m;i++){
//         int a,b;
//         scanf("%d %d",&a,&b);
//         edges[a].push_back(b);
//         edges[b].push_back(a);
//     }
//     printf("%d\n",bfs());
    
//     return 0;
// }
// // #include <iostream>
// // #include <string>
// // #include <queue>

// // using namespace std;
// // int n,m;
// // int graph[100][100];
// // bool visit[100][100];
// // int dy[4]={0,0,1,-1};
// // int dx[4]={1,-1,0,0};
// // int bfs(){
// //     queue<vector<int>> q;
// //     vector<int> temp(3);
// //     temp[0]=temp[1]=0;temp[2]=1;
// //     q.push(temp);
// //     visit[0][0]=1;
// //     while(!q.empty()){
// //         int y=q.front()[0];int x=q.front()[1];int cnt=q.front()[2];
// //         q.pop();
// //         if(y==n-1&&x==m-1)
// //             return cnt;
// //         for(int i=0;i<4;i++){
// //             int ny=y+dy[i];int nx=x+dx[i];
// //             if(ny>=0 &&ny<n &&nx>=0 && nx<m&&graph[ny][nx]==1 &&visit[ny][nx]==0 ){
// //                 temp[0]=ny;temp[1]=nx;temp[2]=cnt+1;
// //                 q.push(temp);
// //                 visit[ny][nx]=1;
// //             }
// //         }

// //     }
// //     return 0;
// // }
// // int main(void){
// //     string temp;
// //     cin>>n>>m;
// //     for(int i=0;i<n;i++){
// //         cin>>temp;
// //         for(int j=0;j<m;j++)
// //             graph[i][j]=temp[j]-'0';
// //     }
// //     cout<<bfs()<<"\n";
// //     return 0;
// // }
// // #include <stdio.h>
// // #include <queue>

// // using namespace std;
// // const int MAX=200000;
// // int n,k;
// // int visit[MAX+1];
// // int main(void){
// //     scanf("%d %d",&n,&k);
// //     if(n>k){
// //         printf("%d\n",n-k);
// //         return 0;
// //     }
// //     queue<pair<int,int>> q;
// //     q.push(make_pair(n,0)); 
// //     visit[n]=1;
// //     while (!q.empty()){
// //         int idx=q.front().first;int cnt=q.front().second;
// //         q.pop();
// //         if(idx==k){
// //             printf("%d\n",cnt);
// //             break;
// //         }
        
// //         int nidx=idx+1;
// //         if(nidx<=MAX &&visit[nidx]==0){
// //             q.push(make_pair(nidx,cnt+1));
// //             visit[nidx]=1;
// //         }
// //         nidx=idx-1;
// //         if(nidx>=0 &&visit[nidx]==0){
// //             q.push(make_pair(nidx,cnt+1));
// //             visit[nidx]=1;
// //         }
// //         nidx=idx*2;
// //         if(nidx<=MAX &&visit[nidx]==0){
// //             q.push(make_pair(nidx,cnt+1));
// //             visit[nidx]=1;
// //         }

// //     }

// //     return 0;
// // }
// // #include <iostream>
// // #include <string>
// // #include <vector>
// // #include <algorithm>
// // #include <queue>
// // using namespace std;
// // int n;
// // int dy[4]={0,0,1,-1};
// // int dx[4]={1,-1,0,0};
// // bool graph[25][25];

// // int bfs(int y,int x){
// //     queue<pair<int,int>> q;
// //     q.push(make_pair(y,x));
// //     int sum=0;
// //     graph[y][x]=0;

// //     while(!q.empty()){
// //         y=q.front().first;x=q.front().second;
// //         q.pop();
// //         sum+=1;
// //         for(int i=0;i<4;i++){
// //             int ny=y+dy[i];int nx=x+dx[i];
// //             if(ny>=0&& ny<n&&nx>=0 &&nx<n && graph[ny][nx]==1){
// //                 q.push(make_pair(ny,nx));
// //                 graph[ny][nx]=0;
// //             }
// //         }
// //     }
// //     return sum;
// // }
// // int main(void){
// //     cin>>n;
// //     string temp;
// //     for(int i=0;i<n;i++){
// //         cin>>temp;
// //         for(int j=0;j<n;j++)
// //             graph[i][j]=temp[j]-'0';
// //     }
    
// //     int cnt=0;
// //     vector<int> arr;
// //     for(int i=0;i<n;i++){
// //         for(int j=0;j<n;j++){
// //             if(graph[i][j]==1){
// //                 arr.push_back(bfs(i,j));
// //                 cnt++;
// //             }
// //         }
// //     }
// //     sort(arr.begin(),arr.end());
// //     cout<<cnt<<endl;
// //     for(int i=0;i<arr.size();i++)   
// //         cout<<arr[i]<<"\n";
            
// //     return 0;
// // }
// // #include <iostream>
// // #include <queue>
// // #include <algorithm>

// // using namespace std;
// // int n,m,s;
// // vector<vector<int>> graph(1001);;
// // bool visit[1001];
// // void dfs(int idx){
// //     if(visit[idx])
// //         return;
// //     visit[idx]=true;
// //     cout<<idx<<" ";

// //     for(int i=0;i<graph[idx].size();i++){
// //         dfs(graph[idx][i]);
// //     }
// // }
// // void bfs(int idx){
// //     queue<int> q;
// //     q.push(idx);
// //     visit[idx]=0;
// //     while(!q.empty()){
// //         int now=q.front();
// //         q.pop();
// //         cout<<now<<" ";
// //         for(int i=0;i<graph[now].size();i++){
// //             if(visit[graph[now][i]]){
// //                 q.push(graph[now][i]);
// //                 visit[graph[now][i]]=0;
// //             }
// //         }
// //     }
// // }
// // int main(void){
// //     int a,b;
// //     cin>>n>>m>>s;
// //     for(int i=0;i<n+1;i++){
// //         vector<int> temp;
// //         graph.push_back(temp);
// //     }
// //     for(int i=0;i<m;i++){
// //         cin>>a>>b;
// //         graph[a].push_back(b);
// //         graph[b].push_back(a);
// //     }
// //     for(int i=1;i<n+1;i++){
// //         sort(graph[i].begin(),graph[i].end());
// //     }
    

// //     dfs(s);
// //     cout<<"\n" ;
// //     bfs(s);
// //     cout<<"\n";
// //     return 0;
// // }