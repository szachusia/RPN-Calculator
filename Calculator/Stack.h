#pragma once
#include <iostream>
#include "Token.h"

using namespace std;

template <class Type>
class Stack
{
private:
	struct Node
	{
		Type data{};
		Node* next = nullptr;
	};
	Node* top = nullptr;

public:

	~Stack()
	{
		while (top != nullptr)
		{
			Node* temp = top;
			top = top->next;
			delete temp;
		}
	}

	void Push(Type value)
	{
		Node* new_node = new Node;
		new_node->data = value;
		new_node->next = top;

		top = new_node;
	}

	Type Pop()
	{
		if (top == nullptr)
		{
			cout << "Stack is empty\n";
			exit(1);
		}

		Type value = top->data;
		Node* temp = top;
		top = top->next;
		delete temp;

		return value;
	}

	Type Peek() const
	{
		if (top == nullptr)
		{
			cout << "Stack is empty\n";
			exit(1);
		}

		return top->data;
	}

	void Print() const
	{
		Node* current = top;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << "\n";
	}

	bool IsEmpty() const
	{
		return top == nullptr;
	}
};