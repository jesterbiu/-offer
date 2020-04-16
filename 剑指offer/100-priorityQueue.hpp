#pragma once
#include <functional>
#include <deque>
#include <vector>
#include <utility>
#include <stdexcept>
typedef unsigned int uint;

template<class T, class Compare, class Container>
class priorityQueue
{
private:
	std::deque<T> dq;
	Compare cmp;

	// heapify the b-tree using cmp to determine the order between elements	
	void heapify()
	{
		uint sz = dq.size();
		for (uint i = sz - 1; i > 0; i--)
		{
			uint parent = (i - 1) / 2;
			if (cmp(arr[i], arr[parent]))
			{
				std::swap(arr[i], arr[parent]);
			}
		}
	}

	void setDefaultCmp()
	{
		cmp = [](const T& a, const T& b) { return a > b; }
	}

public:
	priorityQueue() { setDefaultCmp(); }
	priorityQueue(Compare c) { cmp = c; }
	priorityQueue(const Container& ctnr)
	{ 
		dq.assign(ctnr.begin(), ctrn.end()); 
		setDefaultCmp();
	}
	priorityQueue(const Container& ctnr, Compare c)
	{
		cmp = c;
		dq.assign(ctnr.begin(), ctrn.end());
		setDefaultCmp();
	}
	priorityQueue(const priorityQueue& oth)
	{ 
		dq = oth.dq;
		cmp = oth.cmp;
	}
	priorityQueue& operator=(const priorityQueue& oth)
	{
		if (&oth == this)
		{
			return *this;
		}

		dq = oth.dq;
		cmp = oth.cmp;		
		return *this;
	}

	size_t size()
	{
		return dq.size();
	}

	T top()
	{
		return dq[0];
	}

	void push(const T& val)
	{
		dq.push_back(val);
		heapify();
	}

	void pop()
	{
		if (dq.empty())
		{
			throw std::underflow_error("empty queue!");
		}

		dq[0] = dq[dq.size() - 1];
		dq.pop_back();
		heapify();
	}
};




// enter true for ascending order, false for descending order
template<class T>
void heapSort(T* arr, uint sz, bool min)
{
	if (nullptr == arr || sz <= 1)
	{
		return;
	}
	if (sz == 2)
	{
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		return;
	}

	for (uint i = sz; i > 0; i--)
	{
		// heapify
		if (min)
		{
			heapifyMax(arr, i);
		}
		else
		{
			heapifyMin(arr, i);
		}

		// extract
		extractTop(arr, i);

	}

}