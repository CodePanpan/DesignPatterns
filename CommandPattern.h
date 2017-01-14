#ifndef COMMANDPATTERN_H_INCLUDED
#define COMMANDPATTERN_H_INCLUDED

#include <iostream>
#include <vector>

//Command class
class Command {
protected:
public:
    virtual void Execute() = 0;
};
//Receiver class
class Receiver {
protected:
public:
    void Buy() {std::cout<<"Buy stocks\n";}
    void Sell() {std::cout<<"Sell stocks\n";}
};
//Concrete class 1
class Buy : public Command {
protected:
    Receiver *receiver;
public:
    Buy(Receiver *receiver) {
        this->receiver = receiver;
    }
    void Execute() {
        receiver->Buy();
    }
};
//Concrete class 2
class Sell : public Command {
protected:
    Receiver *receiver;
public:
    Sell(Receiver *receiver) {
        this->receiver = receiver;
    }
    void Execute() {
        receiver->Sell();
    }
};
//Invoker class
class Invoker {
protected:
    std::vector<Command*> command_list;
public:
    void Order(Command *cmd) {
        command_list.push_back(cmd);
        cmd->Execute();
    }
};

#endif // COMMANDPATTERN_H_INCLUDED
