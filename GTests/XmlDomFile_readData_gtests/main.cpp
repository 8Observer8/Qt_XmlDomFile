
#include <QString>
#include <vector>
#include "gtest/gtest.h"
#include "freeFunctions.h"
#include "Person.h"

TEST( readData001, emptyArgumentTest )
{
    QString fileName = "";
    QDomDocument doc;

    ASSERT_THROW( {
                      readData( fileName, doc );
                  }, EmptyArgument );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
