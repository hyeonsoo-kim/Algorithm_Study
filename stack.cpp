#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class stack{
	private:
		int *contents;
		size_t size;
		size_t capacity;
	public:
		stack(void):size(0), capacity(2){
			this->contents = new int[this->capacity];
		}
		void push(const int& x){
			if ( this->size == this->capacity ){
				this->capacity *=2;
				int *tmp = (int*)realloc( this->contents, this->capacity);
				if ( tmp != nullptr) this->contents = tmp;
				else {
					delete this->contents;
					cerr << "ERROR" << endl;
					exit(-1);
				}
			}
			this->contents[size++] = x;
		}
		void pop(void) {
			if (size > 0 ) {
				this->contents[size-1] = 0;
				size--;
			}
		}
		int top(void) { if (size ==0) return -1; else return this->contents[size-1]; }
		bool empty(void) { return size == 0; }
		size_t Size(void) { return this->size; } 
			
	};

enum opcode { ERROR,PUSH,POP,SIZE,EMPTY,TOP };

opcode compile_cmd(const string &cmd){
    if (cmd == "push") return PUSH;
    else if (cmd == "pop") return POP;
    else if (cmd == "size") return SIZE;
    else if (cmd == "empty") return EMPTY;
    else if (cmd == "top") return TOP;
    return ERROR;
}


int parse_opcode(stack& S){
    int logging = -3;
    string op; 
	cin >> op;
    opcode _op = compile_cmd(op);
	switch(_op){
		case PUSH:{
			int arg;
			cin >> arg;
			S.push(arg);
            logging = -2;
			break;
			}
		case POP:{
			logging = S.top();
			S.pop();
			break;
			}
		case SIZE:{
			logging = S.Size();
			break;
			}
		case EMPTY:{
			logging = static_cast<int>(S.empty());
			break;
			}
		case TOP:{
			logging = S.top();
			break;
			}
        default: {logging = -3; break;}
		}
    return logging;
	}

int main() {
		cout.tie(0);
		ios_base::sync_with_stdio(false);
		stack S;
		size_t ln;
        int * results = new int[ln];
		cin >> ln;
		for ( size_t i = 0; i< ln ; i++){
			results[i] = parse_opcode(S);
			}
        for (size_t i2 = 0; i2<ln ; i2++){
            if (results[i2] != -3 && results[i2] != -2 )
                cout << results[i2] << endl;
        }
		return 0;
	}


