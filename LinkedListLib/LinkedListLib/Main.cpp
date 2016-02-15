#include "Header.h"
#include "LinkedList.h"
#include "LinkedList.cpp"

void main(){
	SingleLinkedList<int> l;

	for (int i = 0; i < 1000; i++){
		l.addHead(rand() % 1000);
	}
	clock_t start, finish;
	start = clock();
	l.quickSort();
	finish = clock();
	l.printf();
	int len = l.getLength();
	cout << len << endl;
	cout << "Thoi gian thuc hien: " << finish - start << endl;
}