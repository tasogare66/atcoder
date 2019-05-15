//
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}

int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int N;
    cin>>N;
    vector<string> sv(N);
    for (auto& s: sv) {
        cin>>s;
    }
    int ba=0;
    int xa=0;
    int bx=0;
    int num=0;
    for (const auto& s:sv) {
        for(int i=0;i<s.size()-1;++i){
            if(s[i]=='A'&&s[i+1]=='B'){
                ++num;
            }
        }

        bool a=false;
        bool b=false;
        if (s[0]=='B') b=true;
        if (s[s.size()-1]=='A') a=true;
        if (a&&b) {
            ++ba;
        } else if (a) {
            ++xa;
        } else if (b) {
            ++bx;
        }
    }
    num += std::max(ba-1,0);
    if (ba>0&&xa>0) {
        ++num;
    } else if (ba>0&&bx>0) {
        ++num;
    }
    num+=std::min(xa,bx);
    cout<<num<<endl;
    return 0;
}