/////////////////////14889
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
int total,rowSum,colSum;
const int MAX=20;
int n;
int answer=int(1e9);
int board[MAX][MAX];
int rows[MAX];
int cols[MAX];

void dfs(int idx,int cnt){
    if(cnt==n/2){
        int sum=abs(total-rowSum-colSum);
        answer=min(answer,sum);
    }
    for(int i=idx+1;i<n;i++){
        rowSum+=rows[i];
        colSum+=cols[i];
        dfs(i,cnt+1);
        rowSum-=rows[i];
        colSum-=cols[i];
    }

}
int main (void){
    cin>>n;
    int temp;
    total=rowSum=colSum=0;

    memset(rows,0,sizeof(rows));
    memset(cols,0,sizeof(cols));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>temp;
            total+=temp;
            rows[i]+=temp;
            cols[j]+=temp;
        }
    }
    dfs(-1,0);
    cout<<answer<<"\n";

    return 0;
}



// // /////////////2_4 //2580
// // #include <iostream>
// // #include <vector>
// // #include <string>

// // using namespace std;

// // const int SIZE=9;
// // int board[SIZE][SIZE];
// // vector<pair<int,int>> empties;
// // bool found=false;
// // void printBoard(){
// //     for(int i=0;i<SIZE;i++){
// //         for(int j=0;j<SIZE;j++){
// //             cout<<board[i][j]<<" ";
// //         }
// //         cout<<"\n";
// //     }
// // }
// // bool canPut(int y,int x){
// //     int value=board[y][x];
// //     // cout<<"canPut"<<y<<" "<<x<<" "<<value<<"\n";
// //     // printBoard();
// //     for(int i=0;i<SIZE;i++){
// //         if(board[y][i]==value && i!=x)
// //             return false;
// //         if(board[i][x]==value && i!=y)
// //             return false;
// //     }
// //     int sr=y/3*3;int sc=x/3*3;
    
// //     for(int i=0;i<3;i++){
// //         for(int j=0;j<3;j++){
// //             int cy=sr+i;int cx=sc+j;
// //             if(board[sr+i][sc+j]==value&& cy!=y &&cx!=x)
// //                 return false;
// //         }
// //     }
// //     return true;
// // }
// // void dfs(int idx){
    
// //     if(idx==empties.size()){
// //         printBoard();
// //         found=true;
// //         return;
// //     }
// //     int cy=empties[idx].first;int cx=empties[idx].second;

// //     for(int i=1;i<=SIZE;i++){
// //         board[cy][cx]=i;
// //         if(canPut(cy,cx)){
// //             dfs(idx+1);
// //             if(found)
// //                 return;
// //         }
// //         board[cy][cx]=0;
// //     }

// // }

// // int main(void){
// //     for(int i=0;i<SIZE;i++){
// //         for(int j=0;j<SIZE;j++){
// //             cin>>board[i][j];
// //             if(board[i][j]==0){
// //                 empties.push_back(make_pair(i,j));
// //             }
// //         }
// //     }
// //     dfs(0);
// //     return 0;
// // }



// ///////////////2661
// #include <iostream>
// #include <string>

// using namespace std;

// int n;
// bool isfound=false;
// bool isGoodNumber(string number){
//     int start,end;
//     string s1,s2;
//     int length=number.length()/2;
//     for(int i=1;i<=length;i++){
//         start=number.length()-i;
//         s1=number.substr(start,i);
//         start-=i;
//         s2=number.substr(start,i);
//         if(s1==s2)
//             return false;
//     }
//     return true;
// }
// void dfs(string number){
//     if(isGoodNumber(number)==false)
//         return ;
//     if(number.length()==n){
//         cout<<number<<"\n";
//         isfound=true;
//         return ;
//     }

//     for(int i=1;i<=3;i++){
//         dfs(number+to_string(i));
//         if(isfound)
//             return;
//     }

// }
// int main(void){
//     cin>>n;
//     dfs("");
//     return 0;
// }
//////////////////////15686
// #include <iostream>
// #include <vector>
// #include <string.h>
// #include <math.h>
// using namespace std;

// int n,m;
// int chick_n;
// const int MAX=50;
// const int INF=int(1e9);
// int city[MAX][MAX];

// int answer=INF;
// vector<pair<int,int>> houses;
// vector<pair<int,int>> chickens;
// int visit[MAX];
// void dfs(int idx,int cnt){
    
//     if(cnt==m){
//         int totalDist=0;
//         //집마다의 치킨거리를 구함
//         for(int i=0;i<houses.size();i++){
//             int minDist=INF;
//             for(int j=0;j<chick_n;j++){
//                 if(visit[j]==0){
//                     int dist=abs(houses[i].first-chickens[j].first)+abs(houses[i].second-chickens[j].second);
//                     minDist=min(minDist,dist);
//                 }
//             }
//             totalDist+=minDist;
//         }
//         answer=min(answer,totalDist);
//         return;
//     }

//     for(int start=idx+1;start<chick_n;start++){
//         visit[start]=1;
//         dfs(start,cnt+1);
//         visit[start]=0;
//     }
// }

// int main(void){
//     cin>>n>>m;
//     int info;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>info;
//             city[i][j]=info;
//             switch (info)
//             {
//             case 1:
//                 houses.push_back(make_pair(i,j));
//                 break;
//             case 2:
//                 chickens.push_back(make_pair(i,j));
//                 break;
//             default:
//                 break;
//             }
//         }
//     }
    
//     m=chickens.size()-m;
//     chick_n=chickens.size();
    
//     memset(visit,0,sizeof(visit));
    
//     dfs(-1,0);
//     cout<<answer<<"\n";

//     return 0;
// }

// // // //////////////////15686


// // // #include <stdio.h>
// // // #include <vector>
// // // #include <math.h>
// // // #include <string.h>
// // // using namespace std;

// // // const int MAX=50;
// // // int n,m,answer;
// // // vector<pair<int,int>> home;
// // // vector<pair<int,int>> hop;
// // // int city[MAX][MAX];
// // // vector<int> picked(MAX,1);
// // // void dfs(int cnt,int idx){
// // //     if(cnt==m){
// // //         //도시 치킨 거리 구하고 min인지 확인
// // //         int sum,min_val,dist;
// // //         sum=0;
// // //         for(int i=0;i<home.size();i++){
// // //             min_val=int(1e9);
// // //             for(int j=0;j<hop.size();j++){
// // //                 if(picked[j]!=0){
// // //                     dist=abs(home[i].first-hop[j].first)+abs(home[i].second-hop[j].second);
// // //                     if(min_val>dist)
// // //                         min_val=dist;
// // //                 }
// // //             }

// // //             sum+=min_val;
// // //         }
// // //         if(answer>sum)
// // //             answer=sum;

// // //     }
    
// // //     for(int i=idx+1;i<hop.size();i++){
// // //         picked[i]=0;
// // //         dfs(cnt+1,i);
// // //         picked[i]=1;
// // //     }
// // // }
// // // int main(void){
// // //     int temp;
// // //     scanf("%d %d",&n,&m);
    
// // //     for(int i=0;i<n;i++){
// // //         for(int j=0;j<n;j++){
// // //             scanf("%d",&temp);
// // //             city[i][j]=temp;
// // //             if(temp==1){
// // //                 home.push_back(make_pair(i,j));
// // //             }
// // //             else if(temp==2){
// // //                 hop.push_back(make_pair(i,j));

// // //             }
// // //         }
// // //     }
// // //     m=hop.size()-m; //제거해야할 수
// // //     answer=int(1e9);
// // //     dfs(0,-1);
// // //     printf("%d\n",answer);
// // //     return 0;
// // // }
// // // #include <iostream>
// // // #include <vector>

// // // using namespace std;

// // // int n,answer;
// // // int board[20][20];
// // // bool picked[20];

// // // void dfs(int cnt,int cur){
// // //     if(cnt==n/2){
// // //         //팀간 차이를 구한다
// // //         int a=0;int b=0;
// // //         for(int i=0;i<n;i++){
// // //             for(int j=i+1;j<n;j++){
// // //                 if(picked[i] &&picked[j]){
// // //                     a+=board[i][j];
// // //                     a+=board[j][i];
// // //                 }
// // //                 else if(!picked[i] &&!picked[j]){
// // //                     b+=board[i][j];
// // //                     b+=board[j][i];
// // //                 }
// // //             }
// // //         }
// // //         if(answer>abs(a-b))
// // //             answer=abs(a-b);
// // //     }

// // //     for(int i=cur+1;i<n;i++){
// // //         if(picked[i]==0){
// // //             picked[i]=1;
// // //             dfs(cnt+1,i);
// // //             picked[i]=0;
// // //         }
// // //     }
// // // }
// // // int main(void){
// // //     scanf("%d",&n);
// // //     for(int i=0;i<n;i++){
// // //         for(int j=0;j<n;j++){
// // //             scanf("%d",&board[i][j]);
// // //         }
// // //     }
// // //     answer=int(1e9);
// // //     dfs(0,-1);
// // //     printf("%d\n",answer);

    
// // //     return 0;
// // // }