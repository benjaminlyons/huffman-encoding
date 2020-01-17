#include<cstdint>
#include<iostream>

class bitvector{
	public:
		bitvector() : size(0), capacity(256) {
			bit_array = (int*)calloc(capacity/8, 1);	
		};

		void append(bool b){
			if( size < capacity / 2){
				capacity = capacity*8;
				bit_array = (int*)realloc(bit_array, capacity/8);
			}
			
			// find integer index
			size_t index = size / 8;
			size_t offset = size % 8;

			if(b){
				bit_array[index] = bit_array[index] & 1 << (7 - offset);
			} else {
				bit_array[index] = bit_array[index] & 0 << (7 - offset);
			}

			size++;
		}

		// should only be used if all data is to be read this way
		void append(char i){
			uint8_t test;
			std::cout << test << std::endl;
			for(int j = 0; j < 8; j++){
			}
		}

		int get(size_t index){
			return (bit_array[index / 8] >> (7 - (index % 8))) % 2;
		}
	private:
		size_t size;
		size_t capacity;
		int* bit_array;

   friend std::ostream& operator<<(std::ostream&, bitvector&);
};

std::ostream& operator<<(std::ostream& os, bitvector& bv){
	for(size_t i = 0; i < bv.size; i++){
		os << bv.get(i);
	}
	return os;
}


