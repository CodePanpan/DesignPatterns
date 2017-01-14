#include "SingletonPattern.h"
#include <iostream>

SingletonObject::SingletonObject() {
    var = 0;
    //Nothing to be done here
}
SingletonObject *SingletonObject::iInstance = NULL;
SingletonObject *SingletonObject::GetObject() {
    if (iInstance == NULL) {
        iInstance = new SingletonObject();
    }
    return iInstance;
}
