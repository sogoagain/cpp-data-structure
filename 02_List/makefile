all: listTestApp listADT listIterator

# header files
HEADER = ArrayList/ArrayList.hpp SinglyLinkedList/SinglyLinkedList.hpp CircularLinkedList/CircularLinkedList.hpp

listTestApp: listTestApp.cpp $(HEADER)
	g++ -o listTestApp listTestApp.cpp

listADT: listADT.cpp $(HEADER)
	g++ -o listADT listADT.cpp

listIterator: listIterator.cpp $(HEADER)
	g++ -o listIterator listIterator.cpp
