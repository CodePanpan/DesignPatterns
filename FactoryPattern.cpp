#include "FactoryPattern.h"

Shape *Shape::CreateFactoryObject(std::string type) {
    if (type == "circle")
        return new Circle();
    else if (type == "square")
        return new Square();
    else
        return NULL;
}
Shape *AbstractFactoryObjectCreator::CreateFactoryObject(std::string type) {
    if (type == "circle")
        return new Circle();
    else if (type == "square")
        return new Square();
    else
        return NULL;
}
