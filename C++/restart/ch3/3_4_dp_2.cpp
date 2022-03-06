/////////////////11052
#include <iostream>

using namespace std;
int n,arr[1001],cache[1001]={0,};
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>arr[i];

  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
      cache[j]=max(cache[j],cache[j-i]+arr[i]);
    }
  }
  cout<<cache[n]<<"\n";
  return 0;
}

// ///////////////11053 (6)
// #include <iostream>
// #include <string.h>

// using namespace std;
// int n,arr[1001],cache[1001];
// int dfs(int idx){
//     int& ret=cache[idx];
//     if(ret!=-1)
//         return ret;

//     ret=0;
//     for(int i=idx+1;i<n+1;i++){
//         if(arr[i]>arr[idx]){
//             ret=max(ret,dfs(i));
//         }
//     }
//     return ret+=1;
// }
// int main(void){
//     cin>>n;
//     arr[0]=0;
//     for(int i=1;i<n+1;i++)
//         cin>>arr[i];
//     memset(cache,-1,sizeof(cache));
//     cout<<dfs(0)-1<<"\n";
//     return 0;
// }




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
// ///////////2293(4)
// #include <iostream>
// #include <string.h>
// using namespace std;
// int n,k,arr[100],cache[10000];

// int dfs(int num,int idx) {
//   if(num==0)
//     return 1;
//   else if(num<0)
//     return 0;
//   int& answer=cache[num];
//   for(int i=idx;i<n;i++){
//     answer+=dfs(num-arr[i],i);
//   }
//   return answer;
// }
// int main(void){
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
  
//   cin>>n>>k;
//   for(int i=0;i<n;i++)
//     cin>>arr[i];
//   cout<<dfs(k,0)<<"\n";
//   return 0;
// }

// 1912 (3)
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int n,arr[100001],sum[100001]={0,};
// int main(void){
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cin>>n;
  
//   for(int i=1;i<=n;i++)
//     cin>>arr[i];
  
//   for(int i=1;i<=n;i++){
//     if(sum[i-1]>=0)
//       sum[i]=sum[i-1]+arr[i];
//     else 
//       sum[i]=arr[i];
//   }
//   cout<<*max_element(sum+1,sum+n+1)<<"\n";
//   return 0;
// }
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