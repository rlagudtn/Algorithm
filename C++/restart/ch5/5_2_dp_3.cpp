////////////////////11051(6)
// #include <iostream>
// #include <string.h>

// using namespace std;
// int cache[1001][1001];
// int dfs(int n,int k){
//     if(k==0 ||k==n)
//         return 1;
//     int& ret=cache[n][k];
//     if(ret!=-1)
//         return ret;
    
//     return ret=(dfs(n-1,k-1)+dfs(n-1,k))%10007;
// }
// int main(void){
//     int n,k;
//     cin>>n>>k;
//     memset(cache,-1,sizeof(cache));
//     cout<<dfs(n,k)<<"\n";
//     return 0;
// }
// ///////////////9252(5)
// #include <iostream>
// #include <string.h>
// #include <vector>
// using namespace std;
// int lcs[1001][1001];
// int main(void){
//     string s1,s2;
//     cin>>s1>>s2;
//     int n,m;
//     n=s1.size(),m=s2.size();
//     s1="0"+s1,s2="0"+s2;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(s1[i]==s2[j])
//                 lcs[i][j]=lcs[i-1][j-1]+1;
//             else
//                 lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
//         }
//     }
//         cout<<lcs[n][m]<<"\n";
        
        
//         if(lcs[n][m]!=0){
//             vector<char> answer;
//             int i=n,j=m;
//             while(lcs[i][j]>0){
//                 if(lcs[i][j]==lcs[i-1][j]){
//                     i--;
//                 }
//                 else if(lcs[i][j]==lcs[i][j-1])
//                     j--;
//                 else {
//                     answer.push_back(s1[i]);
//                     i--,j--;
//                 }
//             }
//             for(int i=answer.size()-1;i>=0;i--)
//                 cout<<answer[i];
//             cout<<"\n";
//         }


//     return 0;
// }

/////////////9251(4)
// #include <iostream>
// #include <string.h>

// using namespace std;
// int lcs[1001][1001];
// int main(void){
//     string s1,s2;
//     cin>>s1>>s2;
//     s1="0"+s1;s2="0"+s2;
//     memset(lcs,0,sizeof(lcs));

//     for(int i=1;i<s1.size();i++){
//         for(int j=1;j<s2.size();j++){
//             if(s1[i]==s2[j])
//                 lcs[i][j]=lcs[i-1][j-1]+1;
//             else
//                 lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
//         }
//     }
//     cout<<lcs[s1.size()-1][s2.size()-1]<<"\n";
//     return 0;
// }

// ///////////////12015 (3)
#include <iostream>
#include <vector>

using namespace std;
int arr[1000000];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)    
        cin>>arr[i];

    vector<int> lis;
    lis.push_back(0);
    
    for(int i=0;i<n;i++){
        if(arr[i]>lis.back())
            lis.push_back(arr[i]);
        else{
            int index=lower_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
            lis[index]=arr[i];
        }
    }
    cout<<lis.size()-1<<"\n";   
    return 0;
}



// /////////////1520(2)
// #include <iostream>
// #include <string.h>

// using namespace std;
// int m,n;
// int arr[500][500],visit[500][500]={0,};
// long long cache[500][500];
// int dy[4]={0,0,1,-1},dx[4]={1,-1,0,0};
// int dfs(int y,int x){
//     if(y==m-1 && x==n-1)
//         return 1;
//     long long& ret=cache[y][x];
//     if(ret!=-1)
//         return ret;
//     int ny,nx;
//     ret=0;
//     for(int i=0;i<4;i++){
//         ny=y+dy[i],nx=x+dx[i];
//         if(ny>=0 &&ny<m &&nx>=0 && nx<n && visit[ny][nx]==0 &&arr[ny][nx]<arr[y][x]){
//             visit[ny][nx]=1;
//             ret+=dfs(ny,nx);
//             visit[ny][nx]=0;
//         }
//     }
//     return ret;
// }

// int main(void){
//     cin>>m>>n;
//     for(int i=0;i<m;i++)
//         for(int j=0;j<n;j++)
//             cin>>arr[i][j];
//     memset(cache,-1,sizeof(cache));
//     cout<<dfs(0,0)<<"\n";
//     return 0;
// }

///////////1890(1) 점프
// #include <iostream>
// #include <string.h>

// using namespace std;
// int n;
// long long cache[100][100];
// int arr[100][100];
// int dy[2]={1,0},dx[2]={0,1};
// long long dfs(int y,int x){
//     if(y==n-1 &&x==n-1)
//         return 1;
    
//     long long& ret=cache[y][x];
//     if(ret!=-1)
//         return ret;
    
//     int ny,nx;
//     ret=0;
//     for(int i=0;i<2;i++){
//         ny=y+dy[i]*arr[y][x];nx=x+dx[i]*arr[y][x];
//         if(ny>=n || nx>=n)
//             continue;
//         ret+=dfs(ny,nx);
//     }
//     return ret;
// }

// int main(void){
//     cin>>n;
//     for(int i=0;i<n;i++)
//         for(int j=0;j<n;j++)
//             cin>>arr[i][j];
    
//     memset(cache,-1,sizeof(cache));
//     cout<<dfs(0,0)<<"\n";
//     return 0;
// }