//ABC011 C - 123引き算
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    int ng[3];
    cin>>N;
    cin>>ng[0]>>ng[1]>>ng[2];
    int cn=0;
    auto check = [&](int add){
        int v=cn + add;
        if (v==ng[0]||v==ng[1]||v==ng[2]) {
            return false;
        }
        if (v > N) {
            return false;
        }
        return true;
    };
    for (int i = 0; i<100; ++i) {
        bool ok_flag = false;
        for (int nn=3; nn>=1;--nn) {
			if(check(nn)) {
				cn += nn;
                ok_flag = true;
                break;
			}
		}
        if (!ok_flag) {
            break;
        }
    }
    cout<<((cn==N)?"YES":"NO")<<endl;
    return 0;
}