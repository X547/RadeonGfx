#pragma once

#include <private/kernel/util/DoublyLinkedList.h>


template <typename Element, typename GetLink = DoublyLinkedListStandardGetLink<Element>  >
class OwnedDoublyLinkedList: public DoublyLinkedList<Element, GetLink>
{
public:
	using DoublyLinkedList<Element, GetLink>::DoublyLinkedList;
	using DoublyLinkedList<Element, GetLink>::RemoveHead;

	~OwnedDoublyLinkedList()
	{
		while (Element *e = RemoveHead()) {
			delete e;
		}
	}
};
