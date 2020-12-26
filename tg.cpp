#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class stack{
private:
	    vector<T> _contents;
public:
	    size_t size(void) const {return this->_contents.size();}
	    bool is_empty() const { return this->_contents.size() == 0; }
	    void push(T x) { this->_contents.push_back(x); }
	    void pop(void) { this->_contents.pop_back(); }
	    T head(void) { return (*(this->_contents.end()-1));}
};

void dfs(vector<int>&numbers, const int target, int&cnt, int sum) {
    stack<int> S;
    int current = 0;
    S.push(numbers.at(current));
    while ( !S.is_empty() ) {
        int x = S.head();
        S.pop();
        if ((target == sum) && ( current == numbers.size() )) {
            cnt++;
            return;
	        }
        ++current;
        if ( current >= numbers.size() ) return;
        S.push(sum+numbers.at(current));
        S.push(sum-numbers.at(current));
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
	dfs(numbers, target, answer, 0);
	return answer;
}
int main(){
			vector<int> _n({1,1,1,1,1});
			int t = 3;
			cout << solution(_n,t) << endl;
			return 0;
}

