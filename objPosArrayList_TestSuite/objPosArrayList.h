#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int listSize;
        int arrayCapacity;

    public:
        objPosArrayList();
        ~objPosArrayList();
        objPosArrayList(objPosArrayList &arr);
        objPosArrayList& operator=(objPosArrayList &arr);

        int getSize() const;
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        void printList();
        
        objPos getHeadElement() const;
        objPos getTailElement() const;
        objPos getElement(int index) const;
};

#endif