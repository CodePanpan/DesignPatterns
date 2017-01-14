#include "ObserverPattern.h"

Observable *Observable::iInstance = NULL;

Observable *Observable::GetInstance() {
    if (iInstance == NULL) {
        iInstance = new Observable();
    }
    return iInstance;
}
void Observable::AddObserver(Observer &observer) {
    observers.insert(&observer);
}
void Observable::RemoveObserver(Observer &observer) {
    observers.erase(&observer);
}
void Observable::NotifyObservers() {
    int var = 10;
    std::set<Observer*>::iterator itr;
    for (itr = observers.begin(); itr != observers.end(); itr++)
        (*itr)->Notify(var);
}
void Observable::TriggerObservable() {
    NotifyObservers();
}
TestObserver::TestObserver() {
    observable = Observable::GetInstance();
    observable->AddObserver(*this);
}
TestObserver::~TestObserver() {
    observable->RemoveObserver(*this);
}
void TestObserver::Notify(int &receive) {
    std::cout<<"Observation receiving "<<receive<<"\n";
}
