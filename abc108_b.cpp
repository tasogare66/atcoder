//AtCoder ABC108 B - Ruined Square
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
struct vec2{
    vec2(){}
	vec2(ll ix, ll iy) : x(ix), y(iy) {}
	ll x=0;
	ll y=0;
	vec2 operator-(const vec2& obj) {
		return vec2(this->x-obj.x,this->y-obj.y);
	}
    vec2 operator+(const vec2& obj){
        return vec2(this->x+obj.x,this->y+obj.y);
    }
};
int main() {
    vec2 p[4];
    cin>>p[0].x>>p[0].y;
    cin>>p[1].x>>p[1].y;
    vec2 d=p[1]-p[0];
    vec2 r=vec2(-d.y,d.x);
    p[2]=p[1]+r;
    p[3]=p[0]+r;
    cout<<p[2].x<<" "<<p[2].y<<" "<<p[3].x<<" "<<p[3].y<<endl;
    return 0;
}