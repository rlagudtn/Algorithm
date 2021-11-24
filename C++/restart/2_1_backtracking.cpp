// //////////////////////////9663
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int n,answer;
int board[15];
bool canPut(int y,int x){
    for(int i=0;i<y;i++){
        if(board[i]==x||y-i==abs(x-board[i]))
            return false;
    }
    return true;
}
void dfs(int row){
    if(row==n){
        answer++;
        return;
    }
    for(int i=0;i<n;i++){
        if(canPut(row,i)){
            board[row]=i;
            dfs(row+1);
        }
    }    
    
}
int main(void){
    scanf("%d",&n);
    answer=0;
    dfs(0);
    printf("%d\n",answer);
    return 0;
}
// /////////////////////////9095
// #include <stdio.h>

// int n;
// int cnt;

// void dfs(int sum){
//     if(sum>n)
//         return;
//     else if(sum==n){
//         cnt++;
//         return;
//     }
    
//     for(int i=1;i<=3;i++){
//         dfs(sum+i);
//     }
// }
// int main(void){
//     int t;
//     scanf("%d",&t);
//     for(int k=0;k<t;k++){
//         scanf("%d",&n);
//         cnt=0;
//         dfs(0);
//         printf("%d\n",cnt);
//     }
//     return 0;
// }


// //////////////////////1182
// #include <stdio.h>
// #include <vector>
// using namespace std;
// int n,s;
// int answer;
// void dfs(vector<int>& arr,int index,int sum){
//     //기저 사례
//     if(index==n)
//         return;
    
//     if(sum+arr[index]==s)
//         answer++;
    
//     dfs(arr,index+1,sum);
//     dfs(arr,index+1,sum+arr[index]);
// }
// int main(void){
//     scanf("%d %d",&n,&s);
//     vector<int> arr(n);
//     for(int i=0;i<n;i++)
//         scanf("%d",&arr[i]);
    
//     dfs(arr,0,0);
//     printf("%d",answer);
// }
// ///////////////////6603
// #include <vector>
// #include <stdio.h>
// #include <algorithm>
// using namespace std;
// void output(vector<int> picked){
//     for(int i=1;i<picked.size();i++){
//         printf("%d ",picked[i]);
//     }
//     printf("\n");
// }
// void dfs(vector<int>& arr, vector<int>& picked){
//     if(picked.size()==7)
//         output(picked);
    
//     int now=picked.back();
    
//     int next=lower_bound(arr.begin(),arr.end(),now)-arr.begin(); 
    
//     if(7-picked.size()>arr.size()-next-1) ////////////////////////이 부분 처리를 어떻게 했는지 살펴 보기
//         return;
    
//     for(next=next+1;next<arr.size();next++){
//         picked.push_back(arr[next]);
//         dfs(arr,picked);
//         picked.pop_back();
//     }
// }
// int main(void){
//     int n;
//     while (true)
//     {
//         scanf("%d",&n);
//         if(n==0)
//             break;
//         vector<int> arr(n+1);
//         vector<int> picked;

//         arr[0]=0;
//         for(int i=1;i<n+1;i++)
//             scanf("%d",&arr[i]);
        
//         picked.push_back(0);
//         dfs(arr,picked);
//         printf("\n");
//     }
    
//     return 0;
// }