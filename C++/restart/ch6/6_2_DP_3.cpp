// //////////////2631 (4)
// #include <iostream>
// #include <vector>

// using namespace std;
// int n,arr[200];
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin>>n;
//     vector<int> lis;
//     lis.push_back(-1);
//     for(int i=0;i<n;i++)
//         cin>>arr[i];
//     for(int i=0;i<n;i++){
//         if(arr[i]>lis.back())
//             lis.push_back(arr[i]);
//         else{
//             int index=lower_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
//             lis[index]=arr[i];
//         }
//     }
//     cout<<n-lis.size()+1<<"\n";
//     return 0;
// }

////////////11066(3)
// #include <iostream>
// #include <string.h>

// using namespace std;
// int INF=1e9;
// int t,n,arr[501],sum[501];
// int cache[501][501];
// int dfs(int start,int end){
//     if(start==end)
//         return 0;

//     int& ret=cache[start][end];
//     if(ret!=-1)
//         return ret;
//     ret=INF;
//     for(int i=0;start+i<end;i++){
//         ret=min(ret,dfs(start,start+i)+dfs(start+i+1,end)
//         +sum[end]-sum[start-1]);
//     }

//     return ret;
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     cin>>t;
//     for(int k=0;k<t;k++){
//         cin>>n;
//         arr[0]=0;
//         memset(sum,0,sizeof(sum));
//         memset(cache,-1,sizeof(cache));
//         for(int i=1;i<=n;i++){
//             cin>>arr[i];
//             sum[i]=sum[i-1]+arr[i];
//         }
        
//         cout<<dfs(1,n)<<"\n";
//     }
// }
///11066(3)
#include <iostream>
#include <string.h>

using namespace std;
const long long INF=1e18;
int t,n,arr[501];
long long cache[501][501]={0,};
int sum[501];
long long getCost(int start,int end){
    if(start==end)
        return 0;
    long long& ret=cache[start][end];
    if(ret!=-1)
        return ret;
    ret= INF;
    for(int i=start;i<end;i++){
        ret=min(ret,getCost(start,i)+getCost(i+1,end)+sum[end]-sum[start-1]);
    }
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>k;
        memset(cache,-1,sizeof(cache));
        memset(sum,0,sizeof(sum));
        sum[0]=0;
        for(int j=1;j<=k;j++){
            cin>>arr[j];
            sum[j]=sum[j-1]+arr[j];
        }
        cout<<getCost(1,k)<<"\n";
    }
    return 0;
}

///////////2618 (2)
// #include <iostream>
// #include <string.h>

// using namespace std;
// int n,w,cache[1001][1001];
// pair<int,int> pos[1001];
// int answer[1001][1001];
// int distance(int a,int b){
//     int dist=0;
//     if(a>0 &&b>0)
//         dist=abs(pos[a].first-pos[b].first)+abs(pos[a].second-pos[b].second);
//     else if(a==0){ // 경찰차 1이 첫 위치에서 출발
//         dist=(pos[b].first-1)+(pos[b].second-1); 
//     }
//     else if(b==0){ //경찰차 2가 첫 위치에서 출발
//         dist=(n-pos[a].first)+(n-pos[a].second);
//     }
//     return dist;
// }
// int dfs(int i,int j){
//     if(i==w||j==w)
//         return 0;
//     int& ret=cache[i][j];
//     if(ret!=-1)
//         return ret;
//     int next=max(i,j)+1;
//     int c1=dfs(next,j)+distance(i,next);
//     int c2=dfs(i,next)+distance(next,j);
//     if(c1>c2)
//         answer[i][j]=2;
//     else
//         answer[i][j]=1;
//     ret=min(c1,c2);
//     return ret;
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     cin>>n>>w;
//     memset(cache,-1,sizeof(cache));
//     memset(answer,-1,sizeof(answer));
//     for(int i=1;i<=w;i++)
//         cin>>pos[i].first>>pos[i].second;
//     cout<<dfs(0,0)<<"\n";
//     int c1=0,c2=0;
//     for(int i=0;i<w;i++){
//         cout<<answer[c1][c2];
//         if(answer[c1][c2]==1){
//             c1=i+1;
//         }
//         else
//             c2=i+1;
        
//         // cout<<answer[c1][c2]<<"\n";
//         // if(answer[c1][c2]==1){
//         //     c1=i+1;
//         // }
//         // else {
//         //     c2=i+1;
//         // }
//     }
//     return 0;
// }