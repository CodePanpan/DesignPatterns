#ifndef CHAINOFRESPONSIBILITYPATTERN_H_INCLUDED
#define CHAINOFRESPONSIBILITYPATTERN_H_INCLUDED

#include <iostream>

enum ErrorStates {
    ANALYZE = 0,
    FIX,
    VERIFY,
    CLOSE
};

class ErrorReport {
protected:
    ErrorStates state;
public:
    ErrorReport(ErrorStates state) {
        this->state = state;
    }
    void SetState(ErrorStates state) {
        this->state = state;
    }
    ErrorStates GetState() {
        return state;
    }
};
class Error {
protected:
    ErrorStates state;
    Error *successor;
public:
    Error(ErrorStates state) {
        this->state = state;
        successor = NULL;
    }
    void SetSuccessor(Error *successor) {
        this->successor = successor;
    }
    virtual void ProcessError(ErrorReport &report) = 0;
};
class AnalyzeError : public Error {
protected:
public:
    AnalyzeError():Error(ANALYZE) {}
    void ProcessError(ErrorReport &report) {
        if (report.GetState() == ANALYZE)
            std::cout<<"Handled the error in analyze\n";
        else {
            std::cout<<"Analyze:Passing on to the successor\n";
            successor->ProcessError(report);
        }
    }
};
class FixError : public Error {
protected:
public:
    FixError():Error(FIX) {}
    void ProcessError(ErrorReport &report) {
        if (report.GetState() == FIX)
            std::cout<<"Handled the error in fix\n";
        else {
            std::cout<<"Fix:Passing on to the successor\n";
            successor->ProcessError(report);
        }
    }
};
class VerifyError : public Error {
protected:
public:
    VerifyError():Error(VERIFY) {}
    void ProcessError(ErrorReport &report) {
        if (report.GetState() == VERIFY)
            std::cout<<"Handled the error in verify\n";
        else {
            std::cout<<"Verify:Passing on to the successor\n";
            successor->ProcessError(report);
        }
    }
};
class CloseError : public Error {
protected:
public:
    CloseError():Error(CLOSE) {}
    void ProcessError(ErrorReport &report) {
        if (report.GetState() == CLOSE)
            std::cout<<"Handled the error in close\n";
        else {
            std::cout<<"Close:Ignoring this error. Ending process chain\n";
        }
    }
};

#endif // CHAINOFRESPONSIBILITYPATTERN_H_INCLUDED
