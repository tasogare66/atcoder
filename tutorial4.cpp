#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    std::vector<int> a;
    a.resize(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    bool all_odd = true;
    int div_count = 0;
    while(all_odd){
        for (auto &v : a)
        {
            if (v % 2 != 0)
            {
                all_odd = false;
                break;
            }
            v /= 2;
        }
        if (all_odd) ++div_count;
    }
    cout<<div_count<<endl;
    return 0;
}