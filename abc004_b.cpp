//ABC004 B - 回転
#include <bits/stdc++.h>
using namespace std;
int main() {
    //char cc[4][4];
    array<array<char,4>,4> cc;
    for(int x=0;x<4;++x){
        for (int y = 0; y < 4; ++y)
        {
            cin >> cc[x][y];
        }
    }
    array<array<char,4>,4> ans = cc;
    for(int x=0;x<4;++x){
        for (int y = 0; y < 4; ++y)
        {
            ans[3-x][3-y] = cc[x][y];
        }
    }
    //result
    for(auto l : ans){
        cout << l[0] << " " << l[1] << " " << l[2] << " " << l[3]<<endl;
    }
    return 0;
}