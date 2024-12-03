/**
 * @file objPosArrayList.cpp
 * @author Caden Chan (chanc167), Tyler Fong (fongt5)
 * @date 2024-12-02
 * 
 */

#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.
#include <iostream>
#include <stdexcept>

using namespace std;

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

objPosArrayList::objPosArrayList(objPosArrayList &arr) {
    listSize = arr.listSize;
    arrayCapacity = arr.arrayCapacity;
    for(int i=0;i<listSize;i++) {
        aList[i] = arr.aList[i];
    }
}

objPosArrayList& objPosArrayList::operator=(objPosArrayList &arr) {
    if(this == &arr) return *this;
    listSize = arr.listSize;
    arrayCapacity = arr.arrayCapacity;
    for(int i=0;i<listSize;i++) {
        aList[i] = arr.aList[i];
    }
    return *this;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    for(int i=listSize;i>0;i--){
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    listSize ++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    for(int i=0;i<listSize-1;i++) {
        aList[i] = aList[i+1];
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    if(index >= arrayCapacity || index < 0) throw std::out_of_range("Invalid indexes.");
    return aList[index];
}

void objPosArrayList::printList()
{
    objPos testVal;
    
    if(listSize == 0)    
    {
        cout << "List is Empty!" << endl;
        return;
    }

    cout << "List Size: " << getSize() << endl;
    cout << "Array Capacity: " << arrayCapacity << endl;
    cout << "List Content is: { " << endl;
    for(int i = 0; i < listSize; i++)
    {
        testVal = aList[i];
        cout << i << ": (" << testVal.pos -> x << ", " << testVal.pos -> y << ")" << endl;
    }
    cout << "}" << endl;
}