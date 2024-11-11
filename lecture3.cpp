#include "lectures.h"
#include "DoublyLinkedList.h"

void lecture3()
{
	DoublyLinkedList dList;
	dList.PushFront("1");
	dList.PushBack("2");
	dList.Insert(1,"1-2");
	dList.Insert(0, "1-1-2");
	dList.RemoveFront();
	dList.PushBack("1-1-1-2");
	dList.RemoveBack();
	dList.RemoveAt(1);

	std::cout << dList.FrontValue() << std::endl;
	std::cout << dList.TailValue() << std::endl;

	dList.Print();
}