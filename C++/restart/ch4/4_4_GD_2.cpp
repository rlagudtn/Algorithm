#include <queue>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
bool compare(string a,string b){
    if(a.size()>b.size()){
        for(int i=0;i<b.size();i++){
            if(a[i]>b[i])
                return a>b;
            else if(a[i]<b[i])
                return a<b;
            
        }
        return a[0]>a[b.size()];

    }
    else if(a.size()<b.size()){
        for(int i=0;i<a.size();i++){
            if(a[i]>b[i])
                return a>b;
            else if(a[i]<b[i])
                return a<b;
            
        }
        return b[0]>b[a.size()];
            
    }
    return a>b;
}
int main(void){
    string arr[50];
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}


// ////////////1826
// #include <iostream>
// #include <queue>
// #include <algorithm>
// using namespace std;
// pair<int,int> gasStation[10000];
// int n,l,p;
// int main(void)  {
//     cin>>n;
//     for(int i=0;i<n;i++)
//         cin>>gasStation[i].first>>gasStation[i].second;
    
//     cin>>l>>p;
//     sort(gasStation,gasStation+n);
    
//     priority_queue<int> pq;
//     pq.push(p);
//     int idx,tempGas;
//     idx=0;
//     int cnt=-1;
//     tempGas=0;
//     while(!pq.empty()){
        
        
//         tempGas+=pq.top();
//         pq.pop();
        
//         cnt++;

//         if(tempGas>=l){
//             cout<<cnt<<"\n";
//             return 0;
//         }
//         while(idx<n && gasStation[idx].first<=tempGas){
//             pq.push(gasStation[idx].second);
//             idx++;
//         }

        
//     }
//     cout<<-1<<"\n";
//     return 0;
// }

// ////////////13305
// #include <iostream>
// using namespace std;

// int oils[100000],dists[99999];
// int main(void){
//     int n;
//     cin>>n;
//     for(int i=0;i<n-1;i++)
//         cin>>dists[i];
//     for(int i=0;i<n;i++)
//         cin>>oils[i];
    
//     int i,j;
//     unsigned long long sum,answer;
//     answer=0;
//     i=0;
//     while(i<n){
//         j=i+1;
//         sum=0;
//         while(j<n){
//             sum+=dists[j-1];
//             if(oils[j]<oils[i])
//                 break;
//             j++;
//         }
//         answer+=sum*oils[i];
//         i=j;
//     }
//     cout<<answer<<"\n";
//     return 0;
// }

// ////////////////////9576
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// bool compare(pair<int,int> a,pair<int,int> b){
//     if (a.second==b.second)
//         return a.first<b.first; 
//     return a.second<b.second;
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t,n,m;
//     cin>>t;
//     for(int k=0;k<t;k++){
//         cin>>n>>m;
//         vector<pair<int,int>> books(m);
//         int visit[n+1]={0,};
//         for(int s=0;s<m;s++){
//             cin>>books[s].first>>books[s].second;
//         }

//         sort(books.begin(),books.end(),compare);
//         int current=1;
//         int answer=0;

//         for(int i=0;i<m;i++){
//             for(int j=books[i].first;j<=books[i].second;j++){
//                 if(visit[j]==0){
//                     answer++;
//                     visit[j]=1;
//                     break;
//                 }
//             }
//         }
//         cout<<answer<<"\n";

//     }

//     return 0;
// }


// //////////////////1202
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>

// using namespace std;
// bool compare(pair<int,int> a,pair<int,int> b){
//     if(a.second==b.second)
//         return a.first<b.first;
//     return a.second>b.second;
// }
// int main(void){
//     int n,k,bags[300000],m,v;
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     cin>>n>>k;
//     vector<pair<int,int>> jewels(n);
//     int visit[k]={0,};
//     for(int i=0;i<n;i++){
//         cin>>jewels[i].first>>jewels[i].second;
//     }
//     for(int i=0;i<k;i++){
//         cin>>bags[i];
//     }

//     sort(jewels.begin(),jewels.end());
//     sort(bags,bags+k);

//     int idx=0;
//     long long answer=0;
//     priority_queue<int> pq;
//     for(int i=0;i<k;i++){
//         while(idx<n && jewels[idx].first<=bags[i]){
//             pq.push(jewels[idx].second);
//             idx++;
//         }
//         if(!pq.empty()){
//             answer+=pq.top();
//             pq.pop();
//         }
//     }
//     cout<<answer<<"\n";

//     return 0;
// }