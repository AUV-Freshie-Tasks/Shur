#include <iostream>
#include "LRUcache.h"
using namespace std;

int main(){
	LRUcache<int> cache;
	cache.put(2,2);
	cout<<cache.get(2);
	return 0;
}
