////////////////////2529
// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;
// int n;
// int visit[10]={0,};
// vector<int> picked;
// char signs[10];
// long long maxValue=0;
// long long minValue=9876543210;
// void dfs(int idx){
//     if(picked.size()==n+2){
//         long long temp=0;
//         for(int i=1;i<picked.size();i++)
//             temp=temp*10+picked[i];
//         maxValue=max(maxValue,temp);
//         minValue=min(minValue,temp); 
//         return ;
//     }
//     for(int i=0;i<10;i++){
//         if(visit[i]==0 &&((signs[idx]=='<'&& picked[idx]<i)||(signs[idx]=='>'&& picked[idx]>i))){
//             picked.push_back(i);
//             visit[i]=1;
//             dfs(idx+1);
//             picked.pop_back();
//             visit[i]=0;
//         }
//     }
// }
// int main(void){
//     cin>>n;
//     for(int i=1;i<n+1;i++)
//         cin>>signs[i];
//     signs[0]='<';
    
//     picked.push_back(-1);
//     dfs(0);
//     string maxS="0"+to_string(maxValue);
//     maxS=maxS.substr(maxS.length()-(n+1));
//     string minS="0"+to_string(minValue);
//     minS=minS.substr(minS.length()-(n+1));
//     cout<<maxS<<"\n"<<minS<<"\n";
//     return 0;
// }



// #include <iostream>
// #include <string.h>
// #include <string>
// using namespace std;
// int k;
// char signs[10];
// int visit[11],picked[11];
// long long maxValue=0;
// long long minValue=9876543210;
// long long changeToStr(){
//     long long ret=0;
//     for(int i=0;i<k+1;i++){
//         ret=ret*10+picked[i];
//     }
//     return ret;
// }
// void dfs(int idx){
//     if(idx>=1){
//         if(signs[idx-1]=='<'&& picked[idx-1]>picked[idx])
//             return;
//         else if(signs[idx-1]=='>' && picked[idx-1]<picked[idx])
//             return;
//     }
//     if(idx==k){
//         long long number=changeToStr();
//         maxValue=max(number,maxValue);
//         minValue=min(number,minValue);
//     }

//     for(int i=0;i<10;i++){
//         if(visit[i]==0){
//             visit[i]=1;
//             picked[idx+1]=i;
//             dfs(idx+1);
//             visit[i]=0;
//         }
//     }
// }
// int main(void){
//     cin>>k;
//     for(int i=0;i<k;i++)
//         cin>>signs[i];
//     memset(visit,0,sizeof(visit));
//     memset(picked,0,sizeof(picked));
//     for(int i=0;i<10;i++){
//         visit[i]=1;
//         picked[0]=i;
//         dfs(0);
//         visit[i]=0;
//     }
//     string max=to_string(maxValue);
//     string min=to_string(minValue);
//     max="0"+max;
//     min="0"+min;
//     cout<<max.substr(max.length()-k-1)<<"\n"
//         <<min.substr(min.length()-k-1)<<"\n";
//     return 0;
// }

// ///////////////////2529 (3)
// #include <iostream>

// using namespace std;
// char signs[9];
// int n,arr[10],picked[10],strings[10];
// long long maxValue=0;
// long long minValue=9876543210;
// void dfs(int cnt){
//     if(cnt>n+1){
//         //부등호 확인
//         cout<<"temp\n";
//         for(int i=0;i<n;i++){
//             if(signs[i]=='<' && strings[i]>strings[i+1])
                
//                 return;
//             else if(signs[i]=='>' && strings[i]<strings[i+1])
//                 return;
//         }

//         long long temp=0;
//         for(int i=0;i<n+1;i++){
//             temp=temp*10+strings[i];
//         }
//         cout<<temp<<"\n";
//         maxValue=max(maxValue,temp);
//         minValue=min(minValue,temp);
//         return;
//     }

//     for(int i=0;i<10;i++){
//         if(picked[i]==0){
//             picked[i]=1;
//             strings[cnt]=i;
//             dfs(cnt+1);
//             picked[i]=0;
//         }
//     }
// }
// int main(void){
//     cin>>n;
//     for(int i=0;i<n;i++)
//         cin>>signs[i];
//     dfs(0);
//     cout<<maxValue<<"\n"<<minValue<<"\n";
//     return 0;
// }


// // /////////////////2217 (2)
// // #include <iostream>
// // #include <algorithm>
// // using namespace std;
// // int n,lopes[100000];

// // int main(void){
// //     cin>>n;
// //     for(int i=0;i<n;i++)
// //         cin>>lopes[i];
    
// //     sort(lopes,lopes+n);

// //     int answer=0;
// //     for(int i=0;i<n;i++){
// //         answer=max(answer,lopes[i]*(n-i));
// //     }
// //     cout<<answer<<"\n";
// //     return 0;

// // }

// // /////////////////1931 (2)
// // #include <iostream>
// // #include <algorithm>

// // using namespace std;
// // int n;
// // pair<int,int> meeting[100000];
// // bool compare(pair<int,int> a,pair<int,int> b){
// //     if(a.second==b.second)
// //         return a.first<b.first;
// //     return a.second<b.second;
// // }
// // int main(void){
// //     cin>>n;
// //     for(int i=0;i<n;i++){
// //         cin>>meeting[i].first>>meeting[i].second;
// //     }

// //     sort(meeting,meeting+n,compare);
// //     int answer=0;
// //     int lastTime=0;
// //     for(int i=0;i<n;i++){
// //         if(meeting[i].first>=lastTime){
// //             lastTime=meeting[i].second;
// //             answer++;
// //         }
// //     }
// //     cout<<answer<<"\n";
// //     return 0;
// // }
// // #include <iostream>
// // using namespace std;
// // int coins[10];
// // int n,k;
// // int main(void){
// //     cin>> n>>k;
// //     for (int i = 0; i < n; i++)
// //         cin>>coins[i];

// //     int remain=k;   

// //     int answer=0;
// //     for(int i=n-1;i>=0;i--){
// //         if(remain==0)
// //             break;
// //         answer+=remain/coins[i];
// //         remain-=remain/coins[i]*coins[i];
// //     }
// //     cout<<answer<<"\n";
// //     return 0;
// // }