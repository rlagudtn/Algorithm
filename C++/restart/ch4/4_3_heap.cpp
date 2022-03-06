// ////////////////////1655 (4)
#include <iostream>
#include <queue>

using namespace std;
int n,arr[100000];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;

    for(int i=0;i<n;i++)
        cin>>arr[i];        
    
    priority_queue<int> left;
    priority_queue<int> right;
    left.push(arr[0]);
    cout<<arr[0]<<"\n";
    for(int i=1;i<n;i++){
        if(i%2==0)
            left.push(arr[i]);
        else
            right.push(-arr[i]);
        
        int lt=left.top();
        int rt=-right.top();
        if(lt>rt){
            left.pop();right.pop();
            left.push(rt);
            right.push(-lt);
        }
        cout<<left.top()<<"\n";
    }
        
    return 0;
}


// #include <iostream>
// #include <queue>

// using namespace std;

// int main(void){
//     int n,temp;
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     cin>>n;
//     priority_queue<int> left;
//     priority_queue<int,vector<int>,greater<int>> right;
//     int leftMax,rightMin;
//     for(int i=0;i<n;i++){
//         cin>>temp;
//         if(left.size()<=right.size())
//             left.push(temp);
//         else
//             right.push(temp);
        
//         if(right.size()>0 && left.top()>right.top()){
//             leftMax=left.top();left.pop();
//             rightMin=right.top();right.pop();
//             right.push(leftMax);
//             left.push(rightMin);
//         }
//         cout<<left.top()<<"\n";
//     }
//     return 0;
// }

// ///////////////////1715
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
// int main(void)  {
//     int n,temp,first,second;
//     priority_queue<int,vector<int>,greater<int>> pq;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>temp;
//         pq.push(temp);
//     }
    
//     int answer=0;
//     while(!pq.empty()){
        
//         first=pq.top();
//         if(pq.size()==1){
//             cout<<answer<<"\n";
//             break;
//         }
//         pq.pop();
//         second=pq.top();
//         pq.pop();
//         answer+=first+second;
//         pq.push(first+second);
//     }
//     return 0;
// }

// ////////////////11286
// #include <iostream>
// #include <queue>
// using namespace std;
// class Pair{
//     public:
//     long long  number;
//     long long absolute;
//     Pair(int number,int absolute):number(number),absolute(absolute){}
//     bool operator< (const Pair& other) const{
//         if(absolute==other.absolute){
//             return number>other.number;
//         }
//         return absolute>other.absolute;
//     }

// };

// int main(void){
//     int n;
//     long long temp;
//     priority_queue<Pair> pq;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>temp;
//         if(temp==0){
//             if(pq.empty())
//                 cout<<"0\n";
//             else{
//                 Pair p=pq.top();
//                 pq.pop();
//                 cout<<p.number<<"\n";
//             }
//         }
//         else{
//             pq.push(Pair(temp,abs(temp)));
//         }
//     }
//     return 0;
// }

// /////////////////11279
// #include <stdio.h>
// #include <queue>

// using namespace std;

// int main(void){
//     int n;
//     long long temp;
//     priority_queue<long long> pq;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%lld",&temp);
//         if(temp==0){
//             if(pq.empty()){
//                 printf("0\n");
//             }
//             else{
//                 printf("%lld\n",pq.top());
//                 pq.pop();
//             }
//         }
//         else{
//             pq.push(temp);
//         }
//     }
//     return 0;
// }
/////////////////1927
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     int n;
//     long long temp;
//     priority_queue<long long,vector<long long>,greater<long long>> pq;

//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>temp;
//         if(temp==0){
//             if(pq.empty())
//                 cout<<0<<"\n";
//             else   {
//                 cout<<pq.top()<<"\n";
//                 pq.pop();
//             }
//         }
//         else{
//             pq.push(temp);
//         }

//     }
//     return 0;
// }