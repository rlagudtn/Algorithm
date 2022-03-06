////단체사진 찍기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
string arr;
int answer;
vector<string> d;
int visit[8];
bool isPossible(vector<char>& picked){
  for(int i=0;i<N;i++){
    int u=find(picked.begin(),picked.end(),d[i][0])-picked.begin();
    int v=find(picked.begin(),picked.end(),d[i][2])-picked.begin();
    char s=d[i][3];
    int dist=d[i][4]-'0';
    int uv=abs(u-v);
    uv--;
    if((s=='=' &&uv!=dist)||(s=='>'&&uv<=dist)||(s=='<'&&uv>=dist))
      return false;
  }
  return true;
}
void dfs(vector<char>& picked){

  if(picked.size()==8 &&isPossible(picked)){
      answer++;
  }
  for(int i=0;i<8;i++){
    if(visit[i]==0){
      picked.push_back(arr[i]);
      visit[i]=1;
      dfs(picked);
      picked.pop_back();
      visit[i]=0;
    }
  }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
  answer=0;
  N=n;
  arr="ACFJMNRT";
  for(int i=0;i<8;i++){
    visit[i]=0;
  }
  d=data;

  vector<char> picked;
  dfs(picked);
  return answer;
}

int main(void){
  vector<string> data={"N~F=0", "R~T>2"};
  cout<<solution(2,data)<<"\n";
  return 0;
}

// #include <string>
// #include <vector>
// #include <iostream>
// #include <math.h>
// #include <sstream>
// using namespace std;
// vector<string> split(string input, char delimiter) {
//     vector<string> answer;
//     stringstream ss(input);
//     string temp;

//     while (getline(ss, temp, delimiter)) {
//       if(temp!="")
//         answer.push_back(temp);
//     }
 
//     return answer;
// }
// string convert(int n,int k){
//   string ret="";
//   while(n!=0){
//     ret=to_string(n%k)+ret;
//     n/=k;
//   }
//   return ret;
// }
// bool isPrimeNumber(long long n){
//   if(n==1)
//     return false;
//   else if(n==2)
//     return true;
//   for(int i=2;i<sqrt(n)+1;i++){
//     if(n%i==0)
//       return false;
//   }
//   return true;
// }
// int solution(int n, int k) {
//     int answer = 0;
//     string converted=convert(n,k);

//     vector<string> list=split(converted,'0');
//     for(int i=0;i<list.size();i++){
//       if(isPrimeNumber(stoll(list[i]))){
//         answer++;
//       }
//     }
//     return answer;
// }

// int main(void){
//   // cout<<convert(12,3)<<"\n";
//   cout<<solution(437674,3)<<"\n";
//   cout<<solution(110011,10)<<"\n";

//   return 0;
// }

// // #include <vector>
// // #include <queue>
// // #include <string.h>
// // using namespace std;

// // int visit[100][100];

// // int row,col;
// // // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
// // int bfs(int y,int x,vector<vector<int>>& picture){
// //     int dy[4]={0,0,1,-1};
// //     int dx[4]={1,-1,0,0};
// //     queue<pair<int,int>> q;
// //     q.push({y,x});
// //     visit[y][x]=1;
// //     int cy,cx,ny,nx,cnt=0;
// //     int first=picture[y][x];
// //     while(!q.empty()){
// //         cy=q.front().first;cx=q.front().second;
// //         q.pop();
// //         cnt++;
// //         for(int i=0;i<4;i++){
// //             ny=cy+dy[i];nx=cx+dx[i];
// //             if(ny<0||ny>=row||nx<0||nx>=col)
// //                 continue;
// //             if(picture[ny][nx]==first &&visit[ny][nx]==0){
// //                 q.push({ny,nx});
// //                 visit[ny][nx]=1;
// //             }
// //         }
// //     }
// //     return cnt;
// // }
// // vector<int> solution(int m, int n, vector<vector<int>> picture) {
// //     int number_of_area = 0;
// //     int max_size_of_one_area = 0;
// //     row=m,col=n;
// //     memset(visit,0,sizeof(visit));
    
// //     for(int i=0;i<row;i++){
// //         for(int j=0;j<col;j++){
// //             if(picture[i][j]!=0&&visit[i][j]==0){
// //                 max_size_of_one_area=max(max_size_of_one_area,bfs(i,j,picture));
// //                 number_of_area++;
// //             }
// //         }
// //     }


// //     vector<int> answer(2);
// //     answer[0] = number_of_area;
// //     answer[1] = max_size_of_one_area;
// //     return answer;
// // }

