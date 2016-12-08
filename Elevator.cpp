#include "Elevator.h"

Elevator::Elevator(int const MAX_WEIGHT, int id)
    : at_(0), MAX_WEIGHT_(MAX_WEIGHT),
      destination_(0), id_(id), dir_(0)
{
    
}

Elevator::~Elevator() {

}

std::ostream & operator<<(std::ostream & cout,
                          Elevator const & e) {
    cout << "\n[------ELEVATOR------\nAt: " << e.at()
         << "\nDestination: " << e.destination()
         << "\nID: " << e.id()
         << "\nMAX WEIGHT: " << e.MAX_WEIGHT();

    cout << "\n\nPeople In Elevator:\n";

    for(int i = 0; i < e.people().size(); ++i)
    {
        cout << *(e.people().at(i)) << "\n";
    }
    cout << "------END ELEVATOR------]\n";
    
    return cout;
}

void Elevator::remove(int index)
{
    person_.erase(person_.begin() + index);
}

void Elevator::remove(Person * person)
{
    for(int i = 0; i < person_.size(); ++i)
    {
        if(person_.at(i)->id() == person->id())
        {
            person_.erase(person_.begin() + i);
            break;
        }
    }
}

void Elevator::add(Person * person)
{
    person_.push_back(person);
}

void move(int x)
{
    at() += x;
    for(int i = 0; i < people().size(); ++i)
        people().at(i)->source() += x;
}

int Elevator::find()
{
    
    return -1;
}
