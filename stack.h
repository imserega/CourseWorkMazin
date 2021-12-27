#pragma once
#include <iostream>


#define MAX_STACK_SIZE 20

using namespace std;

template <typename T>
class Stack{
private:
	struct Node{
		T data;
		Node* prev;
		Node(const T element) {
			data = element;
			prev = 0;
		}
	};
	Node* current;
	size_t size_stack;
public:
	Stack();
	~Stack();
	void push(const T);
	T peek();
	void pop();
	size_t size();
	bool isEmpty();
};

template <typename T>
Stack<T>::Stack(){
	current = 0;
	size_stack = 0;
}

template <typename T>
Stack<T>::~Stack()
{
	while (current)
		pop();
}

template <typename T>
void Stack<T>::push(const T element)
{
	Node* temp = current;
	current = new Node(element);
	current->prev = temp;
	size_stack++;
}

template <typename T>
void Stack<T>::pop()
{
	if (size_stack) {
		Node* temp = current->prev;
		delete current;
		current = temp;
		size_stack--;
	}
	else {
		throw std::out_of_range("stack is isEmpty");
	}
}

template <typename T>
T Stack<T>::peek()
{
	if (isEmpty())
	{
		throw std::out_of_range("isEmpty");
	}
	else return current->data;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return size_stack == 0;
}

template <typename T>
size_t Stack<T>::size()
{
	return size_stack;
}