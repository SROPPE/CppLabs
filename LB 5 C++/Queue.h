//---------------------------------------------------------------------------

#ifndef QueueH
#define QueueH
#include <iostream>
template<typename T>
	class  Node
	{
	public:
		T data;
		Node* pNext;
		Node* pPrev;
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
template<typename T>
class Queue
{
public:
	Queue();
	~Queue();

	void PushBack(T data);
	void PrintQueue();
	T PopFront();
	void Clear();
	int GetSize() { return size; }

private:

	Node<T>* head;
	Node<T>* tail;
	int size;
	void PopFrontClear()
	{
		Node<T>* temp = head;
		head = head->pNext;
		size--;
		delete temp;
	}
};
        template<typename T>
Queue<T>::Queue()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template<typename T>
Queue<T>::~Queue()
{

}
template<typename T>
void Queue<T>::PushBack(T data)
{
	if (head == nullptr && tail == nullptr)
	{
		head = new Node<T>(data);
		tail = head;
	}
	else
	{
		tail->pNext = new Node<T>(data);
		Node<T>* temp = tail;
		tail = tail->pNext;
		tail->pPrev = temp;
	}
	size++;
}
template<typename T>
void Queue<T>::PrintQueue()
{
	Node<T>* current = head;
	while (current!=nullptr)
	{
		std::cout << current->data<< " ";
		current = current->pNext;
	}
}
template<typename T>
T Queue<T>::PopFront()
{
	Node<T>* temp = head;
	Node<T> temp2 = *head;
	head = head->pNext;
	delete temp;
	PushBack(temp2.data);
	size--;
	return temp2.data;
}
template<typename T>
void Queue<T>::Clear()
{
	while (size)
	{
		PopFrontClear();
	}
}
//---------------------------------------------------------------------------
#endif
