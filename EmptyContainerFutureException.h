#ifndef EMPTYCONTAINERFUTUREEXCEPTION_H
#define EMPTYCONTAINERFUTUREEXCEPTION_H

#include<stdexcept>
#include<future>
#include<cstring>
class EmptyContainerFutureException :public std::future_error
{
private:
    char * _msg;
public:
    
    EmptyContainerFutureException() =delete;
    EmptyContainerFutureException (const EmptyContainerFutureException &) =delete;                  //(delete -> disabled copy constructor )
    EmptyContainerFutureException(EmptyContainerFutureException &&)=default;                         //brand new
    EmptyContainerFutureException &operator=(const EmptyContainerFutureException&)=delete;          //deleted copy assignment
    EmptyContainerFutureException && operator=(EmptyContainerFutureException&&)=delete;  
    EmptyContainerFutureException(std::future_errc ec, const char * msg) : std::future_error(ec) {
        // strlen(msg)
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }
    ~EmptyContainerFutureException() {
        delete [] _msg;
    }


    virtual const char * what() const noexcept{
        return _msg;
    }
};

#endif // EMPTYCONTAINERFUTUREEXCEPTION_H
