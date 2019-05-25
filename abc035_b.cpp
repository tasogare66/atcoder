//AtCoder ABC035 B - ドローン
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
struct Pos{
    int x=0;
    int y=0;
    int dist()const{
        return abs(x)+abs(y);
    }
};
int main() {
    string S;
    int T;
    cin>>S;
    cin>>T;
    Pos p;
    int cnt=0;
    for(auto c:S){
        if(c=='L'){
            p.x -= 1;
        }else if(c=='R'){
			p.x += 1;
		}else if(c=='U'){
			p.y += 1;
		}else if(c=='D'){
			p.y -= 1;
		}else if(c=='?'){
            ++cnt;
        }
    }
    int ans=0;
    if(T==1){//max
        ans = p.dist() + cnt;
    } else {//min
        ans = max( p.dist()-cnt,(abs(p.dist()-cnt)%2) );
    }
    cout<<ans<<endl;
    return 0;
}