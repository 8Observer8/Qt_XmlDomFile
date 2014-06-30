#ifndef LOGICERROR_H
#define LOGICERROR_H

#include <stdexcept>
#include <string>

class LogicError : public std::logic_error {
public:

    LogicError( const std::string &functionName ) :
        m_functionName( functionName ),
        m_message( "" ),
        std::logic_error( "" )
    {

    }

    virtual ~LogicError( ) throw( ) {

    }

    virtual const char *what( ) const throw( ) {
        return m_message.c_str( );
    }

    std::string message( ) const {
        return m_message;
    }

protected:
    std::string m_message;
    std::string m_functionName;
};

#endif // LOGICERROR_H
