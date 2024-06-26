#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList != sizeArray && sizeList>0)
    {
        for(int i = sizeList; i > 0; i--)
        {
            aList[i].setObjPos(aList[i-1]);
        }

        aList[0].setObjPos(thisPos);

        sizeList++;
    }
    if (sizeList<=0)
    {
        aList[0].setObjPos(thisPos);
        sizeList=1;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList != sizeArray)
    {
        aList[sizeList++].setObjPos(thisPos);
    }

}

void objPosArrayList::removeHead()
{
    if (sizeList > 1)
    {
        for (int i = 0; i < sizeList - 1; i++)
        {
            aList[i] = aList[i + 1];
        }

        sizeList--;
    }
    if (sizeList == 1)
    {
        sizeList--;
    }
}

void objPosArrayList::removeTail()
{
    if (sizeList>0)
    {
    sizeList--;//"lazy deletion" (saves computation time)
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}