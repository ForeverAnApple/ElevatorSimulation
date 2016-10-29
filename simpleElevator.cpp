/*
 * Authors: 
 * 	 Adam Sawyer
 * 	 Dave Chen
 */

#include <iostream>
#include <sstream>
#include "Person.h"
#include "Elevator.h"
#include "Lobby.h"

const int MAX_FLOOR = 10, MIN_FLOOR = 1, MAX_WEIGHT = 7, MAX_PPL = 10;

int main()
{
    Person* person[MAX_PPL];
    for(int i = 0; i < MAX_PPL; ++i){
        person[i] = new Person(0, 1, i, 1);
        std::cout << *(person[i]);
    }
	
    Elevator* elevator[2];
    for(int i = 0; i < 2; ++i){
        elevator[i] = new Elevator(MAX_PPL, MAX_WEIGHT, i);
        elevator[i]->people().push_back(*person[i]);
        std::cout << *(elevator[i]);
    }
    
    Lobby* lobby[MAX_FLOOR];
    for(int i = 0; i < MAX_FLOOR; ++i){
        //std::cout << "Making lobby index: " << i << std::endl;
        lobby[i] = new Lobby(MAX_PPL, i);
        lobby[i]->people().push_back(*person[i]);
        std::cout << *(lobby[i]);
    }
    

    return 0;
}
