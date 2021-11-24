// ///////////////////5430
// #include <deque>
// #include <string>
// #include <iostream>

// using namespace std;
// int main(void){

//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
    
//     int t,n;
//     string cmd,str;
    
//     cin>>t;
//     for(int k=0;k<t;k++){
//         deque<int> dq;
//         bool isError,reverse;
//         isError=reverse=false;

//         int temp=0;
//         cin>>cmd>>n>>str;
//         for(int i=0;i<str.length();i++){
//             if(str[i]=='[')
//                 continue;
//             else if(str[i]==']'||str[i]==','){
//                 dq.push_back(temp);
//                 temp=0;
//             }
//             else{
//                 temp=temp*10+(str[i]-'0');
//             }
//         }
//         if(n==0)
//             dq.clear();
        
//         for(int i=0;i<cmd.size();i++){
//             if(cmd[i]=='R')
//                 reverse=!reverse;
//             else if(cmd[i]=='D'){
//                 if(dq.empty()){
//                     isError=true;
//                     break;
//                 }
//                 if(reverse==false){
//                     dq.pop_front();
//                 }
//                 else{
//                     dq.pop_back();
//                 }
//             }
//         }
        
//         if(isError){
//             cout<<"error\n";
//         }
//         else if(dq.empty()){
//             cout<<"[]\n";
//         }
//         else {
//             if(reverse==false){
//                 deque<int>::iterator it=dq.begin();
//                 cout<<"["<< (*it);
//                 it++;
//                 for(it;it!=dq.end();it++)
//                     cout<<","<<(*it);
//                 cout<<"]\n";
//             }
//             else{
//                 deque<int>::reverse_iterator it=dq.rbegin();
//                 cout<<"["<< (*it);
//                 it++;
//                 for(it;it!=dq.rend();it++)
//                     cout<<","<<(*it);
//                 cout<<"]\n";
                
//             }
//         }

//     }
//     return 0;
// }
// // //////////////////1966
// // #include <stdio.h>
// // #include <vector>
// // #include <queue>
// // #include <algorithm>
// // using namespace std;
// // bool compare(int a,int b) {
// //     return a>b;
// // }
// // int main(void){
// //     int t,n,k,num;
// //     scanf("%d",&t);
// //     for(int i=0;i<t;i++){
// //         scanf("%d %d",&n,&k);
// //         queue<pair<int,int>> q;
// //         vector<int> value(n);
// //         for(int j=0;j<n;j++){
// //             scanf("%d",&num);
// //             q.push(make_pair(j,num));
// //             value[j]=num;
// //         }
// //         sort(value.begin(),value.end(),compare);
        
// //         int cnt,index;
// //         cnt=index=0;
// //         while(!q.empty()){
// //             pair<int,int> front=q.front();
// //             q.pop();
// //             if(front.second<value[index]){
// //                 q.push(front);
// //             }
// //             else{
// //                 cnt++;
// //                 if(front.first==k){
// //                     printf("%d\n",cnt);
// //                     break;
// //                 }
// //                 index++;
// //             }
// //         }
// //     }
// //     return 0;
// // }


// // ///////////////1158
// // #include <queue>
// // #include <stdio.h>
// // #include <vector>
// // using namespace std;
// // int main(void){
// //     int n,k;
// //     scanf("%d %d",&n,&k);

// //     queue<int> q;
// //     vector<int> order;
// //     for(int i=1;i<=n;i++)
// //         q.push(i);

// //     int cnt;
// //     while(!q.empty()){
// //         for(cnt=1;cnt<k;cnt++){
// //             q.push(q.front());
// //             q.pop();
// //         }
// //         order.push_back(q.front());
// //         q.pop();
// //     }
// //     printf("<%d",order[0]);
// //     for(int i=1;i<n;i++)
// //         printf(", %d",order[i]);
// //     printf(">\n");
    
// //     return 0;
// // }
// // ////////////1874
// // #include <stdio.h>
// // #include <stack>
// // #include <queue>

// // using namespace std;
// // int main(void){
// //     int n,num;
// //     scanf("%d",&n);
// //     stack<int> st;
// //     queue<int> q;
// //     vector<char> progress;
// //     for(int i=0;i<n;i++){
// //         scanf("%d",&num);
// //         q.push(num);
// //     }
// //     for(int i=1;i<=n;i++){
// //         st.push(i);
// //         progress.push_back('+');
// //         while(!st.empty()&& st.top()==q.front()){ //////////////////////////////empty 확인 안하면 무한 루프
// //             st.pop();
// //             q.pop();
// //             progress.push_back('-');
// //         }
       
// //     }

// //     if(st.empty())
// //         for(int i=0;i<progress.size();i++)
// //             printf("%c\n",progress[i]);
    
// //     else
// //         printf("NO");
// //     return 0;
// // }

// /////////////9012
// // #include <iostream>
// // #include <stack>
// // #include <string>
// // using namespace std;
// // bool isVpr(string ps){
// //     stack<char> st;

// //     for(int i=0;i<ps.size();i++){
// //         if(ps[i]=='(')
// //             st.push(ps[i]);
// //         else{
// //             if(st.empty())
// //                 return false;
// //             st.pop();
// //         }
        
// //     }
// //     if(!st.empty())
// //         return false;
// //     return true;
// // }
// // int main(void){

// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);cout.tie(0);

// //     int t;
// //     string ps;
// //     cin>>t;
// //     for(int i=0;i<t;i++){
// //         cin>>ps;
// //         if(isVpr(ps))
// //             cout<<"YES\n";
// //         else    
// //             cout<<"NO\n";
// //     }
// //     return 0;
// // }