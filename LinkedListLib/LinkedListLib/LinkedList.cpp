#include "LinkedList.h"
template <class T>
SingleLinkedList<T>::SingleLinkedList()
{
}
template <class T>
SingleLinkedList<T>::~SingleLinkedList()
{
}
template <class T>
bool SingleLinkedList<T>::IsEmpty(){
	if (pHead == NULL && pTail == NULL)
		return true;
	else
		return false;
}
template <class T>
int SingleLinkedList<T>::getLength(){
	if (IsEmpty())
		return 0;
	else{
		int iCount = 0;
		Node* pointer = pHead;
		while (pointer != pTail){
			pointer = pointer->pNext;
			iCount++;
		}
		return ++iCount;
	}
}
template <class T>
void SingleLinkedList<T>::insert(int pos, T val){
	if (IsEmpty()){
		addHead(val);
	}
	else{
		Node* temp = new Node;
		temp->pNext = NULL;
		temp->data = val;
		Node *left = new Node;
		Node *right = new Node;
		right = pHead;
		left = pHead;
		int iCount = 0;
		while ((right->pNext != NULL) && (iCount < pos)){
			right = right->pNext;
			left = right;
			iCount++;
		}
		left->pNext = temp;
		if (temp->pNext = pHead)
			temp->pNext = NULL;
		else
			temp->pNext = right;

		//ptail
		if (pTail->pNext == NULL)
			return;
		else
			pTail = pTail->pNext;
	}
}
template <class T>
void SingleLinkedList<T>::printf(){
	Node* temp = pHead;
	int iCount = 1;
	if (temp != NULL) {
		while (temp->pNext != NULL){
			cout << "Node " << iCount << " :" << temp->data << endl;
			temp = temp->pNext;
			iCount++;
		}
		cout << "Node " << iCount << " :" << pTail->data << endl;
	}
	else
		cout << "List is empty" << endl;
}
template <class T>
void SingleLinkedList<T>::addHead(T val){
	Node* temp = new Node;
	temp->data = val;
	temp->pNext = NULL;
	if (IsEmpty()){
		pHead = temp;
		pTail = pHead;
	}
	else{
		temp->pNext = pHead;
		pHead = temp;
	}
}
template <class T>
void SingleLinkedList<T>::addTail(T val){
	Node* temp = new Node;
	temp->data = val;
	temp->pNext = NULL;
	if (temp != NULL){
		if (IsEmpty())
			addHead(val);
		else{
			pTail->pNext = temp;
			pTail = temp;
		}
	}
	else
		cout << "Khong the chen " << val << " vao danh sach" << endl;
}
template <class T>
void SingleLinkedList<T>::removeHead(){
	if (IsEmpty())
		cout << "Danh sach da rong! Khong the xoa." << endl;
	else{
		if (pHead == pTail){
			pHead = NULL;
			pTail = NULL;
		}
		else{
			Node* temp;
			temp = pHead;
			pHead = temp->pNext;
			temp->pNext = NULL;
			delete temp;
		}
	}
}
template <class T>
void SingleLinkedList<T>::removeTail(){

	if (IsEmpty())
		cout << "Danh sach da rong! Khong the xoa." << endl;
	else{
		if (pHead == pTail){
			pHead = NULL;
			pTail = NULL;
		}
		else{
			Node* temp = pHead;
			while (temp->pNext != pTail)
			{
				temp = temp->pNext;
			}

			pTail = temp;
			pTail->pNext = NULL;
		}
	}
}
template <class T>
void SingleLinkedList<T>::remove(int pos){
	pos--;
	int iCount = 0;
	if (IsEmpty())
		cout << "Danh sach rong! khong the xoa." << endl;
	else{
		Node* temp = pHead;
		Node* temp2 = temp;
		int iCount = 0;
		if (pos == 0)
			removeHead();
		else if (pos < getLength()){
			while (iCount < pos && temp->pNext != NULL){
				temp2 = temp;
				temp = temp->pNext;
				iCount++;
			}
			if (temp == pTail)
				removeTail();
			else{
				temp = temp->pNext;
				temp2->pNext = temp;
			}
		}
		else
			return;
	}
}
template <class T>
void SingleLinkedList<T>::clear(){
	while (!IsEmpty())
		removeTail();
}
template <class T>
int SingleLinkedList<T>::getEntry(int pos){
	Node* temp = pHead;
	int iCount = 0;
	if (pos < getLength())
	{
		while (iCount < pos)
		{
			temp = temp->pNext;
			iCount++;
		}
		return temp->data;
	}

	else

		return 0;
}
template <class T>
void SingleLinkedList<T>::setEntry(int pos, T val){
	Node* temp = pHead;
	if (pos < getLength())
		cout << "Khong the thuc hien";
	else
	{
		int iCount = 0;

		while (iCount < pos)
		{
			iCount++;
			temp = temp->pNext;
		}
	}
	temp->data = val;
}
template <class T>
void SingleLinkedList<T>::SListAppend(SingleLinkedList l){
	if (l.pHead == NULL) return;
	if (pHead == NULL){
		Node* temp;
		temp = l.pHead;
		while (temp != NULL)
		{
			addTail(temp->data);
			temp = temp->pNext;
		}
	}
	else{
		pTail->pNext = l.pHead;
		pTail = l.pTail;
	}
}
template <class T>
//append list before original list
void SingleLinkedList<T>::SListAppend2(SingleLinkedList l){
	if (l.IsEmpty())
		return;
	if (IsEmpty()){
		pHead = l.pHead;
		pTail = l.pTail;
	}
	else{
		l.pTail->pNext = pHead;
		pHead = l.pHead;
	}
}
template <class T>
void SingleLinkedList<T>::quickSort(){
	Node *temp, *temp2;
	SingleLinkedList l1, l2;
	if (pHead == pTail)
		return;
	temp = pHead;
	pHead = pHead->pNext;
	while (pHead != NULL){
		temp2 = pHead;
		if (temp2->data >= temp->data){
			l1.addHead(temp2->data);
			removeHead();
		}
		else{
			l2.addHead(temp2->data);
			removeHead();
		}
	}
	l1.quickSort();
	l2.quickSort();
	SListAppend(l1);
	addHead(temp->data);
	SListAppend2(l2);
}
//void TemporaryFunction(){
//	SingleLinkedList<int> l;
//}