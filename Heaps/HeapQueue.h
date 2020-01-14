#include <iostream>
#ifndef HEAPQUEUE_H
#define HEAPQUEUE_H


/*
David Nguyen 
Professor Hank Stalica
Data Structures and Algorithm
Homework #6 Heaps
May 1st, 2019
*/


using namespace std;

class HeapQueue {
private:
	int *heap;
	int size;
	int bottom;
public:
	HeapQueue(int s);
	~HeapQueue();
	void enqueue(int i);
	void dequeue();
	int top();
	void ReHeapUp();
	void ReHeapDown();
};



HeapQueue::HeapQueue(int s) {
	heap = new int[s];
	size = s;
	bottom = -1;
}



HeapQueue::~HeapQueue() {
	delete [] heap;
}



void HeapQueue::enqueue(int i) {
	if (bottom != size) {
		bottom = bottom + 1;
		heap[bottom] = i;
		ReHeapUp();
	}
}




void HeapQueue::dequeue() {
	if (bottom != -1) {
		heap[0] = heap[bottom];
		bottom--;
		ReHeapDown();
	}
	else {
		return;
	}
}




int HeapQueue::top() {
	if (bottom == -1) {
		return -1;
	}
	else {
		return heap[0];
	}
}




void HeapQueue::ReHeapUp() {
	int i, p, temp;
	i = bottom;
	while (i != 0) {
		p = (i - 1) / 2;
		if(heap[i] > heap[p]){
			temp = heap[p];
			heap[p] = heap[i];
			heap[i] = temp;
		}
		i = p;
	}
}




void HeapQueue::ReHeapDown() {
	int p = 0;
	int lc, rc, bc, temp;
	while (p < bottom) {
		lc = 2 * p + 1;
		rc = 2 * p + 2;
		if (lc <= bottom) {
			if (lc == bottom) {
				bc = lc;
			}
			else {
				if (heap[lc] > heap[rc]) {
					bc = lc;
				}
				else {
					bc = rc;
				}
			}
		}
		else {
			return;
		}
		if (heap[p] < heap[bc]) {
			temp = heap[p];
			heap[p] = heap[bc];
			heap[bc] = temp;
			p = bc;
		}
		else {
			return;
		}
	}
}

#endif