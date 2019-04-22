//ABC006 C - スフィンクスのなぞなぞ
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N=7,M=23;
    cin>>N>>M;
    //b+2c=M-2N
    auto res = M-2*N;
    int a = -1, b = -1, c = 0;
	for(c = 0; c <= res / 2; ++c) {
		b = res - 2 * c;
		if(b >= 0 && N - b - c >= 0) {
			a = N - b - c;
			break;
		}
	}
	if(a < 0) {
		a = -1;
		b = -1;
		c = -1;
	}
	cout << a << " " << b << " " << c << endl;
	return 0;
}