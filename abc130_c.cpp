//AtCoder ABC130 C - Rectangle Cutting	
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll W,H,x,y;
    cin>>W>>H>>x>>y;
    double are=W*H;
    are/=2.0;
    //x,yがしゅうじょうなら1
    ll ans=0;
    //if(x>0&&x<W&&y>0&&y<H){
    //    ans=1;
    //}
    double w2=(double)W/2.0;
    double h2=(double)H/2.0;
    if (abs(w2-x)<=FLT_EPSILON&&abs(h2-y)<=FLT_EPSILON) {
        ans=1;
    }
    cout<<fixed<<std::setprecision(10)<<are<<" ";
    cout<<ans<<endl;
    return 0;
}