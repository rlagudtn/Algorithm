// //////////////3090(4)
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int n,t,arr[100001],copyArr[100001],resultArr[100001];

// bool mediate(int gap){
//     int cnt=0;
//     copy(arr,arr+n,copyArr);
//     /////////오른쪽으로
//     for(int i=0;i<n-1;i++){
//         if(copyArr[i+1]-copyArr[i]>gap){
//             cnt+=copyArr[i+1]-(copyArr[i]+gap);
//             copyArr[i+1]=copyArr[i]+gap;
//         }
//     }
//     //왼쪽으로
//     for(int i=n-1;i>0;i--){
//         if(copyArr[i-1]-copyArr[i]>gap){
//             cnt+=copyArr[i-1]-(copyArr[i]+gap);
//             copyArr[i-1]=copyArr[i]+gap;
//         }
//     }
//     if(cnt<=t)
//         return true;
//     return false;

// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin>>n>>t;
    
//     for(int i=0;i<n;i++)
//         cin>>arr[i];
    
//     int start=0,end=int(1e9);
//     int mid;
//     while(start<=end){
//         mid=(start+end)/2;
//         if(mediate(mid)){
//             copy(copyArr,copyArr+n,resultArr);
//             end=mid-1;
//         }
//         else    
//             start=mid+1;
//     }
    
//     for(int i=0;i<n;i++)
//         cout<<resultArr[i]<<" ";
//     cout<<"\n"; 
// }

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
//////////////////2585(2)
//bfs 핵심 아이디어: 제한된 거리 안에 있으면 인접한 지점으로 본다.





/////////1939(1) 중량제한
/////코드 정리
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
// int n,m,factory1,factory2;
// vector<vector<pair<int,int>>> bridges(100001);
// bool bfs(int w){
//     queue<int> q;
//     int visit[n+1]={0,};
    
//     q.push(factory1);
//     visit[factory1]=1;
//     while(!q.empty()){
//         int now=q.front();
//         if(now==factory2)
//             return true;
//         q.pop();
        
//         for(int i=0;i<bridges[now].size();i++){
//             if(bridges[now][i].second>=w&&visit[bridges[now][i].first]==0){
//                 q.push(bridges[now][i].first);
//                 visit[bridges[now][i].first]=1;
//             }
//         }
//     }
//     return false;
// }
// int main(void){
//     cin>>n>>m;
//     int a,b,c;
//     for(int i=0;i<m;i++){
//         cin>>a>>b>>c;
//         bridges[a].push_back({b,c});
//         bridges[b].push_back({a,c});
//     };
//     cin>>factory1>>factory2;

//     int start,end,mid,answer;
//     start=1,end=int(1e9);
//     while(start<=end){
//         mid=(start+end)/2;
//         if(bfs(mid)){
//             start=mid+1;
//             answer=mid;
//         }
//         else
//             end=mid-1;
//     }
//     cout<<answer<<"\n";
//     return 0;
// }
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
//////////////3079(3)
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_V=100000;
int arr[MAX_V];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    long long start=0,end=(*max_element(arr,arr+n))*m,mid,sum,answer=end;
    ///////answer를 end로 초기화 해줘야함.
    ////////end의 최대값을 정확히 지정해줘야함
    while(start<=end){
        mid=(start+end)/2;
        sum=0;
        for(int i=0;i<n;i++)
            sum+=mid/arr[i];
        if(sum>=m){
            answer=mid;
            end=mid-1;
        }
        else    
            start=mid+1;
    }
    cout<<answer<<"\n";
    return 0;
}
///////2585(2)
// #include <iostream>
// #include <queue>
// #include <math.h>
// using namespace std;

// struct Location{
//     int x;
//     int y;
// };
// Location pos[1001];
// Location END={10000,10000};
// int n,k;
// double getDist(const Location& a,const Location& b){
//     return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
// }
// bool canVisit(int fuel){
//     queue<pair<int,int>> q;
//     bool visit[n+1]={0,};
//     q.push({0,0});
//     visit[0]=1;

//     while(!q.empty()){
//         int now=q.front().first;
//         int cnt=q.front().second;
//         q.pop();

//         if(getDist(pos[now],END)<=fuel*10 &&cnt<=k)
//             return true;
//         for(int i=1;i<=n;i++){
//             if(visit[i]==0 &&getDist(pos[now],pos[i])<=fuel*10){
//                 q.push({i,cnt+1});
//                 visit[i]=1;
//             }
//         }
//     }
//     return false;
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin>>n>>k;
//     for(int i=1;i<=n;i++)
//         cin>>pos[i].x>>pos[i].y;
    
//     int start=1,end=2000,mid,answer;
//     while(start<=end){
//         mid=(start+end)/2;
//         if(canVisit(mid)){
//             answer=mid;
//             end=mid-1;
//         }
//         else    
//             start=mid+1;
//     }
//     cout<<answer<<"\n";
//     return 0;
// }