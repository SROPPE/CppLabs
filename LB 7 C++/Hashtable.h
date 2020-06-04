//---------------------------------------------------------------------------

#ifndef HashtableH
#define HashtableH
#include"Item.h"
#include<string>
template<typename T>
class HashTable
{
public:
	 HashTable(int size);
	~ HashTable();
	void Add(T item)
	{
		auto k = GetHash(item);
		items[k].node.Add(item);
	}
	bool Search(T item)
	{
		auto k = GetHash(item);
		return items[k].node.Contains(item);
	}
	std::string GetTable()
	{
		std::string res;
		for (int i = 0; i < size; i++)
		{
			int size1 =items[i].node.GetSize();
			if (size1 > 0)
			{
				for (int k = 0; k < size1; k++)
				{
					res += std::to_string(items[i].node[k]) + " ";
				}
				res += '\n';
			}
		}
		return res;
	}
    void Clear()
	{

		for (int i = 0; i < size; i++)
		{
			int size1 = items[i].node.GetSize();
			if (size1 > 0)
			{
				items[i].node.Clear();
			}
		}
	}
	Item<T> *items;
	int size;
private:
	int GetHash(T item)
	{
		return item * item % size;
	}
};
template<typename T>
inline HashTable<T>::HashTable(int size)
{
	items = new Item<T>[size];
	this->size = size;
}

template<typename T>
inline HashTable<T>::~HashTable()
{
}

//---------------------------------------------------------------------------
#endif
