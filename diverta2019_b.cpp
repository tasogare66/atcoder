//
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}


int main() {
    int R,G,B,N;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>R>>G>>B>>N;
    auto calc = [&](int r,int g, int b){
        return (r*R+g*G+b*B==N);
    };
    int rmax = N/R;
    //int gmax = N/G+1;
    //int bmax = N/B+1;
    int ans =0;
    for (int r=0;r<=rmax;++r) {
        int rnum=r*R;
        int gmax=(N-rnum)/G;
		for(int g = 0; g <= gmax; ++g) {
            int rgnum=g*G+rnum;
            int bmax=(N-rgnum)/B;
            int rest = N-rgnum;
            if (rest >= 0 && rest%B==0) {
                //cout << r << "," << g << ","<< rest/B <<endl;
                ans += 1;//max(rest/B,1);
            }
			// for(int b = 0; b <= bmax; ++b) {
            //     int rgbnum=b*B+rgnum;
            //     ans += (rgbnum==N);
            //     //ans += calc(r,g,b);
			// }
		}
	}
    cout<<ans<<endl;
    return 0;
}