/*
 * Authors: Daiwei Chen
 *          Adam Sawyer
 *
 * TODO:
 *   1.) Queue of the destinations.
 *   2.) A find function to see who wants to get off on the floor.
 *   3.) 
 */


#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include <string>
#include "Person.h"

class Elevator {
public:
    Elevator(int const MAX_WEIGHT = 15,
             int id = 1);
    ~Elevator();
    int const at() const { return at_; }
    int & at() {return at_;}
    int const destination() const { return destination_; }
    int & destination() { return destination_; }
    int const id() const{ return id_; }
    int & id(){return id_;}
    int const MAX_WEIGHT() const{ return MAX_WEIGHT_; }
    std::vector<Person *> const & people() const{ return person_; }
    std::vector<Person *> & people(){ return person_; }
    void remove(int);
    void remove(Person *);
    void add(Person *);

private:
    int at_, destination_, id_;
    int const MAX_WEIGHT_;
    std::vector<Person *> person_;
		
protected:
};

std::ostream & operator<<(std::ostream & cout,
                          Elevator const & e);

#endif
