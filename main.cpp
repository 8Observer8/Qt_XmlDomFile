
#include <vector>
#include <iostream>
#include <QString>
#include "freeFunctions.h"
#include "Person.h"

int main( )
{
    // Person array for saving
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    std::vector<Person> persons;
    persons.push_back( david );
    persons.push_back( ivan );

    try {
        // Parse the person array to the XML-content
        QDomDocument content;
        parsePersonsToXml( persons, content );

        // Write the XML-content to the file
        QString fileName = "Persons.xml";
        writeData( fileName, content );

        // Read the XML-content from the file
        QDomDocument readContent;
        readData( fileName, readContent );

        // Parse the XML-content to the person array
        std::vector<Person> readPersons;
        parseXmlToPersons( readContent, readPersons );

        // Print the person array on the screen
        printData( readPersons );
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

    return 0;
}
