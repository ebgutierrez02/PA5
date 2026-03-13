#include "queue.hpp"

Queue::Queue()
{
    pHead = nullptr;
    pTail = nullptr;
}

Queue::~Queue()
{
    while (pHead != nullptr)
    {
        QueueNode* temp = pHead;
        pHead = pHead->getNext();

        delete temp;
    }
}

bool Queue::isEmpty() const
{
    return pHead == nullptr;
}

bool Queue::enqueue(int customerCounter, int serviceTime)
{
    int numItems = rand() % 10 + 1;   
    serviceTime = numItems;           

    Data* newCustomer = new Data(customerCounter, serviceTime, 0);
    QueueNode* pMem = new QueueNode(newCustomer);

    if (pMem != nullptr)
    {
        pMem->setItemHead(buildItemList(numItems));

        if (pHead == nullptr)
        {
            pHead = pTail = pMem;
        }
        else
        {
            pTail->setNext(pMem);
            pTail = pMem;
        }
        return true;
    }

    return false;
}

Data* Queue::dequeue()
{
    if (pHead == nullptr)
    {
        return nullptr;
    }

    QueueNode* pTemp = pHead;
    Data* returnData = pHead->getData();

    pTemp->setData(nullptr);
    pHead = pHead->getNext();

    if (pHead == nullptr)
    {
        pTail = nullptr;
    }

    delete pTemp;
    return returnData;
}

void Queue::printQueue() const
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    QueueNode* pCur = pHead;

    while (pCur != nullptr)
    {
        Data* pData = pCur->getData();
        cout << "Customer #" << pData->getCustomerNumber()
            << ", Service: " << pData->getServiceTime()
            << ", Total: " << pData->getTotalTime()
            << ", Items: ";
        printItems(pCur->getItemHead());
        cout << endl;

        pCur = pCur->getNext();
    }

    cout << "NULL" << endl;
}

void Queue::incrementWaitTime()
{
    QueueNode* pCur = pHead;

    while (pCur != nullptr)
    {
        int data = pCur->getData()->getTotalTime();
        data++;
        pCur->getData()->setTotalTime(data);
        pCur = pCur->getNext();
    }
}

void Queue::processCustomer()
{
    if (pHead != nullptr)
    {
        int data = pHead->getData()->getServiceTime();
        data--;
        pHead->getData()->setServiceTime(data);

        if (pHead->getData()->getServiceTime() == 0)
        {
            cout << "Customer #" << pHead->getData()->getCustomerNumber()
                << " has finished. Total time in line: "
                << pHead->getData()->getTotalTime() << endl;

            Data* removed = dequeue();
            delete removed;
        }
    }
}

QueueNode* Queue::getHead() const
{
    return pHead;
}

QueueNode* Queue::getTail() const
{
    return pTail;
}

void Queue::setHead(QueueNode* newHead)
{
    pHead = newHead;
}

void Queue::setTail(QueueNode* newTail)
{
    pTail = newTail;
}

ItemNode* Queue::buildItemList(int numItems)
{
    string groceryOptions[5] = { "cereal", "milk", "steak", "bread", "eggs" };

    ItemNode* pHead = nullptr;
    ItemNode* pTail = nullptr;

    for (int i = 0; i < numItems; i++)
    {
        string randomItem = groceryOptions[rand() % 5];
        ItemNode* pNew = new ItemNode(randomItem, nullptr);

        if (pHead == nullptr)
        {
            pHead = pTail = pNew;
        }
        else
        {
            pTail->setNext(pNew);
            pTail = pNew;
        }
    }

    return pHead;
}

void Queue::printItems(ItemNode* pHead) const
{
    ItemNode* pCur = pHead;
    while (pCur != nullptr)
    {
        cout << pCur->getItem();
        if (pCur->getNext() != nullptr)
        {
            cout << ", ";
        }
        pCur = pCur->getNext();
    }
}