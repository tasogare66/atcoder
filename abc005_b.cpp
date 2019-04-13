//ABC005 B - おいしいたこ焼きの食べ方
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    std::vector<int> tbl(n,0);
    for(int i=0;i<n;++i){
        cin >> tbl[i];
    }
    int least=INT_MAX;
    for(auto v:tbl){
        if (least > v)
        {
            least = v;
        }
    }
    cout<<least<<endl;
    return 0;
}