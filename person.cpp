#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Person
{
protected:
	string fristName, lastName;
	unsigned int age;
public:
	Person();
	Person(const Person&);
	Person(const string& , const string&, unsigned int);
	void setAge(unsigned int);
	Person& operator=(const Person&);
	virtual ostream& printPerson(ostream&) const
	{
		return os << fristName << " " << lastName << " is " << age << " years old" << endl;
	}
};

ostream& operator<<(ostream& os, const Person& p)
{
	p.printPerson(os);
	return os;
}

Person::Person() {}
Person::Person(const Person& p)
{
	fristName = p.fristName;
	lastName = p.lastName;
	age = p.age;
}
Person::Person(const string& fristName, const string& lastName, unsigned int age)
{
	this->fristName = fristName;
	this->lastName = lastName;
	this->age = age;
}
void Person::setAge(unsigned int age)
{
	this->age = age;
}
Person& Person::operator=(const Person& p)
{
	fristName = p.fristName;
	lastName = p.lastName;
	age = p.age;
	return *this;
}

class Employee: public Person
{
protected:
	string company;
public:
	Employee();
	Employee(const Employee&);
	Employee(const string&, const string&, unsigned int, const string&);
	friend ostream& operator<<(ostream& os, const Employee& e);
	ostream& printPerson(ostream& os) const { return os << firstName << " " << lastName << " is " << age << " years old and works in " << company << endl; }
		
};

Employee::Employee() {}
Employee::Employee(const Employee& e)
{
	fristName = e.fristName;
	lastName = e.lastName;
	age = e.age;
	company = e.company;
}
Employee::Employee(const string& fristName, const string& lastName, unsigned int age, const string& company)
{
	this->fristName = fristName;
	this->lastName = lastName;
	this->age = age;
	this->company = company;
}
ostream& Employee::printPerson(ostream& os) const override
{

}

int main(void)
{
	Person p1{ "Marko", "Maric", 25 };
    Person p2{ "Ljubo", "Ljubic", 26 };
    Person p3{ "Ivan", "Ivic", 27 };


    Person p4 = p1;

    
    p4.setAge(24);
    cout << p4 << endl;

    Employee e1{ "Zdravko", "Zdravković", 30, "HP" };

    Person* arr[] = { &p1, &p2, &p3, &e1 };
    for(Person* p: arr)
        cout << *p << endl;

	return EXIT_SUCCESS;
}





























