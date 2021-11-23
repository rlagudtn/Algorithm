
// //////////////////10815
// #include <stdio.h>
// #include <algorithm>
// #include <vector>
// using namespace std;
// int main(void){
//     int n,m;
//     scanf("%d",&n);
//     vector<int> cards(n);
//     for(int i=0;i<n;i++)
//         scanf("%d",&cards[i]);
//     sort(cards.begin(),cards.end());
//     scanf("%d",&m);
//     for(int i=0;i<m;i++){
//         int num;
//         scanf("%d",&num);
//         if(binary_search(cards.begin(),cards.end(),num))
//             printf("1");
//         else
//             printf("0");
//         printf(" ");
//     }
//     return 0;
// }
// ///////////////10989
// #include <stdio.h>
// #include <vector>
// #define MAX int(1e5)
// using namespace std;

// int main(void) {
//     int n;
//     scanf("%d",&n);
//     vector<int> bucket(MAX+1);
//     for(int i=0;i<n;i++){
//         int num;
//         scanf("%d",&num);
//         bucket[num]++;
//     }
//     for(int i=0;i<MAX+1;i++){
//         for(int j=0;j<bucket[i];j++)
//             printf("%d\n",i);
//     }
//     return 0;
// }



// //////////////2751
// #include <stdio.h>
// #include <vector>
// using namespace std;
// #define MAX int(1e6)
// int main(void){
//     int n;
//     scanf("%d",&n);
//     vector<int> arr(MAX*2+1);

//     for(int i=0;i<n;i++){
//         int num;
//         scanf("%d",&num);
//         arr[num+MAX]=1;
//     }

//     for(int i=0;i<MAX*2+1;i++){
//         if(arr[i]==1)
//             printf("%d\n",i-MAX);
//     }

    
//     return 0;
// }
// ///////////////2750
// #include <stdio.h>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main(void)  {

//     int n;
//     scanf("%d",&n);

//     vector<int> arr(n);

//     for(int i=0;i<n;i++){
//         scanf("%d",&arr[i]);
//     }
//     sort(arr.begin(),arr.end());

//     for(int i=0;i<n;i++)
//         printf("%d\n",arr[i]);

//     return 0;
// }