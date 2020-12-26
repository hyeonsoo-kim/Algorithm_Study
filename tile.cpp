#include <iostream>
#include <cstdint>
using namespace std;

uint32_t solution(const int _n) {
	uint32_t answer = 0;
	uint32_t *table = new uint32_t[_n+1]{0,1,3};
	for ( uint8_t idx=3; idx <= _n ; idx++){
		table[idx] = table[idx-1] + 2*table[idx-2];
		}
	answer = table[_n];
	delete table;
	return answer;
}


int main(){
	uint32_t N = 0, res = 0;
	cin >> N;
	res = solution(N);
	cout << res << endl;
	return 0;
}
