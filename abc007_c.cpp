//ABC007 C - 幅優先探索
#include <bits/stdc++.h>
using namespace std;
struct Position {
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
//open list
class OpenListFIFO {
  public:
	void push(Node *node) {
		m_nodes.push(node);
	}
	Node *pop() {
		Node *node = m_nodes.front();
		m_nodes.pop();
		return node;
	}
	bool empty() const { return m_nodes.empty(); }
	void clear() {
		while(!m_nodes.empty()) {
			m_nodes.pop(); // 先頭要素を削除
		}
	}
  protected:
	std::queue<Node *> m_nodes;
};

int main() {
    int R,C;
    int sy,sx;
    int gy,gx;
    vector<string> cl(R);
    cin>>R>>C;
    cin>>sy>>sx;
    cin>>gy>>gx;
    for(auto& l:cl){
        cin>>l;
    }
    vector<char*> map(cl.size());
	for(int i = 0; i < cl.size(); ++i){
		map[i] = &cl[i][0];
	}
    //start,goal
	Searcher searcher;
    Node* st_node = searcher.getNode(sx,sy);
    Node* ed_node = searcher.getNode(gx,gy);

    auto findNeighbors = [](const Node* n, Position *wptr)->int {
        return 0;
    }
	auto identifySuccessorsDFS = [&](const Node *n) {
		Position buf[8];
		const int num = findNeighbors(n, &buf[0]);
		for(int i = num - 1; i >= 0; --i) {
			Position jp = buf[i];
			Node *jn = getNode(jp);
			//FW_ASSERT(jn && jn != n);
			if(!jn->isClosed() && !jn->isOpen()) {
				jn->parent = n;
				m_open->push(jn);
				jn->setOpen();
			}
		}
	};

	//open list
    OpenListFIFO open_list;
	do {
		if(open_list.empty()) {
			break;//NO_PATH;
		}
		Node *n = m_open->pop();
		n->setClosed();
	 	if(n == ed_node) {
	// 		return FOUND_PATH;
	 	}
	// 	identifySuccessors_base(n);
	} while(true);//m_stepsRemain >= 0);

	return 0;
}