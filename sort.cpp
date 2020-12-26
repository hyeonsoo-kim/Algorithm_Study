#include <iostream>
#include <cstdint>
#include <cstdio>
using namespace std;


int main() {

	size_t N, number;
	uint32_t *table = new uint32_t[10000]{0,};

	scanf("%d", &N);

	for (size_t i=0;i<N;i++){
		scanf("%d",&number);
		table[number-1]++;
	}


	for (size_t i=0;i<10000;i++){
		if ( table[i] != 0 ) {
			for (uint32_t iter=0;iter<table[i];iter++){
				printf("%d\n",(i+1));
				}
			}
	}

	delete table;
	return 0;
	}

