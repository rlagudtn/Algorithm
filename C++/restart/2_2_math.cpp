// #include <iostream>
// #include <vector>
// using namespace std;


// int main(void){
//     int n;
//     unsigned long long int answer;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&arr[i]);
//     }
//     unsigned long long int max=arr[0];
//     unsigned long long int min=arr[0];
    
//     if(n>1){
//         for(int i=1;i<n;i++){
//             if(max<arr[i])
//                 max=arr[i];
//             if(min>arr[i])
//                 min=arr[i];
//         }
//         answer=min*max;
//     }
//     else{
//         answer=arr[0]*arr[0];
//     }
//     printf("%llu\n",answer);

//     return 0;
// }