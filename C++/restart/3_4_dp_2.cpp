



// //////////////2156 (5)
// #include <iostream>
// #include <string.h>
// #include <algorithm>
// using name`space std;
// int n, arr[10001],cache[10001];
// int max_value=0;
// int dfs(int n){
//     if(n==0)
//         return 0;
//     else if(n==1)
//         return cache[1]=arr[1];
//     else if(n==2)
//         return cache[2]=arr[1]+arr[2];

//     int& ret=cache[n];
//     if(ret!=-1)
//         return ret;
    
//     return ret=max({dfs(n-1),dfs(n-2)+arr[n],dfs(n-3)+arr[n-1]+arr[n]});
// }
// int main(void){
//     cin>>n;
//     for(int i=1;i<=n;i++)
//         cin>>arr[i];
        
//     memset(cache,-1,sizeof(cache));
//     cout<<dfs(n)<<"\n";
//     return 0;
// }
// 1912 (3)
// #include <iostream>
// #include <string.h>
// #include <algorithm>
// using namespace std;

// int n,cache[100001],arr[100001];

// int dfs(int n){ 
//     if(n==1)
//         return cache[1]=arr[1];
    
//     int& ret=cache[n];
//     if(ret!=-1)
//         return ret;

//     ret=arr[n]+dfs(n-1);
//     if(ret<0)
//         ret=0;
//     return ret;
// }
// int main(void){
//     cin>>n;
//     bool allNeg=true;
//     for(int i=1;i<=n;i++){
//         cin>>arr[i];
//         if(arr[i]>=0)
//             allNeg=false;

//     }
//     memset(cache,-1,sizeof(cache));
//     if(allNeg==false){
//         dfs(n);
//         cout<<*max_element(cache+1,cache+n+1)<<"\n";
//     }
//     else{
//         cout<<*max_element(arr+1,arr+n+1)<<"\n";
//     }
//     return 0;
// }

// /////////////////11727 (2)
// #include <iostream>
// #include <string.h>
// using namespace std;
// int n,cache[1001];
// int dfs(int n){
//     if(n==1)
//         return 1;
//     else if(n==2)
//         return 3;
    
//     int& ret=cache[n];
//     if(ret!=-1)

//         return ret;
//     return ret=(dfs(n-1)+(dfs(n-2)*2))%10007;
// }
// int main(void){
//     cin>>n;
//     memset(cache,-1,sizeof(cache));
//     cout<<dfs(n)<<"\n";
//     return 0;
// }


/////////////////11726 (1)
// #include <iostream>
// #include<string.h>

// using namespace std;
// int n;
// int cache[1001];
// int dfs(int idx){
//     if(idx==1)
//         return 1;
//     else if(idx==2)
//         return 2;

//     int& ret=cache[idx];
//     if(ret!=-1)
//         return ret;
    
//     return ret=(dfs(idx-1)+dfs(idx-2))%10007;
// }
// int main(void)  {
//     cin>>n;
//     memset(cache,-1,sizeof(cache));
    
//     cout<<dfs(n)<<"\n";
//     return 0;
// }