#include "Elevator.h"

Elevator::Elevator(const int MAX_PPL, const int MAX_WEIGHT, int id)
    : MAX_PPL_(MAX_PPL), at_(0), MAX_WEIGHT_(MAX_WEIGHT),
      destination_(0), id_(id) {
    
    
}

Elevator::~Elevator() {

}

std::ostream & operator<<(std::ostream & cout,
                          const Elevator& e) {
    cout << "\n[------ELEVATOR------\nAt: " << e.at()
         << "\nDestination: " << e.destination()
         << "\nID: " << e.id()
         << "\nMax PPL: " << e.MAX_PPL()
         << "\nMAX WEIGHT: " << e.MAX_WEIGHT();

    cout << "\n\nPeople In Elevator:\n";

    for(int i = 0; i < e.people().size(); ++i)
    {
        cout << e.people().at(i) << "\n";
    }
    cout << "------END ELEVATOR------]\n";
    
    return cout;

}
