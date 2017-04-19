/*
 *TODO LIST
 *
 * 1.) A direction function to tell which direction the person wants to go.
 *
 */

#include "Person.h"


Person::Person(int source, int destination,
               int id, int const WEIGHT) 
    : source_(source), destination_(destination), id_(id),
      WEIGHT_(WEIGHT)
{
    
}

Person::~Person()
{
    if(source_ == destination_)
        std::cout << "I'm at my destination" << std::endl;
    else
        std::cout << "Not at my destination" << std::endl;
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
         << "\n\tWEIGHT: " << p.WEIGHT()
         << "\n\tDirection: " << p.dir() << ">\n";
    return cout;
}

//returns 1, 0, -1 for the direction the person wants to move to
//0 means the person is at their destination
int const Person::dir() const
{
    //Duel ternary
    return source_ < destination_ ? 1 : (source_ == destination_ ? 0 : -1);
}
