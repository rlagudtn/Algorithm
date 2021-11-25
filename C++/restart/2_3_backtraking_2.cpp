// ///////////////2661
// #include <iostream>
// #include <string>

// using namespace std;

// int n;
// bool isGoodNumber(int digit,string number){
//     int start,end;
//     string s1,s2;
//     for(int i=1;i<=number.length()/2;i++){
//         start=number.length()-i;
//         s1=number.substr(start,i);
//         start-=i;
//         s2=number.substr(start,i);
//         if(s1==s2){
//             return false;
//         }
//     }
//     return true;
// }
// string dfs(int digit,string number){
//     if(isGoodNumber(digit,number)==false)
//         return "";
//     if(digit==n){
//         return number;
//     }

//     string ret=dfs(digit+1,number+"1");
//     if(ret!="")
//         return ret;
//     ret=dfs(digit+1,number+"2");
//     if(ret!="")
//         return ret;
//     ret=dfs(digit+1,number+"3");
//     if(ret!="")
//         return ret;

//     return "";
// }
// int main(void){
//     cin>>n;
//     cout<<dfs(0,"")<<"\n";
//     return 0;
// }

// // //////////////////15686
// // #include <stdio.h>
// // #include <vector>
// // #include <math.h>
// // #include <string.h>
// // using namespace std;

// // const int MAX=50;
// // int n,m,answer;
// // vector<pair<int,int>> home;
// // vector<pair<int,int>> hop;
// // int city[MAX][MAX];
// // vector<int> picked(MAX,1);
// // void dfs(int cnt,int idx){
// //     if(cnt==m){
// //         //도시 치킨 거리 구하고 min인지 확인
// //         int sum,min_val,dist;
// //         sum=0;
// //         for(int i=0;i<home.size();i++){
// //             min_val=int(1e9);
// //             for(int j=0;j<hop.size();j++){
// //                 if(picked[j]!=0){
// //                     dist=abs(home[i].first-hop[j].first)+abs(home[i].second-hop[j].second);
// //                     if(min_val>dist)
// //                         min_val=dist;
// //                 }
// //             }

// //             sum+=min_val;
// //         }
// //         if(answer>sum)
// //             answer=sum;

// //     }
    
// //     for(int i=idx+1;i<hop.size();i++){
// //         picked[i]=0;
// //         dfs(cnt+1,i);
// //         picked[i]=1;
// //     }
// // }
// // int main(void){
// //     int temp;
// //     scanf("%d %d",&n,&m);
    
// //     for(int i=0;i<n;i++){
// //         for(int j=0;j<n;j++){
// //             scanf("%d",&temp);
// //             city[i][j]=temp;
// //             if(temp==1){
// //                 home.push_back(make_pair(i,j));
// //             }
// //             else if(temp==2){
// //                 hop.push_back(make_pair(i,j));

// //             }
// //         }
// //     }
// //     m=hop.size()-m; //제거해야할 수
// //     answer=int(1e9);
// //     dfs(0,-1);
// //     printf("%d\n",answer);
// //     return 0;
// // }
// // #include <iostream>
// // #include <vector>

// // using namespace std;

// // int n,answer;
// // int board[20][20];
// // bool picked[20];

// // void dfs(int cnt,int cur){
// //     if(cnt==n/2){
// //         //팀간 차이를 구한다
// //         int a=0;int b=0;
// //         for(int i=0;i<n;i++){
// //             for(int j=i+1;j<n;j++){
// //                 if(picked[i] &&picked[j]){
// //                     a+=board[i][j];
// //                     a+=board[j][i];
// //                 }
// //                 else if(!picked[i] &&!picked[j]){
// //                     b+=board[i][j];
// //                     b+=board[j][i];
// //                 }
// //             }
// //         }
// //         if(answer>abs(a-b))
// //             answer=abs(a-b);
// //     }

// //     for(int i=cur+1;i<n;i++){
// //         if(picked[i]==0){
// //             picked[i]=1;
// //             dfs(cnt+1,i);
// //             picked[i]=0;
// //         }
// //     }
// // }
// // int main(void){
// //     scanf("%d",&n);
// //     for(int i=0;i<n;i++){
// //         for(int j=0;j<n;j++){
// //             scanf("%d",&board[i][j]);
// //         }
// //     }
// //     answer=int(1e9);
// //     dfs(0,-1);
// //     printf("%d\n",answer);

    
// //     return 0;
// // }