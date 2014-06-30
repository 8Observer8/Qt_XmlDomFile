#ifndef FILEREADERROR_H
#define FILEREADERROR_H

#include <string>
#include "FileError.h"

class FileReadError : public FileError {
public:

    FileReadError( const std::string &fileName,
                   const std::string &functionName ) :
        FileError( fileName, functionName )
    {
        m_message = "Error: unable to read data from the "
                "file \"" + m_fileName + "\" in the "
                "function \"" + m_functionName + "\"";
    }
};

#endif // FILEREADERROR_H
