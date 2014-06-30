
#include <vector>
#include "gtest/gtest.h"
#include "freeFunctions.h"
#include "Person.h"

TEST( parsePersonsToXml_001, emptyArgumentTest )
{
    // Input data
    std::vector<Person> persons;

    // Actual result
    QDomDocument doc;
    ASSERT_THROW( {
                      parsePersonsToXml( persons, doc );
                  }, EmptyArgument );
}

TEST( parsePersonsToXml_002, firstNameForFirstPersonTest )
{
    // Input data
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    std::vector<Person> persons;
    persons.push_back( david );
    persons.push_back( ivan );

    // Actual result
    QDomDocument actualDoc;
    ASSERT_NO_THROW( {
                         parsePersonsToXml( persons, actualDoc );
                     } );

//    // Make the expected result
//    QDomDocument expectedDoc("Document");
//    QDomElement expectedPersonsElement = expectedDoc.createElement( "Persons" );
//    // First person
//    QDomElement expectedDavidElement = expectedDoc.createElement( "Person" );
//    expectedDavidElement.setAttribute( "firstName", "David" );
//    expectedDavidElement.setAttribute( "lastName", "White" );
//    // Add the person to the expected document
//    expectedDoc.appendChild( expectedDavidElement );
//    // Second person
//    QDomElement expectedIvanElement = expectedDoc.createElement( "Person" );
//    expectedIvanElement.setAttribute( "firstName", "Ivan" );
//    expectedIvanElement.setAttribute( "lastName", "Green" );
//    // Add the person to the expected document
//    expectedDoc.appendChild( expectedIvanElement );

    // Expected result
    QString expectedFirstName = "David";

    // Check the actual result
    QDomElement actualPersonsElement = actualDoc.firstChildElement( "Persons" );
    QDomElement actualDavidElement = actualPersonsElement.firstChildElement( "Person" );
    QString actualFirstName = actualDavidElement.attribute( "firstName" );
    ASSERT_EQ( expectedFirstName.toStdString( ), actualFirstName.toStdString( ) );
}

TEST( parsePersonsToXml_003, lastNameForFirstPersonTest )
{
    // Input data
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    std::vector<Person> persons;
    persons.push_back( david );
    persons.push_back( ivan );

    // Actual result
    QDomDocument actualDoc;
    ASSERT_NO_THROW( {
                         parsePersonsToXml( persons, actualDoc );
                     } );

    // Expected result
    QString expectedLastName = "White";

    // Check the actual result
    QDomElement actualPersonsElement = actualDoc.firstChildElement( "Persons" );
    QDomElement actualDavidElement = actualPersonsElement.firstChildElement( "Person" );
    QString actualLastName = actualDavidElement.attribute( "lastName" );
    ASSERT_EQ( expectedLastName.toStdString( ), actualLastName.toStdString( ) );
}

TEST( parsePersonsToXml_004, firstNameForSecondPersonTest )
{
    // Input data
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    std::vector<Person> persons;
    persons.push_back( david );
    persons.push_back( ivan );

    // Actual result
    QDomDocument actualDoc;
    ASSERT_NO_THROW( {
                         parsePersonsToXml( persons, actualDoc );
                     } );

    // Expected result
    QString expectedFirstName = "Ivan";

    // Check the actual result
    QDomElement actualPersonsElement = actualDoc.firstChildElement( "Persons" );
    QDomElement actualDavidElement = actualPersonsElement.firstChildElement( "Person" );
    QDomElement actualIvanElement = actualDavidElement.nextSiblingElement( "Person" );
    QString actualFirstName = actualIvanElement.attribute( "firstName" );
    ASSERT_EQ( expectedFirstName.toStdString( ), actualFirstName.toStdString() );
}

TEST( parsePersonsToXml_005, lastNameForSecondPersonTest )
{
    // Input data
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    std::vector<Person> persons;
    persons.push_back( david );
    persons.push_back( ivan );

    // Actual result
    QDomDocument actualDoc;
    ASSERT_NO_THROW( {
                         parsePersonsToXml( persons, actualDoc );
                     } );

    // Expected result
    QString expectedLastName = "Green";

    // Check the actual result
    QDomElement actualPersonsElement = actualDoc.firstChildElement( "Persons" );
    QDomElement actualDavidElement = actualPersonsElement.firstChildElement( "Person" );
    QDomElement actualIvanElement = actualDavidElement.nextSiblingElement( "Person" );
    QString actualLastName = actualIvanElement.attribute( "lastName" );
    ASSERT_EQ( expectedLastName.toStdString( ), actualLastName.toStdString( ) );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
