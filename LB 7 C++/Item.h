//---------------------------------------------------------------------------

#ifndef ItemH
#define ItemH
#include"List.h"
template<typename T>
class Item
{
public:
	Item();
	~Item();
	List<T> node;
private:

};

template<typename T>
inline Item<T>::Item()
{
}

template<typename T>
inline Item<T>::~Item()
{
}
//---------------------------------------------------------------------------
#endif
