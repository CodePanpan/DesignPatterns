#ifndef FACTORYPATTERN_H_INCLUDED
#define FACTORYPATTERN_H_INCLUDED

#include <iostream>
#include <cstring>

//A demo of Factory Design Pattern
class Shape {
protected:
public:
    virtual void Draw() = 0;
    static Shape *CreateFactoryObject(std::string type);
};
class Circle : public Shape {
protected:
public:
    void Draw() {std::cout<<"Circle\n";}
};
class Square : public Shape {
protected:
public:
    void Draw() {std::cout<<"Square\n";}
};
class AbstractFactoryObjectCreator {
protected:
public:
    Shape *CreateFactoryObject(std::string type);
};

#endif // FACTORYPATTERN_H_INCLUDED
