//ABC013 C - 節制
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int64_t N, H;
int64_t A, B, C, D, E;

bool check_func(lli xx, lli yy){
    lli zz = N-xx-yy;
    if (B*xx+D*yy-E*zz+H>0) return true;
    return false;
}
lli binary_search(lli xx)
{
    lli yst=-1;
    lli yed=N-xx;
    while(abs(yed-yst)>1){
        lli mid=(yed+yst)/2;
        if (check_func(xx,mid)){
			yed = mid;
		}else{
			yst = mid;
		}
    }
    return yed;
}

int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>H;
    cin>>A>>B>>C>>D>>E;
#if 1
    int64_t least=INT64_MAX;
    lli ax,ay,az;
    for (lli xx=0; xx<=N; ++xx) {
        auto yy=binary_search(xx);
        if (least > A*xx+C*yy){
			least = std::min(A * xx + C * yy, least);
            ax=xx;
            ay=yy;
            az=N-xx-yy;
		}
    }
    //cout<<ax<<","<<ay<<","<<az<<endl;
	cout << least << endl;
#else
    int64_t least=INT64_MAX;
    int64_t ax,ay,az,aymin;
	for(int64_t xx = 0; xx <= N; ++xx) {
        int64_t tmp_y = E*N-E*xx-H-B*xx;
        double ymin = std::max((double(tmp_y) / double(D+E)), 0.0);
		for(int64_t yy = (int64_t)ymin; yy <= N; ++yy) {
            int64_t zz = N-xx-yy;
            if (zz>=0) {
                if (B*xx+D*yy-E*zz+H>0) {
                    int64_t yen = A*xx+C*yy;
                    if (least > yen) {
						ax = xx;
						ay = yy;
						az = zz;
                        aymin=ymin;
						least = yen;
					}
                }       
            }
		}
	}
    cout<<ax<<","<<ay<<","<<az<<","<<aymin<<endl;
    cout<<least<<endl;
#endif
	return 0;
}