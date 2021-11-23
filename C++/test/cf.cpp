#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(int a,int b){
    return a>b;
}
bool compareV(pair<string,pair<int,int>> a, pair<string,pair<int,int>> b){
    if(a.second.first==b.second.first){
        return a.second.second>b.second.second;
    }
    else{
        return a.second.first>b.second.first;
    }
}
int main(void){
    vector<pair<int,int>> v;

    sort(v.begin(),v.end());
    int a[5]={9,3,3,5,2};
    sort(a,a+5,compare);

}