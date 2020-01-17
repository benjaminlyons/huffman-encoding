#include<cstdint>
#include<iostream>

class bitvector{
	public:
		bitvector() : size(0), capacity(256) {
			bit_array = (uint8_t*)calloc(capacity/8, 1);	
		};

		void append(bool b){
			if( size > capacity / 2){
				capacity = capacity*2;
				std::cout << capacity << std::endl;
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

		int get(size_t index){
			return (bit_array[index / 8] >> (7 - (index % 8))) % 2;
		}
	private:
		size_t size;
		size_t capacity;
		uint8_t* bit_array;

   friend std::ostream& operator<<(std::ostream&, bitvector&);
};

std::ostream& operator<<(std::ostream& os, bitvector& bv){
	for(size_t i = 0; i < bv.size; i++){
		os << bv.get(i);
	}
	return os;
}


