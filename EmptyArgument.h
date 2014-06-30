#ifndef EMPTYARGUMENT_H
#define EMPTYARGUMENT_H

#include <string>
#include "LogicError.h"

class EmptyArgument : public LogicError {
public:

    EmptyArgument( const std::string &functionName ) :
        LogicError( functionName )
    {
        m_message = "Error: empty argument in the "
                "function \"" + m_functionName + "\"";
    }
};

#endif // EMPTYARGUMENT_H
