

// ////////////////////////2583 (6)
// #include <iostream>
// #include <queue>
// #include <string.h>
// #include <vector>
// #include <algorithm>

// using namespace std;
// const int MAX=100;
// int n,m,k,answer;
// int graph[MAX][MAX];
// int visit[MAX][MAX];
// int dy[4]={0,0,1,-1};
// int dx[4]={1,-1,0,0};
// int bfs(int y,int x ){
//     queue<pair<int,int>> q;
//     q.push({y,x});
//     visit[y][x]=1;
//     int cy,cx,ny,nx;
//     int cnt=0;
//     while(!q.empty()){
//         cy=q.front().first;cx=q.front().second;
//         q.pop();

//         cnt++;
//         for(int i=0;i<4;i++){
//             ny=cy+dy[i];nx=cx+dx[i];
//             if(0<=ny && ny<n && 0<=nx &&nx<m &&graph[ny][nx]==0 &&visit[ny][nx]==0){
//                 visit[ny][nx]=1;
//                 q.push({ny,nx});
//             }
//         }

//     }
//     return cnt;
// }
// int main(void){
//     cin>>n>>m>>k;
//     int sx,sy,lx,ly;
//     memset(graph,0,sizeof(graph));
//     for(int t=0;t<k;t++){
//         cin>>sx>>sy>>lx>>ly;
//         for(int y=sy;y<ly;y++){
//             for(int x=sx;x<lx;x++){
//                 graph[y][x]=1;
//             }
//         }
//     }
//     vector<int> ret;
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(graph[i][j]==0&&visit[i][j]==0){
//                 int temp=bfs(i,j);
//                 cnt++;
//                 ret.push_back(temp);
//             }
//         }
//     }
//     sort(ret.begin(),ret.end());
//     cout<<cnt<<"\n";
//     for(int i=0;i<ret.size();i++){
//         cout<<ret[i]<<" ";
//     }
//     return 0;
// }
/////////////////////2836 (6)
// #include <iostream>
// #include <queue>
// #include <vector>
// #include <string.h>
// #include <math.h>
// using namespace std;
// const int MAX=100;
// int n,m,k,answer;
// int graph[MAX][MAX];
// int visit[MAX][MAX];
// int d[MAX][MAX];
// int dy[4]={0,0,-1,1};
// int dx[4]={1,-1,0,0};
// int bfs(){
//     queue<pair<int,int>> q;
//     q.push({0,0});
//     visit[0][0]=1;
//     int y,x,ny,nx;
//     int cnt=0;
//     while(!q.empty()){
//         y=q.front().first;x=q.front().second;
//         q.pop();

//         for(int i=0;i<4;i++){
//             ny=y+dy[i];nx=x+dx[i];
//             if(ny>=0 &&ny<n &&nx>=0 && nx<m && graph[ny][nx]==0 &&visit[ny][nx]==0){
//                 visit[ny][nx]=1;
//                 q.push({ny,nx});
//             }
//             else if(ny>=0 &&ny<n &&nx>=0 && nx<m && graph[ny][nx]==1 &&visit[ny][nx]==0){
//                 cnt++;
//                 visit[ny][nx]=1;
//                 graph[ny][nx]=0;
//             }
//         }
//     }
//     return cnt;
// }
// int main(void){
//     cin>>n>>m;
//     for(int i=0;i<n;i++)
//         for(int j=0;j<m;j++)
//             cin>>graph[i][j];
//     answer=0;
//     int time=0;
//     int previous=0;
//     while(true){
//         memset(visit,0,sizeof(visit));

//         int ret=bfs();
//         if(ret==0){
//             cout<<time<<"\n"<<previous<<"\n";
//             break; 
//         }
//         previous=ret;
//         time++;
//     }

//     return 0;
// }
////////////////////9466 (4) 두번째
#include <iostream>
#include <string.h>
using namespace std;

int t,n,arr[100001],cycle[100001],visit[100001];

int dfs(int idx){
    int ret=0;
    if(visit[idx]==0 ){
        visit[idx]=1;
        ret= dfs(arr[idx]);
    }
    else if(cycle[idx]==0){
        int cnt=1;
        int i=arr[idx];
        while(i!=idx){
            cnt++;
            i=arr[i];
        }
        ret=cnt;
    }
    cycle[idx]=1;
    return ret;
}
int main(void){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        memset(cycle,0,sizeof(cycle));
        memset(visit,0,sizeof(visit));
        for(int k=1;k<n+1;k++)
            cin>>arr[k];

        int answer=0;
        for(int i=1;i<n+1;i++){
            if(visit[i]==0){
                answer+=dfs(i);
            }
        }
        cout<<n-answer<<"\n";
    }
}
// ////////////////////9466 (5)
// #include <iostream>
// #include <string.h>
// #include <string>
// using namespace std;
// const int MAX=100001;
// int n,t;
// int answer=0;
// int arr[MAX];
// bool visit[MAX];
// bool done[MAX];
// void dfs(int idx){
//     if(done[idx]==true)
//         return;
//     else if(done[idx]==false && visit[idx]==true){
//         int i=idx;
//         answer++;
//         while(arr[i]!=idx){
//             answer++;
//             i=arr[i];
//         }
//         return;
//     }
//     visit[idx]=true;
//     dfs(arr[idx]);
//     done[idx]=true;
// }
// int main(void){
//     cin>>t;
    
//     for(int k=0;k<t;k++){
//         cin>>n;
//         answer=0;
//         memset(visit,0,sizeof(visit));
//         memset(done,0,sizeof(done));
//         for(int j=1;j<=n;j++){
//             cin>>arr[j];
//             if(arr[j]==j){
//                 visit[j]=1;
//                 done[j]=1;
//                 answer++;
//             }
//         }
//         for(int i=1;i<=n;i++){
//             if(visit[i]==0){
//                 dfs(i);
//             }
//         }
//         cout<<n-answer<<"\n";
//     }
    
//     return 0;
// }
// /////////////////////7576 ,7577  (2)
// #include <iostream>
// #include <queue>
// #include <string.h>
// #include <vector>
// using namespace std;
// // const int MAX=1000;
// const int MAX=100;
// int n,m,z;
// // int board[MAX][MAX];
// int board[MAX][MAX][MAX];
// int main(void){
//     int cy,cx,cz,ny,nx,nz,answer,dist;
//     int dy[6]={1,-1,0,0,0,0};int dx[6]={0,0,-1,1,0,0};
//     int dz[6]={0,0,0,0,1,-1};
//     answer=0;
//     cin>>m>>n>>z;
//     queue<vector<int>> q;
//     for(int k=0;k<z;k++){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 cin>>board[k][i][j];
//             if(board[k][i][j]==1){
//                 q.push({k,i,j,0});
//             }
//             else if(board[k][i][j]==0){
//                 answer++;
//             }
//         }
//     }
//     }
    
//     int ret=0;
//     while (!q.empty())
//     {
//         vector<int> current=q.front();
//         q.pop();
//         cz=current[0];cy=current[1];cx=current[2];dist=current[3];
//         ret=max(ret,dist);

//         for(int i=0;i<6;i++){
//             ny=cy+dy[i];nx=cx+dx[i];nz=cz+dz[i];
//             if(0>ny || ny>=n || 0>nx || nx>=m|| 0>nz || nz>=z)
//                 continue;
//             if(board[nz][ny][nx]==0){
//                 board[nz][ny][nx]=1;
//                 q.push({nz,ny,nx,dist+1});
//                 answer--;
//             }
//         }

//     }
//     // cout<<dist<<","<<answer<<"\n";
//     if(answer==0)
//         cout<<dist<<"\n";
//     else
//         cout<<-1<<"\n";
//     return 0;
    
// }





// /////////////////////2206
// // #include <iostream>
// // #include <string.h>
// // #include <queue>
// // #include <vector>
// // #include <string>
// // using namespace std;
// // const int MAX=1000;
// // int n,m;
// // int arr[MAX][MAX],visit[MAX][MAX][2];
// // int dy[4]={1,-1,0,0};
// // int dx[4]={0,0,1,-1};
// // int main(void){
// //     cin>>n>>m;
// //     memset(arr,0,sizeof(arr));
// //     for (int i = 0; i < n; i++)
// //     {
// //         string temp;
// //         cin>>temp;
// //         for (int j = 0; j < m; j++){
// //             arr[i][j]=temp[j]-'0';
// //         }
// //     }
// //     memset(visit,0,sizeof(visit));
// //     queue<vector<int>> q;
// //     vector<int> first={0,0,1,0};
// //     q.push(first);
// //     int answer=-1;
// //     visit[0][0][0]=1;
    
// //     while(!q.empty()){
// //         vector<int> current=q.front();
// //         q.pop();
// //         int cy,cx,dist,hadbroken;
// //         cy=current[0];cx=current[1];
// //         dist=current[2];hadbroken=current[3];
// //         if(cy==n-1 && cx==m-1){
// //             answer=dist;
// //             break;
// //         }
// //         int ny,nx;
// //         for(int i=0;i<4;i++){
// //             ny=cy+dy[i];nx=cx+dx[i];
// //             if(0>ny || ny>=n || 0>nx || nx>=m)
// //                 continue;

// //             if(arr[ny][nx]==0&&visit[ny][nx][hadbroken]==0){
// //                 visit[ny][nx][hadbroken]=1;
// //                 vector<int> temp={ny,nx,dist+1,hadbroken};
// //                 q.push(temp);
// //             }
// //             else if(arr[ny][nx]==1 && hadbroken==0){
// //                 visit[ny][nx][hadbroken]=1;
// //                 vector<int> temp={ny, nx,dist+1,1};
// //                 q.push(temp);
// //             }
// //         }
// //     }
// //     cout<<answer<<"\n";
// //     return 0;
// // }
// ////////////2206 (1) 두번째
// #include <iostream>
// #include <queue>
// #include <string.h>
// #include <string>
// #include <vector>
// using namespace std;
// int n,m,arr[1000][1000],visit[1000][1000][2];
// int dy[4]={0,0,1,-1};
// int dx[4]={1,-1,0,0};
// void bfs(){
//     queue<vector<int>> q;
//     q.push({0,0,1,0});
//     visit[0][0][0]=1;
//     int cy,cx,dist,broken,ny,nx;
//     while(!q.empty()){
//         vector<int> info=q.front();
//         q.pop();
//         cy=info[0];cx=info[1];dist=info[2];broken=info[3];
//         if(cy==n-1 &&cx==m-1){
//             cout<<dist<<"\n";
//             return ;
//         }
//         for(int i=0;i<4;i++){
//             ny=cy+dy[i];nx=cx+dx[i];
//             if(ny<0 ||ny>=n||nx<0||nx>=m)
//                 continue;
//             if(broken==0&& arr[ny][nx]==1 ){
//                 q.push({ny,nx,dist+1,1});
//             }
//             else if(arr[ny][nx]==0&&visit[ny][nx][broken]==0){
//                 q.push({ny,nx,dist+1,broken});
//                 visit[ny][nx][broken]=1;
//             }
//         }

//     }
//     cout<<-1<<"\n";
//     return;
// }
// int main(void){
//     memset(visit,0,sizeof(visit));
//     cin>>n>>m;
//     string temp;
//     for(int i=0;i<n;i++){
//         cin>>temp;
//         for(int j=0;j<m;j++)
//             arr[i][j]=temp[j]-'0';
//     }

//     bfs();

//     return 0;
// }