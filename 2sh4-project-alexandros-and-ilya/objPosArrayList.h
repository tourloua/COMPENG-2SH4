#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 364 //change this when changing board dimensions
//(#of x coordinates-2) x (#of y coordinates-2)

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int sizeList;
        int sizeArray;

    public:
        objPosArrayList();
        ~objPosArrayList();

        int getSize();
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);
};

#endif