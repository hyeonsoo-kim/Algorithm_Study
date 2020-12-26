#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<size_t, size_t> jewely;

void init(size_t *n, jewely **list){
	cin >> (*n);
   	*list = new jewely[(*n)];
	}	

void register_jewely (size_t *n, jewely **list){
	for (size_t i = 0 ; i<(*n); i++){
		size_t w,p;
		cin >> w >> p ;
		(*list)[i] = {w,p};
		}
	}
	
void register_bag(size_t *n, size_t **list){
	for (size_t i = 0;i<(*n);i++){
		size_t w;
		cin >> w;
		(*list)[i] = w;
		}
	}

size_t solution(size_t *n, jewely **jlist, size_t *nbag, size_t **baglist){

		size_t nofj = (*n), nofb = (*nbag);
		jewely *listofj = (*jlist);
		size_t *listofb = (*baglist);
		size_t result = 0;

		sort(listofb, listofb+nofb);
		sort(listofj, listofj+nofj);
		
		priority_queue<size_t> pq;
		
		size_t jidx = 0;
		for (size_t i = 0 ; i < nofb ; i++){
				while( jidx < nofj && listofj[jidx].first <= listofb[i])
					pq.push(listofj[jidx++].second);

				if (!pq.empty()){
					result += pq.top();
					pq.pop();
					}
			}
		return result;
	}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	jewely *list;
	size_t n, nbag;
	size_t *bag;

	init(&n, &list);
	cin >>nbag;
	bag = new size_t[nbag];

	register_jewely(&n, &list);
	register_bag(&nbag, &bag);
	
	size_t answer = solution(&n,&list,&nbag,&bag);

	cout << answer <<endl;

	delete bag;
	delete list;
	bag = nullptr;
	list = nullptr;
	return 0;	
}
