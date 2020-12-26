#include <iostream>
#include <queue>
#include <utility> // for pair
#include <vector> 
#include <algorithm> // for sort(3)
#include <cstdio>

using namespace std;


typedef pair<int,int> time;

class order {
public:
	bool operator() (const time &l, const time &r){ 
		if ( l.first == r.first ) 
			return l.second > r.second;
		else
			return l.first > r.first;
		}
};	

int main(){
	vector<time> timetable;
	size_t N;
	int s, t;
	cin >> N;
	timetable.resize(N);

	for (size_t i = 0; i< N; i ++){
		cin >> s >> t;
		timetable.at(i)={s,t};
		}
	
	sort(timetable.begin(), timetable.end());
	
	priority_queue<time,vector<time>,order> timequeue;
	timequeue.push(timetable[0]);
	int count=1;
	for ( size_t i = 1; i<N ; i++) {
		if ( timequeue.top().second > timetable[i].first ) {
			timequeue.push(timetable[i]);
			count++;
		} else {
			timequeue.pop();
			timequeue.push(timetable[i]);
		}
	}

	printf("%d",count);
	return 0;
	}
