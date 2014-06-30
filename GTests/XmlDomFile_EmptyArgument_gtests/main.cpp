
#include <gtest/gtest.h>
#include <string>
#include "EmptyArgument.h"

TEST( test001, messageTest ) {
    std::string functionName = "readData()";
    EmptyArgument error( functionName );

    std::string actual = error.message( );
    std::string expected = "Error: empty argument in the "
            "function \"" + functionName + "\"";

    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
