#include <iostream>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,a,b;
    char c;

    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>t>>b;
        cout<<a+b<<"\n";
    }

    return 0;
}