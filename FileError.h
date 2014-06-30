#ifndef FILEERROR_H
#define FILEERROR_H

#include <string>
#include <stdexcept>

class FileError : public std::runtime_error {
public:

    FileError( const std::string &fileName,
               const std::string &functionName ) :
        std::runtime_error( ""),
        m_message( "" ),
        m_fileName( fileName ),
        m_functionName( functionName )
    {

    }

    virtual ~FileError( ) throw( )
    {

    }

    virtual const char *what( ) const throw( )
    {
        return m_message.c_str( );
    }

    std::string message( )
    {
        return m_message;
    }

protected:
    std::string m_message;
    std::string m_fileName;
    std::string m_functionName;
};

#endif // FILEERROR_H
