/*
 * Authors: 
 * 	 Adam Sawyer
 * 	 Dave Chen
 *
 * @TODO:
 *   1.) Add a queue to the controller.
 *   2.) Simple graphics. *AFTER CORE FUNCTION*
 *   3.) A function that kicks all the people off the elevator if they need to get off.
 *   4.) A function that adds people onto the elevator on that floor.
 *   5.) Function decomp EVERYTHING.
 *   6.) Elevator Controller.
 *   7.) Elevator states.
 */

#include <iostream>
#include <string>
#include <sstream>
#include "Person.h"
#include "Elevator.h"
#include "Lobby.h"

int const MAX_FLOOR = 10, MIN_FLOOR = 1,
    MAX_WEIGHT = 7, MAX_PPL = 100;


std::vector< Lobby *> lobbies;
std::vector< Elevator *> elevators;
std::vector< Person *> people;

void ticker();
void lobby_tick();
void elevator_tick();

int main()
{
    
    /*for(int i = 0; i < MAX_PPL; ++i){
        people.push_back(new Person(0, 1, i, 1));
        std::cout << *(people.at(i));
    }*/
	
    /*for(int i = 0; i < 2; ++i){
        elevators.push_back(new Elevator( MAX_WEIGHT, i));
        //elevators.at(i)->people().push_back(people.at(i));
        std::cout << *(elevators.at(i));
    }*/
  
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
  
        //std::cout << "In the while loop\n";
        lobby_tick();
        elevator_tick();
        std::cout << "---------------------------End of one tick--------------------------\n";
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

void lobby_tick()
{
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
                elevators.at(0)->add(lobbies.at(i)->people().at(n));
                elevators.at(0)->destination() =
                    lobbies.at(i)->people().at(n)->destination();
                lobbies.at(i)->remove(n); 
            }   
        }
    }
}

void elevator_tick()
{
    for(int i = 0; i < elevators.size(); ++i)
    {
        // TODO: Get people off the elevators
        // if(elevators.at(i)->people()
        if(elevators.at(i)->at() != elevators.at(i)->destination())
        {
            elevators.at(i)->dir() = (elevators.at(i)->at() < elevators.at(i)->destination())
                ? 1 : -1;
            elevators.at(i)->at() += elevators.at(i)->dir();
        }
        
        for(int n = 0; n < elevators.at(i)->people().size(); ++n)
        {
            elevators.at(i)->people().at(n)->source() = elevators.at(i)->at();
        }
    }
}
