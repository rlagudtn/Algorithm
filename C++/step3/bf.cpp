//////////////1451
#include <iostream>
using namespace std;
int n,m,arr[50][50];
long long answer=0,t=0;
int get(int l,int r,int t,int b){
  int sum=0;
  for(int i=t;i<b;i++){
    for(int j=l;j<r;j++)
      sum+=arr[i][j];
  }
  return sum;
}
void fun1(){
  for(int i=1;i<n;i++){
    int f1=get(0,m,0,i);
    int f2=get(0,m,n-i,n);
    
    for(int j=1;j<m;j++){
      int l1=get(0,j,i,n);
      int l2=get(0,j,0,n-i);
      answer=max(answer,f1*l1*(t-f1-l1));
      answer=max(answer,f2*l2*(t-f2-l2));
    }
  }
}void fun2(){
  for(int i=1;i<m;i++){
    int f1=get(0,i,0,n);
    int f2=get(m-i,m,0,n);
    for(int j=1;j<n;j++){
      int l1=get(i,m,0,j);
      int l2=get(0,m-i,0,j);
      answer=max(answer,f1*l1*(t-f1-l1));
      answer=max(answer,f2*l2*(t-f2-l2));
    }
  }
}
void fun3(){
  for(int i=1;i<n-1;i++){
    int s1=get(0,m,0,i);
    for(int j=i+1;j<n;j++){
      int s2=get(0,m,i,j);
      answer=max(answer,s1*s2*(t-s1-s2));
    }
  }
}
void fun4(){
  for(int i=1;i<m-1;i++){
    int s1=get(0,i,0,n);
    for(int j=i+1;j<m;j++){
      int s2=get(i,j,0,n);
      answer=max(answer,s1*s2*(t-s1-s2));
    }
  }
}
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;
  for(int i=0;i<n;i++){
    string temp;
    cin>>temp;
    for(int j=0;j<m;j++){
      arr[i][j]=temp[j]-'0';
      t+=arr[i][j];
    }
  }

  fun1();

  fun2();

  fun3();

  fun4();
  cout<<answer<<"\n";
  return 0;

}


// /////////////////1107 
// #include <iostream>

// using namespace std;
// int n,m,broken[11];
// int possible(int n){
//   string temp=to_string(n);
//   for(int i=0;i<temp.size();i++){
//     for(int j=0;j<m;j++){
//       if(temp[i]-'0'==broken[j])
//         return 0;
//     }
//   }
//   return temp.size();
// }
// int main(void){
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cin>>n>>m;
//   for(int i=0;i<m;i++)
//     cin>>broken[i];
//   int answer=abs(n-100);
//   for(int i=0;i<=1000000;i++){
//     int size=possible(i);
//     if(size>0 &&abs(n-i)+size<answer){
//       answer=abs(n-i)+size;
//     }
//   }
//   cout<<answer<<"\n";
//   return 0;
// }



// // ///////////////1476
// // #include <iostream>

// // using namespace std;

// // int main(void){
// //   int e,s,m;
// //   cin>>e>>s>>m;
// //   int year=0;
// //   while(true){
// //     e--;s--;m--;
// //     year++;
// //     if(e==0&&s==0&&m==0)
// //       break;
// //     if(e==0)
// //       e=15;
// //     if (s==0)
// //       s=28;
// //     if(m==0)
// //       m=19;
// //   }
// //   cout<<year;
// //   return 0;
// // }