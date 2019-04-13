//ABC0002 C - 直訴
#include <bits/stdc++.h>
using namespace std;
int main() {
    int xa, ya, xb, yb, xc, yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    xb -= xa;
    yb -= ya;
    xc -= xa;
    yc -= ya;
    cout<<fixed<<std::setprecision(10)<<std::abs(xb*yc - yb*xc)/2.0<<endl;
    // if (ans % 2 == 0)
    // {
    //     cout << ans / 2 << endl;
    // }
    // else
    // {
    //     cout << ans / 2 << ".5"<<endl;
    // }
    return 0;
}