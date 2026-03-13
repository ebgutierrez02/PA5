#pragma once

class Data
{
public: // Member functions

	~Data();
	Data();
	Data(int customerNum, int serviceTime, int totalTime);

	int getCustomerNumber() const;
	int getServiceTime() const;
	int getTotalTime() const;

	void setCustomerNumber(int newCustomerNumber);
	void setServiceTime(int newServiceTime);
	void setTotalTime(int newTotalTime);


private:
	int customerNumber;
	int serviceTime; 
	// minutes
	int totalTime; // totalTime = serviceTime + sum of serviceTimes of customers in line 
	
};
