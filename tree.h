typedef struct Node Node;

struct Node {
	char value;
	int freq;
	Node* left;
	Node* right;

	Node() : value(0), freq(0), left(NULL), right(NULL) {}
	Node(char v, int f) : value(v), freq(f), left(NULL), right(NULL) {}
	Node(char v, int f, Node* l, Node* r) : value(v), freq(f), left(l), right(r) {}

	~Node(){
		if(left)	delete left;
		if(right)	delete right;
	}
};

// bool operator> (const &Node n1, const &Node n2){
// 	return n1.freq > n2.freq;
// }
//
// bool operator>= (const &Node n1, const &Node n2){
// 	return n1.freq >= n2.freq;
// }
//
// bool operator== (const &Node n1, const &Node n2){
// 	return n1.freq == n2.freq;
// }
// bool operator<= (const &Node n1, const &Node n2){
// 	return n1.freq <= n2.freq;
// }

// operator needs to be flipped to have min priority queue
bool operator< (const Node& n1, const Node& n2) {
	return n1.freq > n2.freq;
}

std::ostream& operator<<(std::ostream& os, const Node& n){
	os << n.value << " " << n.freq;
	return os;
}
