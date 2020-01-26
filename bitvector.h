#include<cstdint>
#include<iostream>

class bitvector{
	public:
		bitvector() : size(0), capacity(256) {
			bit_array = (uint8_t*)calloc(capacity/8, 1);	
		};

		bitvector(std::string s) : bitvector() {
			for(char c : s){
				if(c == '0'){
					append(false);
				} else{
					append(true);
				}
			}

		}

		~bitvector() {
			free(bit_array);
		}

		std::string to_string(){
			std::string s;
			for(size_t i = 0; i < size; i++){
				if(get(i)){
					s += '1';
				} else {
					s += '0';
				}
			}
			return s;
		}

		void append(bitvector& bv){
			for(size_t i = 0; i < bv.size; i++){
				append(bv.get(i));
			}	
		}

		void append(bool b){
			if( size > capacity / 2){
				capacity = capacity*2;
				// std::cout << capacity << std::endl;
				bit_array = (uint8_t*)realloc(bit_array, capacity);
			}
			
			// find integer index
			size_t index = size / 8;
			size_t offset = size % 8;

			if(b){
				bit_array[index] = bit_array[index] | (1 << (7 - offset));
			} else {
				bit_array[index] = bit_array[index] & ~(1 << (7 - offset));
			}

			size++;
		}

		void append(char c, int amount){
			if(amount > 8)	amount = 8;
			uint8_t i = (uint8_t) c;
			bool b;
			for(int j = 0; j < amount; j++){
				b = (i >> (7 - j)) % 2;	
				append(b);
			}
		}

		bool get(size_t index){
			return (bit_array[index / 8] >> (7 - (index % 8))) % 2;
		}
	private:
		size_t size;
		size_t capacity;
		uint8_t* bit_array; friend std::ostream& operator<<(std::ostream&, bitvector&); 
}; 
std::ostream& operator<<(std::ostream& os, bitvector& bv){
	// print number of bits
	os << "Size: " << bv.size << std::endl;
	// then print data
	// for(size_t i = 0; i < bv.size; i+=8){
		// os << bv.bit_array[i/8];
		// os << bv.to_string();
	// }
	os << bv.to_string();
	return os;
}


