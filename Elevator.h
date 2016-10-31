#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include <string>
#include "Person.h"

class Elevator {
public:
    Elevator(int const, int const, int);
    ~Elevator();
    int const at() const { return at_; }
    int & at() {return at_;}
    int const destination() const { return destination_; }
    int & destination() { return destination_; }
    int const id() const{ return id_; }
    int & id(){return id_;}
    int const MAX_PPL() const{ return MAX_PPL_; }
    int const MAX_WEIGHT() const{ return MAX_WEIGHT_; }
    std::vector<Person> const people() const{ return person_; }
    std::vector<Person> & people(){ return person_; }

private:
    int at_, destination_, id_;
    int const MAX_WEIGHT_;
    int const MAX_PPL_;
    std::vector<Person *> person_;
		
protected:
};

std::ostream & operator<<(std::ostream & cout,
                          Elevator const & e);

#endif
