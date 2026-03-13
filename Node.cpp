#include "Node.hpp"

ItemNode::ItemNode(string newItem, ItemNode* newNext)
{
    item = newItem;
    pNext = newNext;
}

string ItemNode::getItem() const
{
    return item;
}

ItemNode* ItemNode::getNext() const
{
    return pNext;
}

void ItemNode::setItem(string newItem)
{
    item = newItem;
}

void ItemNode::setNext(ItemNode* newNext)
{
    pNext = newNext;
}

QueueNode::~QueueNode()
{
    delete pData;

    ItemNode* pCur = pItemHead;
    while (pCur != nullptr)
    {
        ItemNode* temp = pCur;
        pCur = pCur->getNext();
        delete temp;
    }
}

QueueNode::QueueNode()
{
    pData = nullptr;
    pNext = nullptr;
    pItemHead = nullptr;
}

QueueNode::QueueNode(Data* newData)
{
    pData = newData;
    pNext = nullptr;
    pItemHead = nullptr;
}

QueueNode::QueueNode(Data* newData, QueueNode* newNext)
{
    pData = newData;
    pNext = newNext;
    pItemHead = nullptr;
}

Data* QueueNode::getData() const
{
    return pData;
}

QueueNode* QueueNode::getNext() const
{
    return pNext;
}

ItemNode* QueueNode::getItemHead() const
{
    return pItemHead;
}

void QueueNode::setData(Data* newData)
{
    pData = newData;
}

void QueueNode::setNext(QueueNode* newNext)
{
    pNext = newNext;
}

void QueueNode::setItemHead(ItemNode* newItemHead)
{
    pItemHead = newItemHead;
}