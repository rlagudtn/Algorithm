
// ///////////////////11816
// #include <stdio.h>
// #include <algorithm>
// #include <vector>

// using namespace std;
// int main(void){
//     int n,m,num,cnt;
//     scanf("%d",&n);
//     vector<int> arr(n);
//     for(int i=0;i<n;i++)
//         scanf("%d",&arr[i]);
//     sort(arr.begin(),arr.end());

//     scanf("%d",&m);
//     for(int i=0;i<m;i++){
//         scanf("%d",&num);
//         cnt=upper_bound(arr.begin(),arr.end(),num)-lower_bound(arr.begin(),arr.end(),num);
//         printf("%d ",cnt);
//     }

//     return 0;
// }
// /////////////////10867
// #include <algorithm>
// #include <vector>
// #include <stdio.h>

// using namespace std;
// int main(void){
//     int n,num;
//     scanf("%d",&n);
//     vector<int> arr(n);
//     for(int i=0;i<n;i++)
//         scanf("%d",&arr[i]);
//     sort(arr.begin(),arr.end());
//     arr.erase(unique(arr.begin(),arr.end()),arr.end());
//     for(int i=0;i<arr.size();i++)
//         printf("%d ",arr[i]);

//     return 0;
// }
// #include <vector>
// #include <algorithm>
// #include <cstdio>


// using namespace std;
// bool compare(pair<int,int> a,pair<int,int> b){
//     if(a.second!=b.second)
//         return a.second<b.second;
    
//     return a.first<b.first;
// }
// int main(void){
//     int n,a,b;

//     scanf("%d",&n);
//     vector<pair<int,int>> arr(n);

//     for(int i=0;i<n;i++){
//         scanf("%d %d",&arr[i].first,&arr[i].second );
//     }
//     sort(arr.begin(),arr.end(),compare);
//     for(int i=0;i<n;i++){
//         printf("%d %d\n",arr[i].first,arr[i].second);
//     }
    
//     return 0;
// }
// ////////////////11650
// #include <vector>
// #include <algorithm>
// #include <cstdio>


// using namespace std;
// bool compare(pair<int,int> a,pair<int,int> b){
//     if(a.first!=b.first)
//         return a.first<b.first;
    
//     return a.second<b.second;
// }
// int main(void){
//     int n,a,b;

//     scanf("%d",&n);
//     vector<pair<int,int>> arr(n);

//     for(int i=0;i<n;i++){
//         scanf("%d %d",&a,&b );
//         arr[i].first=a;arr[i].second=b;
//     }
//     sort(arr.begin(),arr.end(),compare);
//     for(int i=0;i<n;i++){
//         printf("%d %d\n",arr[i].first,arr[i].second);
//     }
    
//     return 0;
// }

// ////////////1181
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>

// using namespace std;
// bool compare(string a,string b){
//     if(a.length()!=b.length())
//         return a.length()<b.length();
    
//     ////////사전순으로 비교
//     return a<b;

// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int n;
//     cin>>n;
//     vector<string> arr(n);
//     string temp;
//     for(int i=0;i<n;i++){
//         cin>>temp;
//         arr[i]=temp;
//     }
//     sort(arr.begin(),arr.end(),compare);
//     arr.erase(unique(arr.begin(),arr.end()),arr.end()); 
//     ///////unique 는 중복이 시작되는 곳을 반환하기 때문에 중복되는 부분 삭제
    
//     for(int i=0;i<arr.size();i++)
//         cout<<arr[i]<<"\n";
//     return 0;
// }

/////////////1026
// #include <algorithm>
// #include <cstdio>

// using namespace std;
// bool compare(int a,int b){
//     return a>b;
// }
// int main(void){
//     int n,result=0;
//     scanf("%d",&n);

//     int a[n], b[n];
//     for(int i=0;i<n;i++)
//         scanf("%d",&a[i]);
//     for(int i=0;i<n;i++)
//         scanf("%d",&b[i]);
//     sort(a,a+n);
//     sort(b,b+n,compare);

//     for(int i=0;i<n;i++)
//         result+=a[i]*b[i];
//     printf("%d\n",result);
//     return 0;
// }