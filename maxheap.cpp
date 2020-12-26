#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <cstdio>

int inline log2(size_t x){
	size_t res;
	if ( x == 0 ) res = -1;
	else if ( x == 1 ) res = 0;
	else {
		while ( x >= 0 ) {
			x = ( x >> 1 );
			res++;
			}
		}
	return res;
	}

template <typename KeyType>
class heap{
	private:
		KeyType* contents;
		size_t capacity;
		size_t size;
		bool max;
	public:
		heap(size_t _cap=2, bool _ismaxheap=true):capacity(_cap), size(0),max(_ismaxheap){
			try {
				if (_cap < 1) throw std::logic_error("Capacity MUST BE >= 1");
				this->contents = new KeyType[this->capacity+1];
				}
			catch(std::logic_error &le){
				std::cerr << le.what() << std::endl;
				}
			}
		heap(KeyType *arr, size_t length):capacity(log2(length)+1), size(length){
			try{
				if (arr == nullptr || this->capacity == 0 ) throw std::logic_error("Cannot Make Heap");
				this->contents = new KeyType[this->capacty+1];
				}
			catch(std::logic_error &le){
				std::cerr << le.what() << std::endl;
				}
			}
		void push(const KeyType &key){
			// capacity check and expand array
			if ( this->size == this->capacity ) {
				this->capacity *=2;
				this->contents = (KeyType*)realloc(this->contents, this->capacity);
				}
			size_t idx = ++(this->size);
			//Bubbe up or down
			while ( idx != 1 && (this->max) && this->contents[idx/2] < key) {
				this->contents[idx] = this->contents[idx/2];
				idx /= 2;
				}
			while ( idx != 1 && (!this->max) && this->contents[idx/2] > key) {
				this->contents[idx] = this->contents[idx/2];
				idx /= 2;
				}
			this->contents[idx] = key;
			}
		bool empty(void) { return size == 0 ; }
		void pop(void){
			try{
				if ( this->empty() ) throw std::logic_error("Cannot POP element.");
				this->contents[1].~KeyType();
				
				KeyType last = this->contents[size--];

				size_t idx = 1;
				size_t child = 2;

				while (child <= size){
					if (child < size && this->contents[child] < contents[child+1] && this->max ) child++;
					if (child < size && this->contents[child] > contents[child+1] && (!this->max) ) child++;

					if(  (last >= this->contents[child] && (this->max) ) || (last <= this->contents[child] && (!this->max) ) ) break;

					this->contents[idx] = this->contents[child];
					idx = child;
					child *=2;
					}
				this->contents[idx] = last;
			}
			catch(std::logic_error &e){
				std::cerr << e.what() << std::endl;
				exit(-1);
				}	
			}
		KeyType& front(void) { return this->contents[1]; }
		KeyType& front(void) const { return this->front(); }	
	};

void parse_opcode(const size_t* opcodearr, const size_t length, heap<size_t>& H){
    for (size_t i = 0 ; i<length; i++) {
        size_t opcode = opcodearr[i];
        if ( opcode == 0 ) {
            if (H.empty())printf("%ld\n",0);
            else {
                printf("%ld\n",H.front());
                H.pop();
                }
            }
        else H.push(opcode);
        }
    }

int main() {
    size_t N;
    size_t *opcodearr;
    scanf("%ld",&N);
    opcodearr = new size_t[N];
    heap<size_t> H(N);
    for (size_t iter = 0 ; iter<N ; iter++){
        scanf( "%ld", &(opcodearr[iter]) );
        }
    parse_opcode(opcodearr, N, H);
    delete opcodearr;
    opcodearr = nullptr;
    }
