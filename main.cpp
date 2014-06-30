
#include <vector>
#include <iostream>

#include <QString>

#include "freeFunctions.h"
#include "Person.h"
#include "LogicError.h"
#include "FileError.h"

int main( )
{
    // Person array for saving
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    std::vector<Person> personsOut;
    personsOut.push_back( david );
    personsOut.push_back( ivan );

    // Parse the person array to the XML-document
    QDomDocument docOut;
    try {
        parsePersonsToXml( personsOut, docOut );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Write the XML-document to the file
    QString fileName = "Persons.xml";
    try {
        writeData( fileName, docOut );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( const FileError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Read the XML-document from the file
    QDomDocument docIn;
    try {
        readData( fileName, docIn );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( const FileError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Parse the XML-document to the person array
    std::vector<Person> personsIn;
    try {
        parseXmlToPersons( docIn, personsIn );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Print the person array on the screen
    try {
        printData( personsIn );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    return 0;
}
