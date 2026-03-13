#pragma once
#include "data.hpp"
#include <string>

using std::string;

class ItemNode
{
public:
    ItemNode(string newItem = "", ItemNode* newNext = nullptr);

    string getItem() const;
    ItemNode* getNext() const;

    void setItem(string newItem);
    void setNext(ItemNode* newNext);

private:
    string item;
    ItemNode* pNext;
};

class QueueNode
{
public:
    ~QueueNode();

    QueueNode();
    QueueNode(Data* newData);
    QueueNode(Data* newData, QueueNode* newNext);

    Data* getData() const;
    QueueNode* getNext() const;
    ItemNode* getItemHead() const;

    void setData(Data* newData);
    void setNext(QueueNode* newNext);
    void setItemHead(ItemNode* newItemHead);

private:
    Data* pData;
    QueueNode* pNext;
    ItemNode* pItemHead;   // NEW
};