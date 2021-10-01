
#include <iostream>
#include <stdlib.h>
using namespace std;

//Class Declaration
class Employee
{
private:

	int idNumber;
	double payRate;
	double maxHours;

public:
	Employee();
	Employee(int idNum);
	Employee(int idNum, double rate, double hours);
	void getInfo();
	int getID();
	void setInfo(int idNum, double rate, double maxHours);

};
//Implementation
Employee::Employee() : idNumber(0), payRate(20), maxHours(40) {};
Employee::Employee(int idNum, double rate, double hours) : idNumber(idNum), payRate(rate), maxHours(hours) {};

void Employee::getInfo()
{
	std::cout << "ID Number: "
		<< idNumber << "\n"
		<< "Rate: "
		<< payRate << "\n"
		<< "Hours: "
		<< maxHours << "\n"
		<< std::endl;
}
int Employee::getID()
{
	return idNumber;
}
void Employee::setInfo(int idNum, double rate, double hours)
{
	idNumber = idNum;
	payRate = rate;
	maxHours = hours;
}
int main()
{
	int idNum;
	double rate;
	double hours;
	int ans (0);
	int menuSelection;
	typedef Employee* empPtr;
	empPtr newEmp = new Employee;

	do
	{
		cout << "\nPlease Make a Selection: \n"
			<< "1. Add an Employee \n"
			<< "2. Modify an Employee \n"
			<< "3. Delete an Employee \n"
			<< "4. Print Employee Information \n"
			<< "5. Exit the Menu" << endl;
		cin >> menuSelection;

		switch (menuSelection)
		{
		case 1:

			std::cout << "Enter Employee ID, Pay Rate, and Max Hours Per Week: ";
			std::cin >> idNum >> rate >> hours;
			newEmp = new Employee(idNum, rate, hours);
			newEmp->getInfo();
			break;

		case 2:
			std::cout << "Enter Employee ID, Pay Rate, and Max Hours Per Week: ";
			std::cin >> idNum >> rate >> hours;
			std::cout << "You modified employee: " << newEmp->getID() << "\n";
			newEmp->setInfo(idNum, rate, hours);
			newEmp->getInfo();
			break;

		case 3:
			std::cout << "You have deleted employee " << newEmp->getID();
			cout << "\n";
			delete newEmp;
			newEmp = { nullptr };
			newEmp = new Employee;
			break;

		case 4:
			if (newEmp->getID() == 0)
			{
				cout << "Please create a new Employee! " << endl;
				break;
			}

			else
			newEmp->getInfo();
			break;

		case 5:
			cout << "Goodbye :)" << endl;
			exit(0);

		default:
			std::cout << "Please make a valid selection." << endl;
		}
	} while (ans == 0);
	
	return 0;
}