#ifndef NUMBERFUTUREEXCEPTION_H
#define NUMBERFUTUREEXCEPTION_H

#include<stdexcept>
#include<future>
#include<cstring>
class NumberFutureException :public std::future_error
{
private:
    char * _msg;
public:
    
    NumberFutureException() =delete;
    NumberFutureException (const NumberFutureException &) =delete;                  //(delete -> disabled copy constructor )
    NumberFutureException(NumberFutureException &&)=default;                         //brand new
    NumberFutureException &operator=(const NumberFutureException&)=delete;          //deleted copy assignment
    NumberFutureException && operator=(NumberFutureException&&)=delete;  
    NumberFutureException(std::future_errc ec, const char * msg) : std::future_error(ec) {
        // strlen(msg)
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }
    ~NumberFutureException() {
        delete [] _msg;
    }


    virtual const char * what() const noexcept{
        return _msg;
    }
};

#endif // NUMBERFUTUREEXCEPTION_H
