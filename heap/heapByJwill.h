/*  这是一个heap相关的文件，以数组为基础的简单heap操作，包括增删改基本功能。
*   堆序性质由heaptype决定。
*
*   @date ：2015-09-05
*   @author ：Jwill.
*/
#include "vector"
using namespace std;

#ifndef HEAP_BY_JWILL
#define HEAP_BY_JWILL

enum heaptype{min,max};
class heapbyjwill
{
public:
	heapbyjwill():heapsize(0),type(heaptype::min){}
	heapbyjwill(vector<int> _cont,heaptype _type):heapcontainer(_cont),type(_type)
	{
		heapsize=heapcontainer.size();
		buildheap();
	}
	~heapbyjwill(){}
	bool empty()
	{
		return heapsize==0;
	}
	void heapfy(int index)
	{
		int left=2*index+1,right=2*index+2;
		int hint;
		if (type==heaptype::max)
		{
			if (left<heapsize&&heapcontainer[left]>heapcontainer[index])
				hint=left;
			else
				hint=index;
			if (right<heapsize&&heapcontainer[right]>heapcontainer[hint])
				hint=right;
			if (hint>index)
			{
				::swap(heapcontainer[index],heapcontainer[hint]);
				heapfy(hint);
			}
		}
		else
		{
			if (left<heapsize&&heapcontainer[left]<heapcontainer[index])
				hint=left;
			else
				hint=index;
			if (right<heapsize&&heapcontainer[right]<heapcontainer[hint])
				hint=right;
			if (hint>index)
			{
				::swap(heapcontainer[index],heapcontainer[hint]);
				heapfy(hint);
			}
		}
		
	}
	void buildheap()
	{
		for (int index=(heapsize-1-1)/2;index>=0;index--)
		{
			heapfy(index);
		}
	}
	void fixup(int index)
	{
		int parent=(index-1)/2;
		int hint;
		if (parent>=0)
		{
			if (heaptype::max==type)
			{
				if (heapcontainer[index]>heapcontainer[parent])
					hint=parent;
				else
					hint=index;
				if (hint<index)
				{
					::swap(heapcontainer[hint],heapcontainer[index]);
					fixup(hint);
				}
			}
			else
			{
				if (heapcontainer[index]<heapcontainer[parent])
					hint=parent;
				else
					hint=index;
				if (hint<index)
				{
					::swap(heapcontainer[hint],heapcontainer[index]);
					fixup(hint);
				}
			}
		}
	}
	void insert(int element)
	{
		heapcontainer.push_back(element);
		heapsize=heapcontainer.size();
		fixup(heapsize-1);
	}
	bool erease(int index)
	{
		if (index<0||index>=heapsize)
		{
			return false;
		}
		else
		{
			int erearse_element=heapsize-1;
			::swap(heapcontainer[index],heapcontainer[erearse_element]);
			heapcontainer.pop_back();
			heapsize=heapcontainer.size();
			if (index<heapsize-1)
			{
				heapfy(index);
			}
			return true;
		}

	}

protected:
private:
	vector<int>  heapcontainer;
	unsigned int heapsize;
    heaptype type;
};


#endif