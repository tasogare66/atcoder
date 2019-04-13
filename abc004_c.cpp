//ABC004 C - 入れ替え
#include <bits/stdc++.h>
using namespace std;
int main() {
    int tbl[] = {1,2,3,4,5,6};
    int orig[] = {1,2,3,4,5,6};
    int64_t n;
    cin>>n;
    n%=30;
    for(int64_t i=0;i<n;++i){
        auto p = i%5;
        std::swap(tbl[p],tbl[p+1]);
        // bool flag=true;
        // for(int j=0;j<6;++j){
        //     if (tbl[j] != orig[j]){
        //         flag = false;
        //         break;
        //     }
        // }
        // if(flag) {cout<<i<<endl;}
    }
    for(auto t:tbl){
        cout << t;
    }
    cout<<endl;
    return 0;
}