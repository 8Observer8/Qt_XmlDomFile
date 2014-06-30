
#include <gtest/gtest.h>
#include <string>
#include "Person.h"

TEST( test001, firstNameTest ) {
    Person person( "David", "White" );

    std::string actual = person.firstName( );
    std::string expected = "David";

    ASSERT_EQ( expected, actual );
}

TEST( test002, lastNameTest ) {
    Person person( "David", "White" );

    std::string actual = person.lastName( );
    std::string expected = "White";

    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
