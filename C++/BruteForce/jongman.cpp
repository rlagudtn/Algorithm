
// #include <vector>
// #include <string>
// using namespace std;
// // ////////////////완전탐색 레시피
// // 1. 완전탐색을 할 시 시간 복잡도를 구한다.
// // 2. 답의 후보를 만드는 과정을 여러개의 "선택"으로 나눈다. 
// // 각 "선택"은 후보를 만드는 한 조각이 된다.
// // 3. 하나의 조각을 선택해 답의 일부로 만들고, 나머지 답을 재귀호출을 통해 완성한다.
// // 4. 조각이 하나 밖에 남지 않은경우, 혹은 하나도 남지 않은 경우에 답을 생성했으므로 기저사례로 선택해 처리한다.
// // cf. 범위를 벗어난 것 또한 기저사례로 선택해 코드를 간결하게 하자 

// // ////////////////조합 재귀로/////
// // void pick(int n, vector<int>& picked,int toPick){
// //     if(toPick==0) {
// //         //picked 출력
// //         return;
// //     }
// //     int smallest=picked.back()+1;
// //     for(int next=smallest; next<n;next++){
// //         picked.push_back(next);
// //         pick(n,picked,toPick-1);
// //         picked.pop_back();
// //     }
// // }

// // //////////////////보글 게임

// // //문제 분할
// // //keyword 의 앞 글자를 떼어내고 같다면 이 후 글자를 호출하여 확인
// // //기저 사례: 첫번째 첫글자와 다르다면 pass,
// // //           두번째  한글자인 경우 성공

// // //간결한 코드를 위한 팁
// // // 입력이 잘못되거나 범이에서 벗어난 경우도 기저사례로 선택한다.
// // const int dy[8]={1,1,1,0,0,-1,-1,-1};
// // const int dx[8]={1,0,-1,1,-1,1,0,-1};

// // bool hasWord(int y,int x, const string& word ){
// //     //범위 벗어나면 pass
// //     //if(!inRange(y,x)) return false;
// //     if(board[y][x]!=word[0]) return false;
// //     if(word.size()==1) return true;

// //     for (int i=0;i<8;i++){
// //         int ny=y+dy[i]; int nx=x+dx[i];
// //         if(hasWord(ny,nx,word.substr(1))){
// //             return true;
// //         }
// //     }
// //     return false;
// // }




// // //////////////////////////////// p.171
// // *******p
// const int INF=int(1e6),SWITCHES=10,CLOCKS=16;
// const char linked[SWITCHES][CLOCKS+1]={
//     // {1,1,1,1,}
// };
// bool areAligned(const vector<int>& clocks);


// //switch 번 스위치를 누른다.
// void push(vector<int>& clocks,int swtch){
//     for(int clock=0;clock<CLOCKS;++clock){
//         if(linked[swtch][clock]==1){
//             clocks[clock]+=3;
//             if(clocks[clock]==15) clocks[clock]=3;
//         }
//     }
// }
// //clocks: 현재 시계들의 상태
// //swtch: 이번에 누를 스위치의 번호

// int solution(vector<int>& clocks,int swtch){
//     if (swtch==SWITCHES) return areAligned(clocks)? 0:INF;

//     int ret=INF;
//     for(int cnt=0;cnt<4;cnt++){
//         ret=min(ret,cnt+solution(clocks,swtch+1));
//         push(clocks,swtch);
//     }
//     return ret;
// }
