/*
 * Authors: 
 * 	 Adam Sawyer
 * 	 Dave Chen
 *
 * @TODO:
 *   1.) Add a queue to the controller.
 *   2.) Simple graphics. *AFTER CORE FUNCTION*
 *   3.) A function that kicks all the people off the elevator if they need to get off.
 *   4.) A function that adds people onto the elevator on that floor. *DONE*
 *   5.) Function decomp EVERYTHING. *DONE*
 *   6.) Elevator Controller. *SEMI-DONE*
 *   7.) Elevator states.
 *
 * @IMPORTANT TODO:
 *   1.) Adding a up and down task list in controller for Elevator controls. This is controlling which floors have people that needs to be moved.
 *   2.) A holding area of people, this area will change people's destinations and send them to the lobby.
 *   3.) A list of booleans that remembers the floors people inside the elevator wants to go for each elevator.
 *   4.) Change the add functions to take in a controller pointer and pass in info into controller.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Person.h"
#include "Elevator.h"
#include "Lobby.h"
#include "Controller.h"

int const MAX_FLOOR = 10, MIN_FLOOR = 1,
  MAX_WEIGHT = 7, MAX_PPL = 100;


std::vector< Lobby *> lobbies;
std::vector< Elevator *> elevators;
std::vector< Person *> people;

// The main elevator and lobby controller
Controller controller(3);

/*
 *This vector contains pointers to people who need
 *to go to a different floor in the order that they
 *call for an elevator.
 */ 
std::vector< Person *> queue; 

int main()
{
  for(int i = 0; i < 2; i++)
    elevators.push_back(new Elevator( MAX_WEIGHT, i));
  
  for(int i = 0; i < 3; i++)
    lobbies.push_back(new Lobby(MAX_PPL, i));
  
  std::srand(std::time(0));
  int floor;
  for(int i = 0; i < 5; i++)
  {
    floor = std::rand() % 3;
    people.push_back(new Person(floor, std::rand() % 3, 0, 1));
    lobbies[floor]->add(people[i]); // TODO: Sending information to the controller about up and down button
  }
  controller.addElevator(&elevators);
  controller.addLobby(&lobbies);
  std::string command;

  // Checks the initialized state
  for(int i = 0; i < lobbies.size(); ++i)
    std::cout << *(lobbies.at(i)) << std::endl;
  for(int i = 0; i < elevators.size(); ++i)
    std::cout << *(elevators.at(i)) << std::endl;
  std::cout << "^^^^^^^^^^^^^^^^^^^^Initialized state^^^^^^^^^^^^^^^^^^^^^^^\n";

  while(command != "q")
    {
  
      //std::cout << "In the while loop\n";
      controller.tick();
      for(int i = 0; i < lobbies.size(); ++i)
        std::cout << *(lobbies.at(i)) << std::endl;
      for(int i = 0; i < elevators.size(); ++i)
        std::cout << *(elevators.at(i)) << std::endl;

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
