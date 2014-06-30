
#include <iostream>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QTextStream>
#include "freeFunctions.h"

void parsePersonsToXml(const std::vector<Person> &persons,
                        QDomDocument &doc )
throw ( EmptyArgument )
{
    std::string functionName = "parsePersonsToXml()";

    // Check the input argument
    if ( persons.empty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Persons to Xml
    // Create "Persons" element
    QDomElement personsElement = doc.createElement( "Persons" );
    doc.appendChild( personsElement );

    // Create the "Person" elements in the "Persons" element
    for ( std::size_t i = 0; i < persons.size( ); ++i ) {
        Person person = persons[i];
        QString firstName = person.firstName( );
        QString lastName = person.lastName( );
        QDomElement onePersonElement = doc.createElement( "Person" );
        onePersonElement.setAttribute( "firstName", firstName );
        onePersonElement.setAttribute( "lastName", lastName );
        personsElement.appendChild( onePersonElement );
    }
}

void writeData( const QString &fileName,
                const QDomDocument &doc )
throw ( EmptyArgument, FileOpenError, FileWriteError )
{
    std::string functionName = "writeData()";

    // Check arguments
    if ( fileName.isEmpty( ) || doc.isNull( ) ) {
        throw EmptyArgument( functionName );
    }

    // Open the output file
    QFile file( fileName );
    if ( !file.open( QIODevice::WriteOnly ) ) {
        throw FileOpenError( fileName.toStdString( ), functionName );
    }

    QTextStream( &file ) << doc.toString( );
}

void readData( const QString &fileName,
               QDomDocument &doc )
throw ( EmptyArgument, FileOpenError, FileReadError )
{
    std::string functionName = "readData()";

    // Check argument
    if ( fileName.isEmpty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Open the input file
    QFile file( fileName );
    if ( !file.open( QIODevice::ReadOnly ) ) {
        throw FileOpenError( fileName.toStdString( ), functionName );
    }

    // Read data
    doc.setContent( &file );
}

void parseXmlToPersons( const QDomDocument &doc,
                        std::vector<Person> &persons )
throw ( EmptyArgument )
{
    std::string functionName = "parseXmlToPersons()";

    // Check the input argument
    if ( doc.isNull() ) {
        throw EmptyArgument( functionName );
    }

    // Parse to "Person" array
    // Get the "Persons" element
    QDomElement personsElement = doc.firstChildElement( "Persons" );
    // Get the first one "Person" element
    QDomElement onePersonElement = personsElement.firstChildElement( "Person" );
    while( !onePersonElement.isNull( ) ) {
        // Get the person
        QString firstName = onePersonElement.attribute( "firstName" );
        QString lastName = onePersonElement.attribute( "lastName" );
        Person person( firstName, lastName );

        // Add the person to the output array
        persons.push_back( person );

        // Next person
        onePersonElement = onePersonElement.nextSiblingElement( "Person" );
    }
}

void printData( const std::vector<Person> &persons )
throw ( EmptyArgument )
{
    std::string functionName = "printData()";

    // Check argument
    if ( persons.empty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Print data
    for ( std::size_t i = 0; i < persons.size( ); ++i ) {
        std::cout << "First Name: " << persons[i].firstName( ).toStdString( ) << std::endl;
        std::cout << "Last Name: " << persons[i].lastName( ).toStdString( ) << std::endl;
        std::cout << std::endl;
    }
}
