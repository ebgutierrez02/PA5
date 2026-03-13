#include "data.hpp"

Data::~Data() {}

Data::Data() : customerNumber(0), serviceTime(0), totalTime(0) {}

Data::Data(int customerNum, int serviceTime, int totalTime)
    : customerNumber(customerNum), serviceTime(serviceTime), totalTime(totalTime)
{
}

int Data::getCustomerNumber() const
{
    return customerNumber;
}

int Data::getServiceTime() const
{
    return serviceTime;
}

int Data::getTotalTime() const
{
    return totalTime;
}

void Data::setCustomerNumber(int newCustomerNumber)
{
    customerNumber = newCustomerNumber;
}

void Data::setServiceTime(int newServiceTime)
{
    serviceTime = newServiceTime;
}

void Data::setTotalTime(int newTotalTime)
{
    totalTime = newTotalTime;
}