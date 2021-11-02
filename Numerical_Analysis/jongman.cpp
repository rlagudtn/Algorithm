//예제 13.3
#include <vector>
#include <algorithm>
using namespace std;
//단일 변수 다항식 p의 계수가 주어질 때 미분한 결과 p' 의 계수를 반환한다.
vector<double> differentiate(const vector<double>& poly);

//1차 혹은 2차 방정식을 푼다
vector<double> solveNaive(const vector<double>& poly);

//다항식 f(x)의 계수 poly가 주어지고 x0가 입력으로 들어올 때 f(x0)를 반환한다.
double f(const vector<double>& poly,double x0);

//방정식의 해의 절대 값은 L 이하여야 한다. 구간 [-L, L] 로 임시 설정
const double L=25;

//방정식 sum(poly[i]*x^i) 의 근을 반환한다.
vector<double> solve(const vector<double>& poly){
    int n=poly.size()-1;
    if(n<=2) return solveNaive(poly);

    vector<double> derivative=differentiate(poly);
    vector<double> sols=solve(derivative); //sols에는 극점이 존재함.

    //이 극점 사이를 하나하나 검사하며 근이 있나 확인한다.
    
    //양 끝 부분을 극점으로 추가해준다.
    sols.insert(sols.begin(),-L-1);
    sols.insert(sols.end(),L+1);

    vector<double> ret;
    for(int i=0;i+1<sols.size()-1;i++){
        double x1=sols[i],x2=sols[i+1];
        double y1=f(poly,x1),y2=f(poly,x2);

        //f(x1) 과 f(x2)의 부호가 같은 경우는 없다.
        if(y1*y2>0) continue;
        
        //불변 조건: f(x1)<=0<f(x2)
        if(y1>y2)
            swap(x1,x2);swap(y1,y2);
        
        //이분법을 사용하자.
        for(int i=0;i<100;i++){
            double midx=(x1+x2)/2;
            double midy=f(poly,midx);
            if(y1*midy>0)
            {
                x1=midx;
                y1=midy;
            }
            else{
                x2=midx;
                y2=midy;
            }
        }
        ret.push_back((x1+x2)/2);
    }
    sort(ret.begin(),ret.end());
    return ret;
}















// // 이분법 구현 예제 13.1
// #include <algorithm>
// #include <math.h>
// using namespace std;
// bool f(double x);
// double bisection(double lo,double hi){
//     //
//     if(f(lo)>0){
//         swap(lo,hi);
//     }
//     while(fabs(hi-lo)>2e-7){
//         double mid=(lo+hi)/2;
//         double fmid=f(mid);
//         if(fmid<=0)
//             lo=mid;
//         else 
//             hi=mid;
//     }
//     return (hi+lo)/2;
// }














