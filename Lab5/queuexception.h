#ifndef LAB5_QUEUEXCEPTION_H
#define LAB5_QUEUEXCEPTION_H

#include <exception>
#include <string>

using std::exception;
using std::string;

class QueueException : public exception {
private:
    string message;
public:
    //constructor with given message
    QueueException(const string &msg) {
        message = msg;
    }

    //func to return the message
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif //LAB5_QUEUEXCEPTION_H
