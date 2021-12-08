/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 6
    Template of DoublyLinkedList class
    */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>


using namespace std;

template <class T>
class ListNode{
	public:
		T data;
    ListNode<T> *next;
    ListNode<T> *prev;

		ListNode();

		ListNode(T d);

		~ListNode();

};

template <class T>
ListNode<T>::ListNode(){

}

template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

template<class T>
ListNode<T>::~ListNode(){
  if (next != NULL){
    next = NULL;
    prev = NULL;

    delete next;
    delete prev;
  }
}

template <class T>
class DoublyLinkedList{
	public:
		ListNode<T> *front;
		ListNode<T> *back;
		unsigned int size;

		DoublyLinkedList();
		~DoublyLinkedList();
		void insertBack(T d);
		T removeFront();
		void removeAt(int pos);
		T getFront();
		void printList();
		unsigned int getSize();
    bool isEmpty();
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  delete front;
  delete back;
}

template<class T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);

  // IF LIST IS EMPTY
  if (size == 0){
    front = node;
  }

  else{
    back->next = node;
    node->prev = back;
  }

  back = node;
  ++size;
}

template<class T>
T DoublyLinkedList<T>::removeFront(){
  if (!isEmpty()){
  ListNode<T> *oldFront = front;

    T oldData = oldFront->data;

    // IF THERE IS ONLY ONE ELEMENT
  if (front->next == NULL){
        front = NULL;
        back = NULL;
  }

    // MORE THAN ONE ELEMENT
  else{
    front->next->prev = NULL;

        front = front->next;
  }

  delete oldFront;

  size--;

  return oldData;
  }

else{
  return T();
}
}

template<class T>
void DoublyLinkedList<T>::removeAt(int pos){
  int index = 0;
  ListNode<T> *current = front;
  ListNode<T> *previous = front;

  while (index != pos){
    previous = current;
    current = current->next;
    ++index;
  }

  // WE FOUND WHAT NEEDS TO BE DELETED

  previous->next = current->next;
  current->next->prev = previous;
  current->next = NULL;
  current->prev = NULL;

  size--;
  delete current;
}

template<class T>
T DoublyLinkedList<T>::getFront(){
  return front->data;
}

template<class T>
void DoublyLinkedList<T>::printList(){
  if (front != NULL){
    ListNode<T> *current = front;

    while (true){
      if (current == NULL){
        break;
      }

      cout << current->data << ", ";
      current = current->next;
    }
  }

  else{
    cout << "None";
  }
}

template<class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}

template<class T>
bool DoublyLinkedList<T>::isEmpty(){
  return (size == 0);
}

#endif
