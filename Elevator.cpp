#include "Elevator.h"

Elevator::Elevator(int const MAX_WEIGHT, int id)
    : at_(0), MAX_WEIGHT_(MAX_WEIGHT),
      destination_(0), id_(id) {
    
    
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
