//ABC017 B - choku語
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    bool ans=true;
#if 1
    int pt = s.size()-1;
    while (pt>=0) {
        if(s[pt]=='o'||s[pt]=='k'||s[pt]=='u'){
			pt-=1;
			continue;
        }
        if(pt>=1&&s[pt]=='h'&&s[pt-1]=='c'){
            pt-=2;
            continue;
        }
        ans = false;
        break;
    }
#else
#endif
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}