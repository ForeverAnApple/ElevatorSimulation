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
