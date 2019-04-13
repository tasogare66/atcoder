//ABC049C - 白昼夢 / Daydream
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    ++n; //start分
    vector<int> t(n);
    vector<int> x(n);
    vector<int> y(n);
    for(int i=1;i<n;++i){
        cin >> t[i] >> x[i] >> y[i];
    }
    for (int i = n - 1; i >= 1; --i)
    {
        int t1 = t[i];
        int t0 = t[i-1];
        auto dt = abs(t1-t0);
        auto dx = abs(x[i]-x[i-1]);
        auto dy = abs(y[i]-y[i-1]);
        auto dist = dt - (dx + dy);
        //cout<<dist;
        if (dist >= 0 && dist % 2 == 0) {
            //ok
            continue;
        } else {
            //ng
            cout << "No"<<endl;
            return 0;
        }
    }
    cout << "Yes"<<endl;
    return 0;
}