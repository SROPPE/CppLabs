//---------------------------------------------------------------------------

#ifndef ListH
#define ListH
template<typename T>
class List
{
public:
	List();
	~List();

	void Add(T data);
	void Delete(int index);
	void PopFront();
	void Clear();
	bool Contains(T data);
	int GetSize() { return size; }

	T& operator[](const int index);
private:
	template<typename Z>
	class  Node
	{
	public:
		Z data;
		Node* pNext;
		Node(Z data = Z(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	Node<T>* head;
	int size;
};
template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List()
{
	Clear();
}
template<typename T>
void List<T>::Add(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = new Node<T>();
		current = head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}
template<typename T>
void List<T>::Delete(int index)
{
	if (index == 0)
	{
		PopFront();
		return;
	}
	Node<T>* current = this->head;
	Node<T>* preCurrent = this->head;
	int counter = 0;
	while (counter != index)
	{
		preCurrent = current;
		current = current->pNext;
		counter++;
	}
	preCurrent->pNext = current->pNext;
	delete current;
	size--;
}
template<typename T>
void List<T>::PopFront()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}
template<typename T>
void List<T>::Clear()
{
	while (size)
	{
		PopFront();
	}
}
template<typename T>
inline bool List<T>::Contains(T data)
{
	Node<T>* current = head;
	while (current !=nullptr)
	{
		if (current->data == data)
			return true;
		current = current->pNext;
	}
	return false;
}
template<typename T>
T& List<T>::operator[](const int index)
{
	Node<T>* current = new Node<T>();
	current = head;
	int counter = 0;
	while (counter != index)
	{
		current = current->pNext;
		counter++;
	}
	return current->data;
}
//---------------------------------------------------------------------------
#endif
