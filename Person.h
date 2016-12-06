#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person
{
public:
    Person(int source = 0, int destination = 0,
           int id = 0, int const WEIGHT = 1, int dir = 0);
    ~Person();
    int const source() const { return source_; }
    int & source() { return source_; }
    int const destination() const { return destination_; }
    int & destination() { return destination_; }
    int const id() const{ return id_; }
    int & id() { return id_; }
    int const dir() const{ return dir_; }
    int & dir() { return dir_; }
    int const WEIGHT() const{ return WEIGHT_; }

    Person & operator=(Person const &);
    
private:
    int source_, destination_, id_, dir_;
    int const WEIGHT_;
    
protected:
    
};

// std::cout << x 
// translates
// operator<<(std::cout, x)
//
// std::cout << x << y
// translates
// operator<<( operator<<(std::cout, x), y)
// std::cout << x << y
// translates
// operator<<( operator<<(std::cout, x), y)



std::ostream & operator<<(std::ostream &,
                          Person const &);



#endif
 
