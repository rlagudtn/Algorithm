////////////////2110 (5)
#include <iostream>
#include <algorithm>
using namespace std;
int n,c;
int arr[200000];
int main(void){
    cin>>n>>c;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);

    int start,end,mid,last;
    int answer=0;
    start=0;end=arr[n-1]-arr[0];
    while(start<=end){
        mid=(start+end)/2;
        last=arr[0]+mid;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(arr[i]>=last){
                last=arr[i]+mid;
                cnt++;
            }
        }
        if(cnt>=c){
            answer=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<answer<<"\n";
    return 0;
}


// /////////////2512(4)
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int n, bugets[10000];
// long long m;
// int main(void){
//     int answer=0;

//     cin>>n;
//     for(int i=0;i<n;i++)
//         cin>>bugets[i];
//     cin>>m;

//     int start,end,mid;
//     long long sumValue;
    
//     start=0;end=*max_element(bugets,bugets+n);

//     while(start<=end){
//         mid=(start+end)/2;
//         sumValue=0;
//         for(int i=0;i<n;i++){
//             sumValue+=(bugets[i]>mid? mid:bugets[i]);
//         }
//         if(sumValue<=m){
//             answer=mid;
//             start=mid+1;
//         }
//         else if(sumValue>m){
//             end=mid-1;
//         }
       
//     }
//     cout<<answer<<"\n";
//     return 0;
// }

////////////////2869(3)
// #include <iostream>
// using namespace std;
// #include <math.h>
// int main(void){
//     int a,b,c;
//     cin>>a>>b>>c;
//     int remain=c-a;
//     if(remain<=0){
//         cout<<1<<"\n";
//     }
//     else{
//         int remainder=remain%(a-b);
//         int quan=remain/(a-b);
//         if(remainder!=0)
//             quan++;
//         cout<<quan+1<<"\n";
//     }
//     return 0;
// }


// //////////////1654 (2)
// #include <iostream>
// #include <algorithm>
// using namespace std;
// long long lans[10000];
// int main(void){
//     int k,n;
//     cin>>k>>n;
//     for(int i=0;i<k;i++)
//         cin>>lans[i];
    
//     long long start=0;
//     long long end=(long long)(1e10);
//     long long mid,answer;
//     int cnt;
//     answer=0;
//     while(start<=end){
//         mid=(start+end)/2;
//         cnt=0;
//         for(int i=0;i<k;i++){
//             cnt+=lans[i]/mid;
//         }
//         if(cnt>=n){
//             answer=max(answer,mid);
//             start=mid+1;
//         }
//         else{
//             end=mid-1;
//         }

//     }
//     cout<<answer<<"\n";

//     return 0;
// }

/////////////////2805 (1)
// #include <iostream>
// using namespace std;
// int trees[1000000];

// int main(void){
//     int n, m;
//     cin>>n>>m;
//     for(int i=0;i<n;i++)
//     cin>>trees[i];

//     int answer=0;
//     int start,end,mid;
//     long long sum;
//     start=0;end=int(1e9);
//     while(start<=end){
//         mid=(start+end)/2;
//         sum=0;
//         for(int i=0;i<n;i++){
//             int temp=trees[i]-mid;
//             sum+=(temp>=0? temp:0);
//         }
//         if(sum>=m){
//             answer=max(answer,mid);
//             start=mid+1;      
//         }
//         else{
//             end=mid-1;
//         }
        
//     }
//     cout<<answer<<"\n";
//     return 0;
// }

// // #include <iostream>
// // #include <string.h>
// // #include <string>
// // using namespace std;
// // int k;
// // char signs[10];
// // int visit[11],picked[11];
// // long long maxValue=0;
// // long long minValue=9876543210;
// // long long changeToStr(){
// //     long long ret=0;

// //     for(int i=0;i<k+1;i++){
// //         ret=ret*10+picked[i];
// //     }
// //     return ret;
// // }
// // void dfs(int idx){
// //     if(idx>=1){
// //         if(signs[idx-1]=='<'&& picked[idx-1]>picked[idx])
// //             return;
// //         else if(signs[idx-1]=='>' && picked[idx-1]<picked[idx])
// //             return;
// //     }
// //     if(idx==k){
// //         long long number=changeToStr();
// //         maxValue=max(number,maxValue);
// //         minValue=min(number,minValue);
// //     }

// //     for(int i=0;i<10;i++){
// //         if(visit[i]==0){
// //             visit[i]=1;
// //             picked[idx+1]=i;
// //             dfs(idx+1);
// //             visit[i]=0;
// //         }
// //     }
// // }
// // int main(void){
// //     cin>>k;
// //     for(int i=0;i<k;i++)
// //         cin>>signs[i];
// //     memset(visit,0,sizeof(visit));
// //     memset(picked,0,sizeof(picked));
// //     for(int i=0;i<10;i++){
// //         visit[i]=1;
// //         picked[0]=i;
// //         dfs(0);
// //         visit[i]=0;
// //     }
// //     string max=to_string(maxValue);
// //     string min=to_string(minValue);
// //     max="0"+max;
// //     min="0"+min;
// //     cout<<max.substr(max.length()-k-1)<<"\n"
// //         <<min.substr(min.length()-k-1)<<"\n";
// //     return 0;
// // }