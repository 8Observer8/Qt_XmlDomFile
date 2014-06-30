
#include <vector>
#include <QDomDocument>
#include "gtest/gtest.h"
#include "freeFunctions.h"
#include "Person.h"

TEST( parseXmlToPersons_001, emptyArgumentTest )
{
    // Input data
    QDomDocument doc;

    // Actual data
    std::vector<Person> persons;
    ASSERT_THROW( {
                      parseXmlToPersons( doc, persons );
                  }, EmptyArgument );
}

TEST( parseXmlToPersons_002, firstNameOfFirstPerson )
{
    // Input data
    QDomDocument personsDoc;
    // Add the "Persons" element
    QDomElement personsElement = personsDoc.createElement( "Persons" );
    personsDoc.appendChild( personsElement );
    // Add the first "One Person" element
    QDomElement davidElement = personsDoc.createElement( "Person" );
    davidElement.setAttribute( "firstName", "David" );
    davidElement.setAttribute( "lastName", "White" );
    personsElement.appendChild( davidElement );
    // Add the second "One Person" element
    QDomElement ivanElement = personsDoc.createElement( "Person" );
    ivanElement.setAttribute( "firstName", "Ivan" );
    ivanElement.setAttribute( "lastName", "Green" );
    personsElement.appendChild( ivanElement );

    // Get the actual result
    std::vector<Person> actualPersons;
    ASSERT_NO_THROW( {
                         parseXmlToPersons( personsDoc, actualPersons );
                     } );

    // Check the actual size
    std::size_t exptectedSize = 2;
    std::size_t actualSize = actualPersons.size( );
    ASSERT_EQ( exptectedSize, actualSize );

    // Actual result
    QString actualFirstName = actualPersons[0].firstName( );
    // Expected result
    QString expectedFirstName = "David";
    // Check the actual result
    ASSERT_EQ( expectedFirstName.toStdString( ), actualFirstName.toStdString( ) );
}

TEST( parseXmlToPersons_003, lastNameOfFirstPerson )
{
    // Input data
    QDomDocument personsDoc;
    // Add the "Persons" element
    QDomElement personsElement = personsDoc.createElement( "Persons" );
    personsDoc.appendChild( personsElement );
    // Add the first one "Person" element
    QDomElement davidElement = personsDoc.createElement( "Person" );
    davidElement.setAttribute( "firstName", "David" );
    davidElement.setAttribute( "lastName", "White" );
    personsElement.appendChild( davidElement );
    // Add the second one "Person" element
    QDomElement ivanElement = personsDoc.createElement( "Person" );
    ivanElement.setAttribute( "firstName", "Ivan" );
    ivanElement.setAttribute( "lastName", "Green" );
    personsElement.appendChild( ivanElement );

    // Make the actual result
    std::vector<Person> persons;
    ASSERT_NO_THROW( {
                         parseXmlToPersons( personsDoc, persons );
                     } );

    // Check the actual size
    std::size_t expectedSize = 2;
    std::size_t actualSize = persons.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Actual result
    QString actualLastName = persons[0].lastName( );
    // Expected result
    QString expectedLastName = "White";
    // Check the actual result
    ASSERT_EQ( expectedLastName.toStdString( ), actualLastName.toStdString( ) );
}

TEST( parseXmlToPersons_004, firstNameOfSecondPerson )
{
    // Input data
    QDomDocument personsDoc;
    // Add the "Persons" element
    QDomElement personsElement = personsDoc.createElement( "Persons" );
    personsDoc.appendChild( personsElement );
    // Add the first one "Person" element
    QDomElement davidElement = personsDoc.createElement( "Person" );
    davidElement.setAttribute( "firstName", "David" );
    davidElement.setAttribute( "lastName", "White" );
    personsElement.appendChild( davidElement );
    // Add the second one "Person" element
    QDomElement ivanElement = personsDoc.createElement( "Person" );
    ivanElement.setAttribute( "firstName", "Ivan" );
    ivanElement.setAttribute( "lastName", "Green" );
    personsElement.appendChild( ivanElement );

    // Make the actual result
    std::vector<Person> persons;
    ASSERT_NO_THROW( {
                         parseXmlToPersons( personsDoc, persons );
                     } );

    // Check the actual size
    std::size_t expectedSize = 2;
    std::size_t actualSize = persons.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Actual result
    QString actualLastName = persons[1].firstName( );
    // Expected result
    QString expectedLastName = "Ivan";
    // Check the actual result
    ASSERT_EQ( expectedLastName.toStdString( ), actualLastName.toStdString( ) );
}

TEST( parseXmlToPersons_005, lastNameOfSecondPerson )
{
    // Input data
    QDomDocument personsDoc;
    // Add the "Persons" element
    QDomElement personsElement = personsDoc.createElement( "Persons" );
    personsDoc.appendChild( personsElement );
    // Add the first one "Person" element
    QDomElement davidElement = personsDoc.createElement( "Person" );
    davidElement.setAttribute( "firstName", "David" );
    davidElement.setAttribute( "lastName", "White" );
    personsElement.appendChild( davidElement );
    // Add the second one "Person" element
    QDomElement ivanElement = personsDoc.createElement( "Person" );
    ivanElement.setAttribute( "firstName", "Ivan" );
    ivanElement.setAttribute( "lastName", "Green" );
    personsElement.appendChild( ivanElement );

    // Make the actual result
    std::vector<Person> persons;
    ASSERT_NO_THROW( {
                         parseXmlToPersons( personsDoc, persons );
                     } );

    // Check the actual size
    std::size_t expectedSize = 2;
    std::size_t actualSize = persons.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Actual result
    QString actualLastName = persons[1].lastName( );
    // Expected result
    QString expectedLastName = "Green";
    // Check the actual result
    ASSERT_EQ( expectedLastName.toStdString( ), actualLastName.toStdString( ) );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
