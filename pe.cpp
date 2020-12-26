#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> count_of_uniform(n,1);
    for ( int& x : lost ) {
        count_of_uniform[x-1]--;
    	}
    for ( int& x : reserve) {
        count_of_uniform[x-1]++;
    }
    for( size_t idx = 0; idx < n ; idx ++) {
        if ( count_of_uniform[idx] == 0 ) {
            if ( count_of_uniform[idx+1] == 2 ) {
                count_of_uniform[idx]++; count_of_uniform[idx+1]--;
            	}
            else if ( count_of_uniform[idx-1] == 2 ) {
                count_of_uniform[idx]++; count_of_uniform[idx-1]++;
            	}
        	}
    	}
    for ( int& x : count_of_uniform ) {
        if ( x>= 1) answer++;
    }
    return answer;
}

int main() {
	int n = 5;
	vector<int> lost = {2,4};
	vector<int> reserve = {1,3,5};
	cout << solution(n,lost,reserve) <<endl;
}
