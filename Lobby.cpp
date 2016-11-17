#include "Lobby.h"

Lobby::Lobby(int const MAX_PPL, int const FLOOR)
    : MAX_PPL_(MAX_PPL), FLOOR_(FLOOR) {

}

Lobby::~Lobby() {

}

std::ostream & operator<<(std::ostream & cout,
                          Lobby const & l) {
    cout << "\n{-----Lobby-------}"
         << "\nFloor: " << l.FLOOR()
         << "\nMax people: " << l.MAX_PPL() << std::endl;

    cout << "\n\nPeople In Elevator:\n";

    for(int i = 0; i < l.people().size(); ++i)
    {
        cout << *(l.people().at(i)) << "\n";
    }
    cout << "]\n";
    
    return cout;

}

void Lobby::removePerson(int index)
{
    person_.erase(person_.begin() + index);
}

void Lobby::removePerson(Person * person)
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

void Lobby::addPerson(Person * person)
{
    person_.push_back(person);
}
