
#include <QString>
#include "gtest/gtest.h"
#include "freeFunctions.h"

TEST( writeData001, emptyArgumentTest )
{
    QString fileName = "";
    QDomDocument doc;
    QDomElement personsElement = doc.createElement( "Persons" );
    doc.appendChild( personsElement );

    ASSERT_THROW( {
                      writeData( fileName, doc );
                  }, EmptyArgument );
}

TEST( writeData002, emptyArgumentTest )
{
    QString fileName = "Persons.xml";
    QDomDocument doc;

    ASSERT_THROW( {
                      writeData( fileName, doc );
                  }, EmptyArgument );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
