typedef struct Node Node;

struct Node {
	char value;
	int freq;
	Node* left;
	Node* right;

	Node() : value(0), freq(0), left(NULL), right(NULL) {}
	Node(char v, int f) : value(v), freq(f), left(NULL), right(NULL) {}
	Node(char v, int f, Node* l, Node* r) : value(v), freq(f), left(l), right(r) {}
	Node(const Node& n) : value(n.value), freq(n.freq), left(n.left), right(n.right) {}
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

void print_leafs(const Node* root){
	if(!root)	return;

	if(!root->left && !root->right){
		std::cout << *root << std::endl;
	}
	else{
		print_leafs(root->left);
		print_leafs(root->right);
	}	
}
