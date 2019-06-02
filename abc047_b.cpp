//AtCoder ABC047 B - すぬけ君の塗り絵 2 イージー / Snuke's Coloring 2 (ABC Edit)
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int W,H,N;
    cin>>W>>H>>N;
    int minx=0;
    int maxx=W;
    int miny=0;
    int maxy=H;
    for(int i=0;i<N;++i){
        int x,y,a;
        cin>>x>>y>>a;
		switch(a) { 
        case 1: minx=max(x,minx); break;
        case 2: maxx=min(x,maxx); break;
		case 3: miny=max(y,miny); break;
        case 4: maxy=min(y,maxy); break;
		}
	}
    int ans=max(maxx-minx,0)*max(maxy-miny,0);
    cout<<ans<<endl;
    return 0;
}