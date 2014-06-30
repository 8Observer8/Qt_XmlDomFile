#ifndef FILEOPENERROR_H
#define FILEOPENERROR_H

#include "FileError.h"

class FileOpenError : public FileError {
public:

    FileOpenError( const std::string fileName,
                   const std::string functionName ) :
        FileError( fileName, functionName )
    {
        m_message = "Error: unable to open the "
                "file \"" + m_fileName + "\" in the "
                "function \"" + m_functionName + "\"";
    }
};

#endif // FILEOPENERROR_H
