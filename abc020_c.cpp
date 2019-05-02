//ABC020 C - 壁抜け
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

struct Position {
	Position(int32_t in_x, int32_t in_y)
		:x(in_x)
		,y(in_y)
	{}
	int32_t x, y;
	bool operator==(const Position &p) const { return x == p.x && y == p.y; }
	bool operator!=(const Position &p) const { return x != p.x || y != p.y; }
	// for sorting
	bool operator<(const Position &p) const {
		return y < p.y || (y == p.y && x < p.x);
	}
};
struct Node {
	Node(const Position& p)
        : m_pos(p)
    {}
    const Position m_pos;
    const Node* m_parent = nullptr;
	lli m_dist=0;
    uint32_t m_flags = 0;
	void setOpen() { m_flags |= 1; }
	void setClosed() { m_flags |= 2; } // visiedでもある
	uint32_t isOpen() const { return m_flags & 1; }
	uint32_t isClosed() const { return m_flags & 2; }
};
class OpenList {
  public:
	void push(Node *node) {
		nodes.push_back(node);
		std::push_heap(nodes.begin(), nodes.end(), _compare);
	}
	Node *pop() {
		std::pop_heap(nodes.begin(), nodes.end(), _compare);
		Node *node = nodes.back();
		nodes.pop_back();
		return node;
	}
	bool empty() const { return nodes.empty(); }
	void clear() { nodes.clear(); }
	void fixup() {
		std::make_heap(nodes.begin(), nodes.end(), _compare);
	}
  protected:
	static inline bool _compare(const Node *a, const Node *b) {
		return (a->m_dist > b->m_dist);
	}
	vector<Node*> nodes;
};

struct Searcher{
    Node* getNode(const Position& pos){
		//重複時は要素は追加されず、firstが、それへのイテレーター
		return &m_node_grid.insert(std::make_pair(pos, Node(pos))).first->second;
    }
    map<Position, Node> m_node_grid;
};

int main() {
    int H,W,T;
#if LOCAL&01
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>H>>W>>T;
    vector<string> cl(H);
    for (auto&& l:cl){
		cin >> l;
	}
    vector<char*> map(cl.size());
	for(int i = 0; i < cl.size(); ++i){
		map[i] = &cl[i][0];
	}
    int sx,sy;
    int gx,gy;
    for(int y=0;y<H;++y){
        for (int x=0;x<W;++x){
            if(map[y][x]=='S'){
                sx=x;
                sy=y;
            }
            if(map[y][x]=='G'){
                gx=x;
                gy=y;
            }
        }
    }

    auto check_func = [&](lli c_x){
        //dijkstra
		// start,goal
		Searcher searcher;
		Node *st_node = searcher.getNode({sx, sy});
		Node *ed_node = searcher.getNode({gx, gy});
		// search
		//std::queue<Node *> que;
        OpenList que;
		st_node->setOpen();
		que.push(st_node);
		do {
			const Node *cur_n = que.pop();
			if(cur_n == ed_node) { //goal
				break;
			}
			//que.pop();
			auto cur_pos = cur_n->m_pos;
			Position offset_tbl[] = {
                Position(0, 1),
                Position(0, -1),
				Position(1, 0),
                Position(-1, 0)
            };
			for(auto &ofs : offset_tbl) {
				auto p = cur_pos;
				p.x += ofs.x;
				p.y += ofs.y;
                if (p.x<0||p.y<0||p.x>=W||p.y>=H){
                    //範囲外
                } else {
                    int cost=(map[p.y][p.x] == '#')?c_x:1;
					Node *n = searcher.getNode(p);
					if(n && (!n->isOpen() || cur_n->m_dist + cost < n->m_dist)) {
						n->m_parent = cur_n;
						n->m_dist = cur_n->m_dist + cost;
						if (!n->isOpen()){
							que.push(n);
							n->setOpen();
						} else {
							que.fixup();
                        }
					}
				}
			}
		} while(!que.empty());
        if (ed_node->m_dist<=T) {
            return true;
        }
        return false;
    };

    //binary search
    int ans=0;
    int c_x_ok=1;
    int c_x_ng=T+1;
    while(abs(c_x_ok-c_x_ng)>1){
        int mid=(c_x_ok+c_x_ng)/2;
        if (check_func(mid)){
			c_x_ok = mid;
		}else{
			c_x_ng = mid;
		}
    }
    ans = c_x_ok;
#if 0
    for (int c_x=1;c_x<=T;++c_x) {
        //dijkstra
		// start,goal
		Searcher searcher;
		Node *st_node = searcher.getNode({sx, sy});
		Node *ed_node = searcher.getNode({gx, gy});
		// search
		//std::queue<Node *> que;
        OpenList que;
		st_node->setOpen();
		que.push(st_node);
		do {
			const Node *cur_n = que.pop();
			if(cur_n == ed_node) { //goal
				break;
			}
			//que.pop();
			auto cur_pos = cur_n->m_pos;
			Position offset_tbl[] = {
                Position(0, 1),
                Position(0, -1),
				Position(1, 0),
                Position(-1, 0)
            };
			for(auto &ofs : offset_tbl) {
				auto p = cur_pos;
				p.x += ofs.x;
				p.y += ofs.y;
                if (p.x<0||p.y<0||p.x>=W||p.y>=H){
                    //範囲外
                } else {
                    int cost=(map[p.y][p.x] == '#')?c_x:1;
					Node *n = searcher.getNode(p);
					if(n && (!n->isOpen() || cur_n->m_dist + cost < n->m_dist)) {
						n->m_parent = cur_n;
						n->m_dist = cur_n->m_dist + cost;
						if (!n->isOpen()){
							que.push(n);
							n->setOpen();
						} else {
							que.fixup();
                        }
					}
				}
			}
		} while(!que.empty());
        if (ed_node->m_dist<=T) {
            ans = std::max(ans,c_x);
        }
	}
#endif
    cout<<ans<<endl;
    return 0;
}