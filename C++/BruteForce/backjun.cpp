

// // 1644
// #include <iostream>
// #include <math.h>
// #include <string.h>
// #include <vector>

// using namespace std;
// const int MAX=4000000;
// bool isPrime[MAX+1];
// int cache[MAX+1];
// int n;
// vector<int> primeNumbers;
// void eratos(vector<int>& primeNumbers){
    
//     for(int start=2;start<(int)sqrt(n)+1;start++){
//         for(int j=2;start*j<=n;j++){
//             isPrime[start*j]=false;
//         }
//     }
//     for(int i=2;i<=n;i++)
//         if(isPrime[i]==true)
//             primeNumbers.push_back(i);
    
// }
// int main(void){
//     cin>>n;
//     int answer=0;
//     memset(isPrime,true,sizeof(isPrime));

//     eratos(primeNumbers);
    
//     int end,interval;
//     end=interval=0;
//     for(int start=0;start<primeNumbers.size();start++){
//         while(end<primeNumbers.size() && interval<n){
//             interval+=primeNumbers[end];
//             end++;
//         }
//         if(interval==n){
//             answer++;
//         }
//         interval-=primeNumbers[start];
//     }
//     cout<<answer<<endl;

//     return 0;
// }

////////////////9019 런타임 에러 뜸;;
// #include <iostream>
// #include <string.h>
// #include <queue>

// using namespace std;
// const int MAX=10000;
// int t;
// int visit[MAX];
// string type[4]={"L","R","S","D"};

// int change(int number,int type){
//     int ret;
//     switch (type)
//     {
//     case 0: //L
//         /* code */
//         ret= number%1000*10+number/1000;
//         break;
//     case 1://R
//         ret=(number%10)*1000+number/10;
//         break;
//     case 2://S
//         ret= ret>0? ret-1:9999;
//         break;
//     case 3://D
//         ret=(number<<1)%10000;
//     default:
//         break;
//     }
//     return ret;
// }
// string bfs(int start,int end){
//     queue<pair<int,string>> q;

//     visit[start]=true;
//     q.push(make_pair(start,""));

//     while(!q.empty()){
//         int now=q.front().first;
//         string way=q.front().second;
//         if(now==end){
//             return way;
//         }
//         q.pop();

//         /////4개 반복
//         for(int i=0;i<4;i++){
//             int temp=change(now,i);
//             if(visit[temp]==false){
//                 visit[temp]=true;
//                 q.push(make_pair(temp,way+type[i]));
//             }
//         }
//     }
//     return "";
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     cin>>t;
//     for(int i=0;i<t;i++){
//         int start,end;
//         cin>>start>>end;
        
//         memset(visit,false,sizeof(visit));

//         cout<<bfs(start,end)<<"\n";

//     }
    
//     return 0;
// }
// ////////////////////1963
// #include <iostream>
// #include <queue>
// #include <string.h>
// #include <math.h>

// using namespace std;
// const int MAX=10000;
// int t;
// bool isPrime[MAX],visit[MAX-1000];
// void eratos(){
//     for(int start=2;start<(int)sqrt(MAX)+1;start++){
//         for(int j=2;start*j<MAX;j++){
//             isPrime[start*j]=false;
//         }
//     }
// }
// int changeNumber(int number,int digit,int n){
//     int front,end,ret;
//     front=number/((int)pow(10,digit))*((int)pow(10,digit));
//     end=number%((int)pow(10,digit-1));
//     ret=front+((int)pow(10,digit-1))*n+end;
//     return ret;
// }
// int bfs(int start,int end){
//     queue<pair<int,int>> q;
//     visit[start-1000]=true;
//     q.push(make_pair(start,0));
//     while(!q.empty()){
//         int now=q.front().first;
//         int cnt=q.front().second;
//         if(now==end){
            
//             return cnt;
//         }
//         q.pop();
        
//         for(int digit=1;digit<=4;digit++){
//             for(int i=0;i<10;i++){
//                 if(digit==4 &&i==0) 
//                     continue;
//                 int next=changeNumber(now,digit,i);
//                 if(visit[next-1000]==false && isPrime[next]==true){
//                     visit[next-1000]=true;
//                     q.push(make_pair(next,cnt+1));
//                 }

//             }
//         }
        
//     }
//     return -1;
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     cin>>t;
//     memset(isPrime,true,sizeof(isPrime));
//     eratos();
//     for(int i=0;i<t;i++){
//         int start,end;
//         memset(visit,0,sizeof(visit));
//         cin>>start>>end;
//         int ret=bfs(start,end);
//         if(ret!=-1){
//             cout<<ret<<"\n";
//         }
//         else{
//             cout<<"Impossible\n";
//         }
//     }
   
//     return 0;
// }


////////////////////1697
// #include <iostream>
// #include <string.h>
// #include <queue>
// using namespace std;
// const int MAX=200000;
// int n,k;
// int cache[MAX+1];

// int bfs(){
//     queue<pair<int,int>> q;
//     q.push(make_pair(n,0));
//     cache[n]=0;
    
//     while (!q.empty())
//     {
//         int now=q.front().first;
//         int time=q.front().second;
//         if(now==k){
//             return time;
//         }
//         q.pop();

//         int next[3]={now-1,now+1,now*2};
//         for(int i=0;i<3;i++){
//             if(next[i]>=0 && next[i]<=MAX && cache[next[i]]==-1){
//                 cache[next[i]]=time+1;
//                 q.push(make_pair(next[i],time+1));
//             }
//         }
//     }
//     return -1;
// }
// int main(void) {
//     cin>>n>>k;
//     memset(cache,-1,sizeof(cache));
//     cout<<bfs()<<endl;

//     return 0;
// }


// #include <iostream>
// #include <string.h>

// using namespace std;
// const int MAX=10;
// const int INF=int(1e9);
// int n;
// int graph[MAX][MAX];
// bool visit[MAX];
// int answer=INF;
// void dfs(int s,int sum,int cnt){
//     if(cnt==n-1 && graph[s][0]!=0){
//         answer=min(answer,sum+graph[s][0]);
//     }
//     for(int i=0;i<n;i++){
//         if(graph[s][i]!=0 && visit[i]==false){
//             visit[i]=true;
//             dfs(i,sum+graph[s][i],cnt+1);
//             visit[i]=false;
//         }
//     }

    
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     memset(visit,false,sizeof(visit));
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>graph[i][j];
//         }
//     }
//     visit[0]=true;
//     dfs(0,0,0);
//     cout<<answer<<endl;
//     return 0;
// }

// // //////////////////14502
// // #include <vector>
// // #include <iostream>
// // #include <queue>
// // #include <utility>
// // using namespace std;
// // #define ROW 8
// // #define COL 8
// // int n,m;
// // int board[ROW][COL];
// // int ret=0;
// // vector<int> tmp;
// // vector<pair<int,int>> starts;

// // int dy[4]={1,-1,0,0};
// // int dx[4]={0,0,1,-1};
// // int bfs(){

// //     queue<pair<int,int>> q;
// //     int tempBoard[ROW][COL];
// //     //starts 복제함
// //     for(int i=0;i<starts.size();i++){
// //         q.push(starts[i]);
// //     }
// //     //board 복사
// //     for (int i=0;i<n;i++){
// //         for(int j=0;j<m;j++){
// //             tempBoard[i][j]=board[i][j];
// //         }
// //     }
// //     while(!q.empty()){
// //         int y=q.front().first;
// //         int x=q.front().second;
// //         q.pop();

// //         for(int i=0;i<4;i++){
// //             int ny=y+dy[i],nx=x+dx[i];
// //             if(0<=ny && ny<n && 0<=nx && nx<m && tempBoard[ny][nx]==0){
// //                 q.push(make_pair(ny,nx));
// //                 tempBoard[ny][nx]=2;
// //             }
// //         }
// //     }
// //     int retBfs=0;
// //     for(int i=0;i<n;i++){
// //         for(int j=0;j<m;j++){
// //             if(tempBoard[i][j]==0){
// //                 retBfs+=1;
// //             }
// //         }
// //     }
// //     return retBfs;
// // }
// // void makeWall(int cnt){
// //     if(cnt==3){
// //         ret=max(ret,bfs());
// //         return;
// //     }
// //     for(int i=0;i<n;i++){
// //         for (int j=0;j<m;j++){
// //             if(board[i][j]==0){
// //                 board[i][j]=1;
// //                 makeWall(cnt+1);
// //                 board[i][j]=0;
// //             }
// //         }
// //     }
// // }

// // int main(void){
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);
// //     cout.tie(0);
// //     cin>>n>>m;

// //     for(int i=0;i<n;i++){
// //         for(int j=0;j<m;j++){
// //             cin>>board[i][j];
// //             if(board[i][j]==2){
// //                 starts.push_back({i,j});

// //             }
// //         }
// //     }
// //     makeWall(0);
// //     cout<<ret<<endl;

// //     return 0;
// // }

// // // // ///////////////////////9663
// // // // #include <iostream>
// // // // #define MAX 14
// // // // using namespace std;

// // // // int n;
// // // // int state[MAX];
// // // // bool canPut(int y,int x){
// // // //     for(int i=0;i<x;i++){
// // // //         if(y==state[i]||x-i==abs(y-state[i]))
// // // //             return false;
// // // //     }
// // // //     return true;
// // // // }
// // // // int dfs(int cx){
// // // //     if(cx==n)
// // // //         return 1;
// // // //     int ret=0;
// // // //     for(int i=0;i<n;i++){
// // // //         if(canPut(i,cx)){
// // // //             state[cx]=i;
// // // //             ret+=dfs(cx+1);
// // // //         }
// // // //     }
// // // //     return ret;
// // // // }
// // // // int main(void){
// // // //     cin>>n;
// // // //     cout<<dfs(0)<<"\n";

// // // //     return 0;
// // // // }

// // // // //////////////////2143
// // // // #include <iostream>
// // // // #include <vector>
// // // // #include <map>
// // // // using namespace std;

// // // // int main(void){

// // // //     int t,n,m;
// // // //     vector<int> a; vector<int> b;
// // // //     int num;

// // // //     map<int,int> a_cache,b_cache;
// // // //     ios_base::sync_with_stdio(0);
// // // //     cin.tie(0);
// // // //     cin>>t;cin>>n;
// // // //     for(int i=0;i<n;i++){
// // // //         cin>>num;
// // // //         a.push_back(num);
// // // //     }
// // // //     cin>>m;
// // // //     for(int i=0;i<m;i++){
// // // //         cin>>num;
// // // //         b.push_back(num);
// // // //     }

// // // //     //a의 부분합
// // // //     for (int start=0;start<n;start++){
// // // //         int interval=0;
// // // //         for(int end=start;end<n;end++){
// // // //             interval+=a[end];
// // // //             if(a_cache.count(interval)!=0){
// // // //                 a_cache[interval]+=1;
// // // //             }
// // // //             else{
// // // //                 a_cache[interval]=1;
// // // //             }
// // // //         }
// // // //     }

// // // //     //a의 부분합
// // // //     for (int start=0;start<m;start++){
// // // //         int interval=0;
// // // //         for(int end=start;end<m;end++){
// // // //             interval+=b[end];
// // // //             if(b_cache.count(interval)!=0){
// // // //                 b_cache[interval]+=1;
// // // //             }
// // // //             else{
// // // //                 b_cache[interval]=1;
// // // //             }
// // // //         }
// // // //     }
// // // //     int ret=0;
// // // //     if(a_cache[t]!=0)
// // // //         ret+=a_cache[t];
// // // //     if(b_cache[t]!=0)
// // // //         ret+=b_cache[t];
// // // //     for(auto it=a_cache.begin();it!=a_cache.end();it++){
// // // //         if(b_cache.count(t-it->first)!=0)
// // // //             ret+=it->second;
// // // //     }
// // // //     cout<<ret<<"\n";
// // // //     return 0;
// // // // }

// // // // /////////////////백준 1525
// // // // // #include <iostream>
// // // // // #include <queue>
// // // // // #include <algorithm>
// // // // // #include <map>

// // // // // using namespace std;
// // // // // #define KEY "123456780"
// // // // // int main(void){
// // // // //     ios_base::sync_with_stdio(0);
// // // // //     cin.tie(0);
// // // // //     string answer="";
// // // // //     for(int i=0;i<3;i++){
// // // // //         for(int j=0;j<3;j++){
// // // // //             string num;
// // // // //             cin>>num;
// // // // //             answer+=num;
// // // // //         }
// // // // //     }

// // // // //     map<string,int> cache;
// // // // //     queue<pair<string,int>> q;
// // // // //     int dy[4]={1,-1,0,0};
// // // // //     int dx[4]={0,0,1,-1};
// // // // //     cache[answer]=1;
// // // // //     q.push(make_pair(answer,0));

// // // // //     while (!q.empty()){
// // // // //         pair<string,int> now=q.front();
// // // // //         q.pop();
// // // // //         if(now.first==KEY) {
// // // // //             cout<<now.second<<'\n';
// // // // //             return 0;
// // // // //         }

// // // // //         int index=now.first.find('0');
// // // // //         int cy=index/3,cx=index%3;
// // // // //         for(int i=0;i<4;i++){
// // // // //             int ny=cy+dy[i],nx=cx+dx[i];

// // // // //             if(0<=ny && ny<3 && 0<=nx && nx<3){
// // // // //                 string temp=now.first;
// // // // //                 swap(temp[ny*3+nx],temp[index]);
// // // // //                 if(cache.count(temp)!=0)
// // // // //                     continue;
// // // // //                 q.push(make_pair(temp,now.second+1));
// // // // //                 cache[temp]=1;
// // // // //             }
// // // // //         }

// // // // //     }
// // // // //     cout<<-1<<"\n" ;
// // // // //     return 0;
// // // // // }
