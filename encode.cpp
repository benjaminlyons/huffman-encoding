#include <iostream>
#include <queue>
#include <string>
#include <fstream>

#include "tree.h"

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
		Node* n = new Node((char)i, freqs[i]);

		// add to priority queue
		pq->push(*n);
	}

	return pq;
}


// returns the root node of a huffman tree based on
Node* construct_tree(std::priority_queue<Node>* pq){

	while(pq->size() > 1){

	}

	return NULL;
}

void encode(std::string filename){

	int * freqs = get_frequency(filename);

	std::priority_queue<Node>* pq = load_queue(freqs);

	while(!pq->empty()){
		std::cout << pq->top() << std::endl;
		pq->pop();
	}

	free(freqs);

}

int main(int argc, char* argv[]){
	encode("input.txt");
	return 0;
}
