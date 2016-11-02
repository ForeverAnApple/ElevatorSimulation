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

int const MAX_FLOOR = 10, MIN_FLOOR = 1,
    MAX_WEIGHT = 7, MAX_PPL = 100;

void ticker();

int main()
{
    
    std::vector< Person *> people;
    for(int i = 0; i < MAX_PPL; ++i){
        people.push_back(new Person(0, 1, i, 1));
        std::cout << *(people.at(i));
    }
	
    std::vector< Elevator *> elevators;
    for(int i = 0; i < 2; ++i){
        elevators.push_back(new Elevator( MAX_WEIGHT, i));
        elevators.at(i)->people().push_back(people.at(i));
        std::cout << *(elevators.at(i));
    }
  
    std::vector< Lobby *> lobbies;
    for(int i = 0; i < MAX_FLOOR; ++i){
        lobbies.push_back(new Lobby(MAX_PPL, i));
        lobbies.at(i)->people().push_back(people.at(i));
        std::cout << *(lobbies.at(i));
    }
    

    /*Person test1(0, 0, 1, 1);
    std::cout << test1 << std::endl;

    Person test2(0, 0, 2, 1);
    std::cout << test2 << std::endl;

    test2 = test1;
    std::cout << test2 << std::endl;*/
    
    return 0;
}

void ticker()
{
    
}
