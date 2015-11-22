
#include "heapByJwill.h"
#include "iostream"

using namespace std;

int main()
{
	int a[]={1,5,3,2,6,8,7,9,4};
	vector<int> vctint(a,a+9);

	heaptype type=heaptype::min;

	heapbyjwill heap(vctint,type);
	if (heap.empty())
	{
		cout << "empty!";
	}
	heap.insert(11);
	heap.erease(1);

	return 0;
}