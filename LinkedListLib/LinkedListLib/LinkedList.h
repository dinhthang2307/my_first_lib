#pragma once
#include "Header.h"
// <class T>


template <class T>
class SingleLinkedList
{
	struct Node{
		T data;
		Node* pNext;
	};
	Node* pHead;
	Node* pTail;
public:
	SingleLinkedList();
	~SingleLinkedList();
	bool IsEmpty();
	int getLength();
	void insert(int pos, T val);
	void printf();
	void addHead(T);
	void SListAppend(SingleLinkedList);
	void SListAppend2(SingleLinkedList);
	void addTail(T val);
	void remove(int);
	void removeHead();
	void removeTail();
	void clear();
	int getEntry(int pos);
	void setEntry(int pos, T val);
	void quickSort();
};