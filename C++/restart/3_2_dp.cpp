// #include <iostream>
// #include <string.h>
// #include <algorithm>
// using namespace std;
// const int MAX=1000;
// int n;
// int arr[MAX][3];
// int cache[MAX][3];
// int dfs(int idx,int type){
//     if(idx==n)
//         return 0;
    
//     int& ret=cache[idx][type];
//     if(ret!=-1)
//         return ret;
    
//     int index[6]={0,1,2,0,1,2};
//     return ret=min(dfs(idx+1,index[type+1]),dfs(idx+1,index[type+2]))+arr[idx][type];
// }
// int main(void){
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
//     }
//     memset(cache,-1,sizeof(cache));
//     int answer=int(1e9);
//     for(int i=0;i<3;i++){
//         answer=min(answer,dfs(0,i));
//     }
//     cout<<answer<<"\n";
//     return 0;
// }


//////////////1149 (3번)
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=1001;
int main(void){
    int n,arr[MAX][3];
    int cacheR[MAX],cacheG[MAX],cacheB[MAX];

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    cacheR[1]=arr[1][0];cacheG[1]=arr[1][1];cacheB[1]=arr[1][2];

    for(int i=2;i<=n;i++){
        cacheR[i]=min(cacheG[i-1],cacheB[i-1])+arr[i][0];
        cacheG[i]=min(cacheR[i-1],cacheB[i-1])+arr[i][1];
        cacheB[i]=min(cacheG[i-1],cacheR[i-1])+arr[i][2];
    }
    cout<<min({cacheR[n],cacheG[n],cacheB[n]})<<"\n";
    
    return 0;
}
// #include <iostream>
// #include <string.h>
// #include <algorithm>
// using namespace std;

// const int MAX=500;
// int n;
// int arr[MAX][MAX];
// int cache[MAX][MAX];
// int dfs(int y,int x){
//     if(y==n)
//         return 0;
    
//     int& ret=cache[y][x];
//     if(ret!=-1)
//         return ret;

//     return ret= max(dfs(y+1,x),dfs(y+1,x+1))+arr[y][x];
// }
// int main(void){
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++)
//             cin>>arr[i][j];
//     }
//     memset(cache,-1,sizeof(cache));
//     cout<<dfs(0,0)<<"\n";
//     return 0;
// }
////////////////1463 (2번)
// #include <iostream>
// #include <string.h>
// #include <algorithm>
// using namespace std;
// int n;
// const int MAX=int(1e6);
// int cache[MAX+1];

// int main(void)  {
//     cin>>n;
//     memset(cache,-1,sizeof(cache));
//     cache[1]=0;
//     for(int i=2;i<=n;i++){
//         int& current=cache[i];
//         current=MAX+1;
//         if(i%3==0)
//             current=min(current,cache[i/3]);
//         if(i%2==0)
//             current=min(current,cache[i/2]);
//         current=min(current,cache[i-1])+1;
//     }
//     cout<<cache[n]<<"\n";
//     return 0;
// }
// #include <iostream>
// #include <queue>
// #include <string.h>
// using namespace std;
// const int MAX=int(1e6);
// int n;

// int visit[MAX+1];
// int bfs(){
//     queue<pair<int,int>> q;
//     q.push(make_pair(n,0));
//     visit[n]=1;
//     while(!q.empty()){
//         int now=q.front().first;int dist=q.front().second;
//         q.pop();

//         if(now==1)
//             return dist;
        
//         int next[3]={now-1,now/2,now/3};
//         for(int i=0;i<3;i++){
//             if(visit[next[i]]==0 &&(i==0||(now%2==0&&i==1)||(now%3==0&&i==2)) ){
//                 q.push(make_pair(next[i],dist+1));
//                 visit[next[i]]=1;
//             }
//         }
//     }
//     return visit[n];
// }
// int main(void){
//     cin>>n;
//     memset(visit,0,sizeof(visit));
//     cout<<bfs()<<"\n";
//     return 0;
// }
// // // ////////////////1003 (1번)
// // // #include <iostream>
// // // #include <vector>

// // // using namespace std;

// // // const int MAX=40;
// // // int t,n;
// // // vector<pair<int,int>> cache(MAX+1);
// // // pair<int,int> dfs(int n){
// // //     pair<int,int>& ret=cache[n];
// // //     if(ret.first!=-1)
// // //         return ret;
// // //     ret.first=0;
// // //     ret.second=0;
// // //     pair<int,int> p1=dfs(n-1);
// // //     pair<int,int> p2=dfs(n-2);
// // //     ret.first=p1.first+p2.first;
// // //     ret.second=p1.second+p2.second;

// // //     return ret;
// // // }
// // // int main(void){
// // //     cin>>t;
    
// // //     for(int i=0;i<t;i++){
// // //         cin>>n;
// // //         for(int j=0;j<n+1;j++){
// // //             pair<int,int> temp;
// // //             cache.push_back(temp);
// // //             cache[j].first=-1;cache[j].second=-1;
// // //         }

// // //         cache[0].first=1;cache[0].second=0;
// // //         cache[1].first=0;cache[1].second=1;
// // //         pair<int,int> answer=dfs(n);
// // //         cout<<answer.first<<" "<<answer.second<<"\n";

// // //         cache.clear();
// // //     }

// // //     return 0;
// // // }