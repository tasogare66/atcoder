//ABC007 C - 幅優先探索
#include <bits/stdc++.h>
using namespace std;
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
	int m_dist=0;
    uint32_t m_flags = 0;
	void setOpen() { m_flags |= 1; }
	void setClosed() { m_flags |= 2; } // visiedでもある
	uint32_t isOpen() const { return m_flags & 1; }
	uint32_t isClosed() const { return m_flags & 2; }
};
struct Searcher{
    Node* getNode(const Position& pos){
		//重複時は要素は追加されず、firstが、それへのイテレーター
		return &m_node_grid.insert(std::make_pair(pos, Node(pos))).first->second;
    }
    map<Position, Node> m_node_grid;
};
int main() {
    int R,C;
    int sy,sx;
    int gy,gx;
#if 0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>R>>C;
    cin>>sy>>sx;
    cin>>gy>>gx;
    vector<string> cl(R);
    for(auto& l:cl){
        cin>>l;
    }
    vector<char*> map(cl.size());
	for(int i = 0; i < cl.size(); ++i){
		map[i] = &cl[i][0];
	}
	//start,goal
	Searcher searcher;
    Node* st_node = searcher.getNode({sx-1,sy-1});
    Node* ed_node = searcher.getNode({gx-1,gy-1});
	//search
	std::queue<Node*> que;
	st_node->setOpen();
	que.push(st_node);
    do {
        const Node* cur_n = que.front();
		if (cur_n == ed_node) { //goal
			break;
		}
        que.pop();
		auto cur_pos = cur_n->m_pos;
		Position offset_tbl[]={
			Position(0,1),
			Position(0,-1),
			Position(1,0),
			Position(-1,0)
		};
		for(auto &ofs : offset_tbl) {
			auto p = cur_pos;
			p.x += ofs.x;
			p.y += ofs.y;
			if(map[p.y][p.x] == '.') {
				Node *n = searcher.getNode(p);
				if(n && !n->isOpen()) {
					n->m_parent = cur_n;
					n->m_dist = cur_n->m_dist + 1;
					n->setOpen();
					que.push(n);
				}
			}
		}
    } while(!que.empty());
	cout<<ed_node->m_dist<<endl;
	return 0;
}