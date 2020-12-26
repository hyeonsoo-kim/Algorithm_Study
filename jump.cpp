#include <iostream>
#include <cstdint>

using namespace std;

uint32_t solution(uint32_t n, uint32_t *table){
	uint32_t res;
	uint32_t *status = new uint32_t[n];
	if (table != nullptr) {
		status[0] = table[0];
		for (uint32_t i = 1 ; i < n ; i++){
			status[i] = status[i-1] + table[status[i-1]];
			if (status[i] >= n) { res = i+1; break; }
			}
		}
	delete status;
	return res;
	}

int main() {
	uint32_t N, *M;
	cin >> N;
	M = new uint32_t[N];
	for ( uint32_t i = 0; i < N ; i++){
		cin >> M[i];
		}
	cout << solution(N,M)<< endl;
	return 0;
	}
	
