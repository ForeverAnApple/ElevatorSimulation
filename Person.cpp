#include "Person.h"


Person::Person(int source, int destination,
               int id, int const WEIGHT, int dir) 
    : source_(source), destination_(destination), id_(id),
      WEIGHT_(WEIGHT), dir_(dir)
{
    
}

Person::~Person()
{

}

Person & Person::operator=(Person const & p)
{
    std::cout << "Operator= overloading.\n";
    id() = p.id();
}

std::ostream & operator<<(std::ostream & cout,
                          Person const & p)
{
    cout << "\t<Person Source: " << p.source()
         << "\n\tDestination: " << p.destination()
         << "\n\tID: " << p.id()
         << "\n\tWEIGHT: " << p.WEIGHT() << ">\n";
    return cout;
}
