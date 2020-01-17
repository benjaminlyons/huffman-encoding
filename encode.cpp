#include <iostream>
#include <queue>
#include <string>
#include <fstream>

#include "tree.h"
#include "bitvector.h"

// default frequency size is 256 for ascii
#define FREQ_SIZE 256

int* get_frequency(std::string filename){
	std::ifstream ifs(filename);

	// check if file opened successfully
	if (!ifs.is_open()){
		return NULL;
	}

	// now allocate memory for the array
	// we are using ascii so we need 256 spots
	int * freqs = (int*)calloc(FREQ_SIZE, sizeof(int));

	char c;
	while( ifs.get(c) ){
		freqs[(int)c] ++;
	}

	ifs.close();

	return freqs;
}

// this creates and returns a priority with nodes for each
// character and its corresponding frequency
std::priority_queue<Node>* load_queue(int* freqs){
	std::priority_queue<Node>* pq = new std::priority_queue<Node>();

	// loop through all characters
	for (int i = 0; i < FREQ_SIZE; i++){
		// if frequency is 0 ignore it
		if (!freqs[i])	continue;

		// create a node
		Node n((char)i, freqs[i]);

		// add to priority queue
		pq->push(n);
	}

	return pq;
}


// returns the root node of a huffman tree based on
Node* construct_tree(std::priority_queue<Node>* pq){

	while(pq->size() > 1){
		Node* n1 = new Node(pq->top());
		pq->pop();
		Node* n2 = new Node(pq->top());
		pq->pop();

		// std::cout << *n1 << " " << *n2 << std::endl;

		Node* parent = new Node('\0', n1->freq + n2->freq, n1, n2);

		pq->push(*parent);
	}

	Node* root = new Node(pq->top());
	pq->pop();
	return root;
}

void generate_header(const Node* node, std::string curr){
	if(!node)	return;
	// check if leaf
	if(!node->left && !node->right){
		std::cout << *node << " " << curr << std::endl;
	} else {
		generate_header(node->left, curr + "0");
		generate_header(node->right, curr + "1");
	}	
}

void encode(std::string filename){

	int * freqs = get_frequency(filename);

	std::priority_queue<Node>* pq = load_queue(freqs);

	const Node* root = construct_tree(pq);

	// generate_codes(root, "");
	std::cout << (root->left->value) << std::endl;


}

int main(int argc, char* argv[]){
	// std::cout << sizeof(bool) << std::endl;
	bitvector bv;
	bv.append(true);

	// encode("input.txt");
	return 0;
}
