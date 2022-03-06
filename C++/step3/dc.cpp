

// ///////////////1629
// #include <iostream>

// using namespace std;
// int c;
// long long dc(int a,int b){
//   if(b==1)
//     return a%c;
//   if(b%2==0){
//     long long temp=dc(a,b/2);
//     return temp*temp%c;
//   }
//   else
//     return a*dc(a,b-1)%c;
// }
// int main(void){
//   int a,b;
//   cin>>a>>b>>c;
//   cout<<dc(a,b)<<"\n";
//   return 0;
// }