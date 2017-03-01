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

    cout << "\n\nPeople In Lobby:\n";

    for(int i = 0; i < l.people().size(); ++i)
    {
        cout << *(l.people().at(i)) << "\n";
    }
    cout << "]\n";
    
    return cout;

}

Person * const Lobby::remove(int index)
{
    Person *temp = person_.at(index);
    person_.erase(person_.begin() + index);
    return temp;
}

Person * const Lobby::remove(Person * person)
{
    for(int i = 0; i < person_.size(); ++i)
    {
        if(person_.at(i)->id() == person->id())
        {
            Person *temp = person_.at(i);
            person_.erase(person_.begin() + i);
            return temp;
        }
    }
}

int const Lobby::add(Person * person)
{
    person_.push_back(person);
    return person_.size() - 1;
}

//returns the indexes of all people on the floor that want
//to get on the given elevator and can get on the elevator
int const Lobby::find(int weightLeft, int eDestination)
{
    for(int i = 0; i < person_.size(); ++i )
    {
        if(person_.at(i)->WEIGHT() < weightLeft
           && (person_.at(i)->destination() > FLOOR_))
          {
            /*&&
               eDestination > FLOOR_) ||
           (person_.at(i)->destination() < FLOOR_ &&
           eDestination < FLOOR_ ) */
            return i;
          }
    }
    return -1;

}
