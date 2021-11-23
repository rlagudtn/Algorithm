////////2번

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int MAX=1000;
const int INF=int(1e9);
int n;
int edge[MAX+1][MAX+1][3];
int parent[MAX+1];
int findParent(int now){
    if(parent[now]!=now)
        parent[now]=findParent(parent[now]);
    return parent[now];
}
void unionGroup(int a,int b){
    a=findParent(a);
    b=findParent(b);
    if (a<b)
        parent[b]=a;
    else
        parent[a]=b;
}
int main() {
    int a,b,dist;
    memset(edge,0,sizeof(edge));
    
    cin>>n;
    for(int i=0;i<n+1;i++){
        parent[i]=i;
    }
    //////그래프 초기화
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>dist;
        for(int j=0;j<3;j++){
            if(edge[a][b][j]==0){
                edge[a][b][j]=-dist;
                break;
            }
        }
        for(int j=0;j<3;j++){
            if(edge[b][a][j]==0){
                edge[b][a][j]=-dist;
                break;
            }
        }
    }


    //최소 신장트리
    
}

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int pivot=0;
//     int left,right,enter;
//     enter=left=right=0;

//     string input,key;
//     cin>>input>>key;
//     /////////////입력 예외 처리해줄 것
//     int length=input.length();
//     if(length<7 || length>51){
//         cout<<-1<<endl;
//         return 0;
//     }
//     if(key.length()<2 || key.length()>82){
//         cout<<-1<<endl;
//         return 0;
//     }
//     ///////////

//     for(int i=0;i<key.length();i++){
//         int ldist,rdist;
//         bool isNone=true;
//         for(int j=0;j<input.length();j++){
//             int next=(pivot+j)%length;
//             if(input[next]==key[i]){
//                 rdist=j;
//                 isNone=false;
//                 break;
//             }
//         }
//         for(int j=0;j<input.length();j++){
//             int next=(pivot-j+length)%length;
//             if(input[next]==key[i]){
//                 ldist=j;
//                 isNone=false;
//                 break;
//             }
//         }
//         if(isNone==true){
//             cout<<-1<<endl;
//             return 0;
//         }
//         if(ldist<rdist){
//             right+=ldist;
//             pivot=(pivot-ldist+length)%length;
//         }
//         else{
//             left+=rdist;
//             pivot=(pivot+rdist)%length;

//         }
//         enter++;
//     }
//     int answer=enter+left+right;
//     cout<<answer<<" "<<left<<" "<<right<<endl;
//     return 0;
// }












// // #include<stdio.h>
// // #include <math.h>
// // int main()
// // {  
// //     int n,x,y;
// //     int t,b,l,r;
// //     scanf("%d",&n);
// //     scanf("%d %d",&x,&y);
// //     t=b=y;l=r=x;
// //     for(int k=0;k<n-1;k++){
// //         scanf("%d %d",&x,&y);
// //         if(y>t)
// //             t=y;
// //         else if(y<b)
// //             b=y;
// //         if(x>r)
// //             r=x;
// //         else if(x<l)
// //             l=x;
// //     }
// //     printf("%d %d %d %d\n",t,b,r,l);
    
// //     double section=(double)((r-l)*(t-b))/4;
// // 	//셋째 자리 반올림
// //     section=round(section*100)/100;
// //     printf("%d\n",section);
// //     return 0;
// // }
// // #include <iostream>
// // #include <string.h>

// // using namespace std;
// // const int MAX=100;
// // int n,t,board[MAX][MAX];
// // void attact(int y,int x){
// //     for(int i=0;i<10;i++){
// //         for(int j=0;j<10;j++){
// //             board[y+i][x+j]=1;
// //         }
// //     }
// // }
// // int main()
// // {
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0); cout.tie(0);

// //     cin>>t;
// //     for(int i=0;i<t;i++){
// //         cin>>n;
// //         memset(board,0,sizeof(board));
// //         for (int j=0;j<n;j++){
// //             int y,x;
// //             cin>>x>>y;
// //             attact(y,x);
// //         }
// //         int cnt=0;
// //         for(int i=0;i<100;i++)
// //             for(int j=0;j<100;j++){
// //                 if(board[i][j]==1)
// //                     cnt++;
// //             }
// //         cout<<cnt<<"\n";
// //     }
// //     return 0;
// // }

// // #include<stdio.h>
// // #include <math.h>

// // int main()
// // {   //프로그램의 시작부
// // 		//첫 번째 점 P의 좌표
// // 		int px, py;
// // 		//두 번째 점 Q의 좌표
// // 		int qx, qy;
// // 		scanf("%d %d", &px, &py);
// // 		scanf("%d %d", &qx, &qy);
// //         int width=abs(px-qx);
// //         int height=abs(py-qy);

// //         if(width==0 &&height==0){
// //             printf("DOT\n");
// //         }
// //         else if(width==0 ||height==0){
// //             printf("SEGMENT");
// //         }
// //         else if(width==height){
// //             printf("SQUARE");
// //         }
// //         else{
// //             printf("RECTANGLE");
// //         }
// //     return 0;
// // }