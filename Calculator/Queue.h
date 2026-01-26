#pragma once
#include <iostream>
#include "Token.h"
using namespace std;

class Queue
{
private:
    struct Node
    {
        Token data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    ~Queue()
    {
        while (front != nullptr)
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr; // This is not strictly necessary, but it's good practice
    }

    bool IsEmpty() const
    {
        return front == nullptr;
    }

    void Enqueue(Token value)
    {
        Node* newNode = new Node{ value, nullptr };
        if (IsEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    Token Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty\n";
            exit(1);
        }

        Token value = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;

        return value;
    }

    void Print() const
    {
        Node* temp = front;
        while (temp != nullptr)
        {
            Token tempToken = temp->data;
            tempToken.Print();
            cout << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};
