//
#include <bits/stdc++.h>
using namespace std;
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}
int main() {
    int n;
    cin>>n;
    vector<int> htbl(n,0);
    for(auto &h:htbl){
        cin >> h;
    }
    int ans=0;
    int max = -1;
    for (int i=0;i<htbl.size();++i){
        if (htbl[i] >= max) {
            max = htbl[i];
            ++ans;
        }
    }
    // for(int i=htbl.size()-2;i>=0;--i){
    //     if(htbl[i+1] >= htbl[i]){
    //         ++ans;
    //     } else {
    //         break;
    //     }
    // }
    cout<<ans<<endl;
    return 0;
}