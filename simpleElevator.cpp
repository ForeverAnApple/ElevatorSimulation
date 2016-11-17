/*
 * Authors: 
 * 	 Adam Sawyer
 * 	 Dave Chen
 */

#include <iostream>
#include <string>
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
    /*for(int i = 0; i < MAX_PPL; ++i){
        people.push_back(new Person(0, 1, i, 1));
        std::cout << *(people.at(i));
    }*/
	
    std::vector< Elevator *> elevators;
    /*for(int i = 0; i < 2; ++i){
        elevators.push_back(new Elevator( MAX_WEIGHT, i));
        //elevators.at(i)->people().push_back(people.at(i));
        std::cout << *(elevators.at(i));
    }*/
  
    std::vector< Lobby *> lobbies;
    /*for(int i = 0; i < MAX_FLOOR; ++i){
        lobbies.push_back(new Lobby(MAX_PPL, i));
        //lobbies.at(i)->people().push_back(people.at(i));
        std::cout << *(lobbies.at(i));
    }*/

    people.push_back(new Person(0, 1, 0, 1));
    elevators.push_back(new Elevator( MAX_WEIGHT, 0));
    lobbies.push_back(new Lobby(MAX_PPL, 0));
    lobbies.push_back(new Lobby(MAX_PPL, 1));
    lobbies.at(0)->people().push_back(people.at(0));
    std::string command;
    while(command != "terminate")
    {
        for(int i = 0; i < lobbies.size(); ++i)
            std::cout << *(lobbies.at(i)) << std::endl;
        for(int i = 0; i < elevators.size(); ++i)
            std::cout << *(elevators.at(i)) << std::endl;
  
        std::cout << "In the while loop\n";
        for(int i = 0; i < lobbies.size(); ++i){
            for(int n = 0; n < lobbies.at(i)->people().size(); ++n)
            {
                if(lobbies.at(i)->people().at(n)->source() !=
                   lobbies.at(i)->people().at(n)->destination()) {
                    elevators.at(0)->destination() =
                        lobbies.at(i)->people().at(n)->source();
                }
                
                if(elevators.at(i)->at() ==
                   lobbies.at(i)->people().at(n)->source()) {
                    elevators.at(0)->addPerson(lobbies.at(i)->people().at(n));
                    elevators.at(0)->destination() =
                        lobbies.at(i)->people().at(n)->destination();
                    lobbies.at(i)->removePerson(n); 
                }   
            }
        }

        for(int i = 0; i < elevators.size(); ++i)
        {
            // TODO: Get people off the elevators
            //if(elevators.at(i)->people()
            if(elevators.at(i)->at() != elevators.at(i)->destination())
            {
                elevators.at(i)->at() += (elevators.at(i)->at() < elevators.at(i)->destination())
                    ? 1 : -1;
            }
            for(int n = 0; n < elevators.at(i)->people().size(); ++n)
            {
                elevators.at(i)->people().at(n)->source() = elevators.at(i)->at();
            }

        }
        std::cin >> command;
        //for(int i = 0; i < elevators.size(); ++i)
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
