#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include "tree.h"
#include "bitvector.h"

char decode_char(bitvector& bv, Node* root, size_t& index){
	while(!root->value){
		if(!bv.get(index)){
			root = root->left;
		} else {
			root = root->right;
		}
		index++;
	}
	return root->value;
}

std::string decode_bitvector(bitvector& bv, Node* root){
	std::string message;

	size_t index = 0;
	while(index < bv.get_size()){
		message += decode_char(bv, root, index);
	}
	
	return message;
}

void construct_subtree(Node* root, char c, std::string bv){
	Node* curr = root;
	for(size_t i = 0; i < bv.size(); i++){
		if(bv[i] == '0'){
			if(!curr->left) curr->left = (Node*)calloc(1, sizeof(Node));
			curr = curr->left;

		} else {
			if(!curr->right) curr->right = (Node*)calloc(1, sizeof(Node));
			curr = curr->right;
		}
	}
	curr->value = c;
}

Node* construct_tree(std::map<char, bitvector*>* key){
	Node* root = (Node*)calloc(1, sizeof(Node));

	for(auto it = key->begin(); it != key->end(); it++){
		construct_subtree(root, it->first, it->second->to_string());
	}

	return root;
}

void decode(std::string filename){
	std::ifstream ifs(filename);

	int size;
	ifs >> size;

	std::cout << size << std::endl;

	std::map<char, bitvector*>* key = new std::map<char, bitvector*>();
	
	std::string input;
	char c;
	bitvector* bv;
	while(true){
		ifs.get(c);
		ifs >> input;
		if(input == "ND"){
			break;
		}
		bv = new bitvector(input.substr(0, input.size()));
		(*key)[c] = bv;
		std::cout << c << bv->to_string() << std::endl;
		ifs.get(c);
	}

	ifs.get(c);

	uint8_t* data = (uint8_t*)calloc(size/8+1, sizeof(uint8_t));

	ifs.read((char*)data, size/8+1);
	bitvector d;
	d.set_bit_array(data, size);	


	std::cout << d.to_string() << std::endl;
	Node* root = construct_tree(key);
	print_leafs(root);
	std::cout << count_leafs(root) << std::endl;
	std::string message = decode_bitvector(d, root);
	std::cout << message << std::endl;
}

int main(int argc, char* argv[]){
	decode("data.enc");
	return 0;
}
