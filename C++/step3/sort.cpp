

// #include <iostream>
// #include <algorithm>
// using namespace std;
// int n,k,arr[5000000];
// int main(void){
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cin>>n>>k;
//   for(int i=0;i<n;i++)
//     cin>>arr[i];
  
//   sort(arr,arr+n);
//   cout<<arr[k-1];
//   return 0;
// }


// //////////10867
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int n;
// vector<int> arr;
// int main(void){
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   cin>>n;
//   arr.resize(n);
//   for(int i=0;i<n;i++){
//     cin>>arr[i];
//   }
//   // sort(arr.begin(),arr.end());

//   arr.erase(unique(arr.begin(),arr.end()),arr.end());
//   for(int i=0;i<arr.size();i++)
//     cout<<arr[i];
//   return 0;
// }
// ///////////10825
// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;

// struct Student{
//   string name;
//   int k;
//   int e;
//   int m;
// };
// int n;
// vector<Student> students(100000);
// bool compare(Student a,Student b){
//   if(a.k==b.k){
//     if(a.e==b.e){
//       if(a.m==b.m)
//         return a.name<b.name;
//       return a.m>b.m;
//     }
//     return a.e<b.e;
//   }
//   return a.k>b.k;
// }
// int main(void){
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);cout.tie(0);
//   cin>>n;
//   string name;
//   int k,e,m;
//   for(int i=0;i<n;i++){
//     cin>>name>>k>>e>>m;
//     students.push_back({name,k,e,m});
//   }
//   sort(students.begin(),students.end(),compare);
//   for(int i=0;i<n;i++)
//     cout<<students[i].name<<"\n";
//   return 0;
// }


// // ///////////////1026
// // #include <iostream>
// // #include <algorithm>

// // using namespace std;
// // int n,a[50],b[50];

// // int main(void){
// //   cin>>n;
// //   for(int i=0;i<n;i++)
// //     cin>>a[i];
// //   for(int i=0;i<n;i++)
// //     cin>>b[i];
// //   sort(a,a+n);
// //   sort(b,b+n,greater<>());
// //   int answer=0;
// //   for(int i=0;i<n;i++){
// //     answer+=a[i]*b[i];
// //   }
// //   cout<<answer<<"\n";

// //   return 0;
// // }

// // /////////////10989
// // #include <iostream>
// // using namespace std;

// // const int MAX=10001;
// // int arr[MAX]={0,};
// // int main(void){
// //   ios_base::sync_with_stdio(0);
// //   cin.tie(0);cout.tie(0);
// //   int n,a;
// //   cin>>n;
// //   for(int i=0;i<n;i++){
// //     cin>>a;
// //     arr[a]++;
// //   }
// //   for(int i=1;i<MAX;i++)
// //     for(int j=0;j<arr[i];j++)
// //       cout<<i<<"\n";
// //   return 0;
// // }