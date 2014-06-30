#ifndef FILEWRITEERROR_H
#define FILEWRITEERROR_H

#include <string>
#include "FileError.h"

class FileWriteError : public FileError {
public:

    FileWriteError( const std::string &fileName,
                    const std::string &functionName ) :
        FileError( fileName, functionName )
    {
        m_message = "Error: unable to write data to the "
                "file \"" + m_fileName + "\" in the "
                "function \"" + m_functionName + "\"";
    }
};

#endif // FILEWRITEERROR_H
