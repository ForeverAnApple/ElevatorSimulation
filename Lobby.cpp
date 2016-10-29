#include "Lobby.h"

Lobby::Lobby(const int MAX_WEIGHT, const int FLOOR)
    : MAX_WEIGHT_(MAX_WEIGHT), FLOOR_(FLOOR) {

}

Lobby::~Lobby() {

}

std::ostream & operator<<(std::ostream & cout,
                          const Lobby& l) {
    cout << "\n{-----Lobby-------}"
         << "\nFloor: " << l.FLOOR()
         << "\nMax weight: " << l.MAX_WEIGHT() << std::endl;

    cout << "\n\nPeople In Elevator:\n";

    for(int i = 0; i < l.people().size(); ++i)
    {
        cout << l.people().at(i) << "\n";
    }
    cout << "]\n";
    
    return cout;

}
