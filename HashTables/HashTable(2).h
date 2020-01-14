#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<string>
#include<iostream>
using std::string;
using std::cout;
using std::endl;

class HashTable
{
	private:
	struct Element
	{
		string key;
		int mark;		// 0 = empty, 1 = empty but deleted, 2 = used
	};
	
	Element* table;
	int size;
	int hash(string) const;
	
	public:
	HashTable(int);
	~HashTable();
	void insert(string);
	void remove(string);
	bool isFull() const;
	bool isEmpty() const;
	void clear();
	void print() const;
	bool find(string) const;
};

int HashTable::hash(string s) const
{
	int sumOfCodes = 0;
	
	for(char c : s)
		sumOfCodes += c;
	
	return sumOfCodes % size;
}

HashTable::HashTable(int s)
{
	size = s;
	table = new Element[s];
	clear();
}

HashTable::~HashTable()
{
	delete [] table;
}

void HashTable::insert(string s)
{
	if(!isFull())
	{
		// get the hash index
		int hi = hash(s);
		
		// while there is a collision, move to the 
		// next element
		while(table[hi].mark == 2)
			hi = (hi + 1) % size;
		
		// once that's done, add the value to the table
		table[hi].key = s;
		table[hi].mark = 2;
	}
}

void HashTable::remove(string s)
{
	if(!isEmpty())
	{
		int i = 0;
		int hi = hash(s);
		
		while(table[hi].mark > 0 && i < size)
		{
			if(table[hi].mark == 2 && table[hi].key == s)
				break;
			
			hi = (hi + 1) % size;
			i++;
		}
		
		if(table[hi].mark == 2 && table[hi].key == s)
			table[hi].mark = 1;
	}
}

bool HashTable::isFull() const
{
	int i = 0;
	bool full = true;
	
	while(i < size && full)
	{
		if(table[i].mark < 2)
			full = false;
		
		i++;
	}
	
	return full;
}

bool HashTable::isEmpty() const
{
	int i = 0;
	bool empty = true;
	
	while(i < size && empty)
	{
		if(table[i].mark == 2)
			empty = false;
		
		i++;
	}
	
	return empty;
}

void HashTable::clear()
{
	for(int i = 0; i < size; i++)
		table[i].mark = 0;
}

void HashTable::print() const
{
	int i = 0;
	
	while(i < size)
	{
		if(table[i].mark == 2)
			cout << table[i].key << endl;
		
		i++;
	}
	
	cout << endl;
}

bool HashTable::find(string s) const
{
	int hi = hash(s);
	bool found = false;
	
	int i = 0;
	while(hi > 0 && !found && i < size)
	{
		if(table[hi].mark == 2 && table[hi].key == s)
			found = true;
		
		hi = (hi + 1) % size;
		i++;
	}
	
	return found;
}

#endif