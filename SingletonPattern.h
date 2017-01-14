#ifndef SINGLETONPATTERN_H_INCLUDED
#define SINGLETONPATTERN_H_INCLUDED

class SingletonObject {
protected:
    SingletonObject();
    int var;
public:
    static SingletonObject *iInstance;
    static SingletonObject *GetObject();
    void SetVar() {var = 1;}
    int GetVar() const {return var;}
};


#endif // SINGLETONPATTERN_H_INCLUDED
