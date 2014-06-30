#ifndef FREEFUNCTIONS_H
#define FREEFUNCTIONS_H

#include <string>
#include <vector>

#include <QString>
#include <QDomDocument>

#include "Person.h"
#include "FileOpenError.h"
#include "FileReadError.h"
#include "FileWriteError.h"
#include "EmptyArgument.h"

void parsePersonsToXml( const std::vector<Person> &persons,
                        QDomDocument &doc)
throw ( EmptyArgument );

void writeData( const QString &fileName,
                const QDomDocument &doc )
throw ( EmptyArgument, FileOpenError, FileWriteError );

void readData( const QString &fileName,
               QDomDocument &doc )
throw ( EmptyArgument, FileOpenError, FileReadError );

void parseXmlToPersons( const QDomDocument &doc,
                        std::vector<Person> &persons )
throw ( EmptyArgument );

void printData( const std::vector<Person> &persons )
throw ( EmptyArgument );

#endif // FREEFUNCTIONS_H
