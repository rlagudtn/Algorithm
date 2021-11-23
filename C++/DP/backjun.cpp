////2156
// #include <iostream>
// #include <string.h>

// using namespace std;
// const int MAX=10000;
// int n,wines[MAX],cache[MAX];
// int drink(int col){
//     if(col==n-1)
//         return
//     if(col>=n-1)
//         return 0;
//     int& ret=cache[col];
//     if(ret!=-1)
//         return ret;
//     ret=max(drink(col+2),drink(col+3)+wines[col+1])+wines[col];
//     return ret;
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);


//     return 0;
// }

// ////9465
// #include <iostream>
// #include <string.h>

// using namespace std;
// const int MAX=100000;
// int t,n,board[2][MAX],cache[2][MAX];


// int stick(int row,int col){
//     if(col>=n)
//         return 0;
//     int& ret=cache[row][col];
//     if(ret!=-1) 
//         return ret;
//     ret=max(stick(!row,col+1),stick(!row,col+2))+board[row][col];

//     return ret;
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     cin>>t;
//     for(int k=0;k<t;k++){
//         cin>>n;
//         memset(cache,-1,sizeof(cache));
//         for(int i=0;i<2;i++)
//             for(int j=0;j<n;j++)
//                 cin>>board[i][j];
//         cout<<max(stick(0,0),stick(1,0))<<endl;
//     }
//     return 0;
// }
// ///////////////////////10819
// #include <iostream>
// #include <string.h>

// #include <vector>
// using namespace std;
// int n;

// vector<int> arr;
// vector<int> picked;
// bool visited[8];
// int result=0;

// int cal(vector<int>& arr){
//     int ret=0;
//     int i;
//     for(i=0;i+1<arr.size();i++){
//         ret+=abs(arr[i]-arr[i+1]);
//     }
   
//     return ret;
// }
// void dfs(vector<int>& picked){
//     if(picked.size()==n){
//         result=max(result,cal(picked));
//     }

//     for(int i=0;i<arr.size();i++){
//         if(visited[i]==false){
//             visited[i]=true;
//             picked.push_back(arr[i]);
//             dfs(picked);
//             visited[i]=false;
//             picked.pop_back();
//         }
//     }

// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin>>n;

//     for(int i=0;i<n;i++){
//         int temp;
//         cin>>temp;
//         arr.push_back(temp);

//     }
//     memset(visited,false,sizeof(visited));
//     dfs(picked);
//     cout<<result<<endl;
//     return 0;
// }

// /////////////////////11057
// #include <iostream>
// #include <string.h>

// using namespace std;
// const int MAX=1000;
// const int MODE=10007;
// int n;
// int cache[MAX+2][10];

// int dfs(int size,int end){
//     if(size==1)
//         return cache[size][end]=1;
//     int& ret=cache[size][end];
//     if(ret!=-1) return ret;
//     ret=0;
//     for(int i=0;i<10;i++){
//         if(i<=end){
//             ret+=dfs(size-1,i);
//             ret%=MODE;
//         }
//     }
//     return ret;
// }
// int main(void){
//     cin>>n;
//     memset(cache,-1,sizeof(cache));
//     int answer=dfs(n+1,9);
//     cout<<answer<<endl;

//     return 0;
// }


// // ///////////////////////10844
// // #include <iostream>
// // #include <string.h>
// // using namespace std;
// // const int MAX=100;
// // const long long MODE=int(1e9);
// // int n;
// // long long cache[MAX+1][10];
// // long long dfs(int size,int end){
// //     //기저사례
// //     if(size==1)
// //         return cache[size][end];

// //     long long& ret=cache[size][end];
// //     if(ret!=-1)
// //         return ret;
// //     ret=0;
// //     if(end<9)
// //         ret+=dfs(size-1,end+1);
// //     if(end>0)
// //         ret+=dfs(size-1,end-1);

// //     return ret%MODE;
    
// // }
// // int main(void){
// //     cin>>n;
// //     memset(cache,-1,sizeof(cache));
// //     cache[1][0]=0;
// //     for (int i=1;i<10;i++)
// //         cache[1][i]=1;
    
// //     long long ans=0;
// //     for(int i=0;i<10;i++)
// //         ans+=dfs(n,i);
// //         ans%=MODE;
// //     cout<<ans<<endl;
// //     return 0;
// // }


// // ////////////////////////11727
// // #include <iostream>
// // #include <string.h>

// // using namespace std;
// // const int MAX=1001;
// // const int MODE=10007;
// // int n,cache[MAX];
// // int tiling2(int n){
// //     if(n<=1)
// //         return cache[n]=1;
// //     int& ret=cache[n];
// //     if(ret!=-1) 
// //         return ret;
// //     ret=(tiling2(n-1)+tiling2(n-2)*2)%MODE;
// //     return ret;
// // }
// // int main(void){
// //     cin>>n;
// //     memset(cache,-1,sizeof(cache));
// //     cout<<tiling2(n)<<"\n" ;

// //     return 0;
// // }


// // ///////////////////////1462 1로 만들기
// // #include <iostream>
// // #include <string.h>

// // using namespace std;
// // const int MAX=1000001;

// // int n,cache[MAX];
// // int makeOne(int n){
// //     //기저사례
// //     if(n==1){
// //         return 0;
// //     }
// //     int& ret=cache[n];
// //     if(ret!=-1)
// //         return ret;
// //     ret=MAX;
// //     if(n%3==0)
// //         ret=min(ret,makeOne(n/3));
// //     if(n%2==0)
// //         ret=min(ret,makeOne(n/2));
// //     ret=min(ret,makeOne(n-1))+1;

// //     return ret;
// // }
// // int main(void){
// //     cin>>n;
// //     memset(cache,-1,sizeof(cache));
// //     cout<<makeOne(n)<<"\n";

// //     return 0;
// // }

// // // ////////////////////11726 타일링

// // // #include <iostream>
// // // #include <string.h>
// // // using namespace std;
// // // const int MAX=10001;

// // // int n;
// // // int cache[MAX];
// // // const int MODE=10007;
// // // int tiling(int n){
// // //     if(n<=1)
// // //         return 1;
// // //     int& ret=cache[n];
// // //     if(ret!=-1)
// // //         return ret;
// // //     ret=(tiling(n-1)+tiling(n-2))%MODE;
// // //     return ret;
    
// // // }
// // // int main(void){
// // //     cin>>n;
// // //     memset(cache,-1,sizeof(cache));
// // //     cout<<tiling(n)<<"\n";
// // //     return 0;
// // // }

// // // /////////////////////////////9465
// // // #include <iostream>
// // // #include <string.h>
// // // #define MAX 100000
// // // using namespace std;
// // // int cache[2][MAX];
// // // int board[2][MAX];
// // // int t,n;

// // // int dfs(int y,int x){
// // //     if(x>=n) 
// // //         return 0;

// // //     int& ret=cache[y][x];
// // //     if(ret!=-1) 
// // //         return ret;
// // //     int ny=!y;
// // //     ret=max(dfs(ny,x+1),dfs(ny,x+2))+board[y][x];
// // //     return ret;
// // // }
// // // int main(void){
// // //     cin>>t;
// // //     for(int i=0;i<t;i++){
// // //         cin>>n;
// // //         memset(cache,-1,sizeof(cache));
// // //         memset(board,0,sizeof(board));
// // //         for(int y=0;y<2;y++){
// // //             for (int x=0;x<n;x++){
// // //                 cin>>board[y][x];
// // //             }
// // //         }
// // //         cout<<max(dfs(0,0),dfs(0,1))<<"\n";
// // //     }
   
// // //     return 0;
// // // }
// // // ///////////////////////2193
// // // #include <iostream>
// // // using namespace std;
// // // int main(void){
// // //     int n;
// // //     cin>>n;
// // //     long long cache[90][2];
// // //     cache[0][0]=0,cache[0][1]=1;
// // //     for (int i=1;i<n;i++){
// // //         cache[i][0] =cache[i-1][0]+cache[i-1][1];
// // //         cache[i][1] =cache[i-1][0];
// // //     }
// // //     cout<<cache[n-1][0]+cache[n-1][1]<<endl;
// // //     return 0;
// // // }
// // // #include <iostream>
// // // using namespace std;
// // // int d[1000000];

// // // int main(void){
// // //     int n;
// // //     cin>>n;
    
// // //     fill_n(d,1000000,-1);
// // //     d[1]=0;
// // //     for(int i=2;i<=n;i++){
// // //         d[i]=d[i-1]+1;
// // //         if(i%3==0) d[i]=min(d[i],d[i/3]+1);
// // //         if(i%2==0) d[i]=min(d[i],d[i/2]+1);
// // //     }
// // //     cout<<d[n];
    
// // //     return 0;
// // // }