////////////////1406에디터
#include <iostream>
#include <list>

using namespace std;

int main(void){
    string input;
    int n;
    char cmd,character;
    cin>>input;

    list<char> editer;
    for(int i=0;i<input.size();i++){
        editer.push_back(input[i]);
    }

    list<char>::iterator it=editer.end();

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cmd;
        switch (cmd)
        {
        case 'L':
            if(it!=editer.begin())
                it--;
            break;
        case 'D':
            if(it!=editer.end())
                it++;
            break;
        case 'B':
            if(it!=editer.begin()){
                it--;
                it=editer.erase(it);
                
            }
            
            break;
        
        case 'P':
            cin>>character;
            it=editer.insert(it,character);
            it++;
            break;
        default:
            break;
        }
    }
    for(it=editer.begin();it!=editer.end();it++)
        cout<<(*it);
    cout<<"\n";

    return 0;
}

// //////////////10845 큐
// #include <iostream>
// #include <queue>

// using namespace std;
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);


//     int n;
//     queue<int> q;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         string cmd;
//         cin>>cmd;
//         if(cmd=="push"){
//             int num;
//             cin>>num;
            
//             q.push(num);
//         }
//         else if(cmd=="size")
//             cout<<q.size()<<"\n";
//         else if(cmd=="empty"){
//             if(q.empty())
//                 cout<<1<<"\n";
//             else
//                 cout<<0<<"\n";
//         }
//         else if(cmd=="back"){
//             if(q.empty())
//                 cout<<-1<<"\n";
//             else    
//                 cout<<q.back()<<"\n";
//         }
//         else if(cmd=="front"||cmd=="pop"){
//             if(q.empty())
//                 cout<<-1<<"\n";
//             else{
//                 cout<<q.front()<<"\n";
//                 if(cmd=="pop")
//                     q.pop();
//             }
//         }

//     }

//     return 0;
// }


/////////////////10848 스택
// #include <iostream>
// #include <sstream>
// #include <stack>
// #include <vector>
// using namespace std;

// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);

//     stack<int> st;
//     int n,number;
//     string cmd;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>cmd;
//         if(cmd=="push"){
//             cin>>number;
//             st.push(number);
//         }
//         else if(cmd=="pop"||cmd=="top"){
//             if(st.empty())
//                 cout<<-1<<"\n";
//             else{
//                 cout<<st.top()<<"\n";
//                 if(cmd=="pop")
//                     st.pop();
//             }
//         }
//         else if(cmd=="size"){
//             cout<<st.size()<<"\n";
//         }
//         else if(cmd=="empty"){
//             if(st.empty())
//                 cout<<1<<"\n";
//             else    
//                 cout<<0<<"\n";
//         }
//     }

//     return 0;
// }