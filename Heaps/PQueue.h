#ifndef PQUEUE_H
#define PQUEUE_H

#include<iostream>
using namespace std;

class PQueue
{
	int *heap, size, bottom;
	
	void ReHeapUp();
	void ReHeapDown();
	
	public:
	PQueue(int);
	~PQueue();
	void enqueue(int);
	void dequeue();
	int top() const;
};



PQueue::PQueue(int s)
{
	size = s;
	bottom = -1;
	heap = new int[size];
}

PQueue::~PQueue()
{
	delete [] heap;
}

int PQueue::top() const 
{
	return (bottom == -1 ? -1 : heap[0]);;
}

void PQueue::enqueue(int i)
{
	if(bottom != size - 1)
	{
		bottom++;
		heap[bottom] = i;
		ReHeapUp();
	}
}

void PQueue::dequeue()
{
	if(bottom != -1)
	{
		// swap top and bottom
		int temp = heap[0];
		heap[0] = heap[bottom];
		heap[bottom] = temp;
		
		bottom--;
		
		// rebuild heap
		ReHeapDown();
	}
}

void PQueue::ReHeapUp()
{
	int i = bottom;
	
	while(i != 0)
	{
		int p = (i - 1) / 2;
		
		if(heap[i] > heap[p])
		{
			int temp = heap[p];
			heap[p] = heap[i];
			heap[i] = temp;
		}
		
		i = p;
	}
}

void PQueue::ReHeapDown()
{
	int p = 0;
	
	while(p < bottom)
	{
		int lc = 2 * p + 1;
		int rc = 2 * p + 2;
		int bc;
		
		if(lc <= bottom)
			if(lc == bottom)
				bc = lc;
			else
				bc = (heap[lc] > heap[rc] ? lc : rc);
		
		if(heap[p] < heap[bc])
		{
			int temp = heap[p];
			heap[p] = heap[bc];
			heap[bc] = temp;
			
			p = bc;
		}
		else 
			break;
	}
}




#endif