//ABC0002 B - 罠
#include <bits/stdc++.h>
using namespace std;
int main() {
    string w,ans;
    cin >> w;
    ans.reserve(w.size());
    for(int i=0;i<w.size();++i){
        if (w[i] != 'a' && w[i] != 'i' && w[i] != 'u' && w[i] != 'e' && w[i] != 'o')
        {
            ans.append(1,w[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}