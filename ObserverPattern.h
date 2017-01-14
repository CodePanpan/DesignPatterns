#ifndef OBSERVERPATTERN_H_INCLUDED
#define OBSERVERPATTERN_H_INCLUDED

#include <iostream>
#include <set>

class Observer {
protected:
public:
    virtual void Notify(int &receive) = 0;
};
class Observable {
protected:
    static Observable *iInstance;
    std::set<Observer*> observers;
    Observable(){}
public:
    static Observable *GetInstance();
    void AddObserver(Observer &observer);
    void RemoveObserver(Observer &observer);
    void NotifyObservers();
    void TriggerObservable();
};
class TestObserver : public Observer {
protected:
    Observable *observable;
public:
    TestObserver();
    ~TestObserver();
    void Notify(int &receive);
};

#endif // OBSERVERPATTERN_H_INCLUDED
