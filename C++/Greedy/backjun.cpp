#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool desc(int a,int b){
    return a>b;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> pos,neg;
    int zero=0,one=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num>1) 
            pos.push_back(num);
        else if(num<0)
            neg.push_back(num);
        else if(num==0)    
            zero++;
        else if(num==1)
            one++;
    }
    sort(pos.begin(),pos.end(),desc);
    sort(neg.begin(),neg.end());
    int pIndex=0,nIndex=0;
    int ret=0;
    for(pIndex;pIndex+1<pos.size();pIndex=pIndex+2){
        ret+=pos[pIndex]*pos[pIndex+1];
    }
    if(pIndex<pos.size()){
        ret+=pos[pIndex];
    }
    for(nIndex;nIndex+1<neg.size();nIndex=nIndex+2){
        ret+=neg[nIndex]*neg[nIndex+1];
    }
    //0이 없는 경우 그냥 neg 하나 남은거 더해줌
    if(zero==0 && nIndex<neg.size()){
        ret+=neg[nIndex];
    }
    ret+=one;

    cout<<ret<<"\n";

    

}

/////////////////////1783
// #include <iostream>

// using namespace std;

// int main(void){
//     int n,m;
//     cin>>n>>m;
//     int ret;
//     if(m>=6 && n>=3){
//         ret=m-2;
//     }
//     else if(((m>=5 &&m<7 )&&n==2)||(m==3&&n>=3)){
//         ret=3;
//     }
//     else if((m>=4 &&n>=3)||(m>=7 &&n==2)){
//         ret= 4;
//     }
//     else if(n==1 ||m==1 ||(n==2&&m==2)){
//         ret= 1;
//     }
//     else{
//         ret= 2;
//     }

//     cout<<ret<<"\n";
//     return 0;
// }