#include "lectures.h"
#include "LinkedList.h"

void lecture2()
{
	ILinkedList iList;

	iList.PushFront(10);
	iList.TailValue();
	iList.PushBack(30);
	iList.TailValue();
	iList.InsertAfter(iList.GetNode(0),20);
	iList.RemoveBack();
	iList.TailValue();
}
