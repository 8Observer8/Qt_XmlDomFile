
#include <gtest/gtest.h>
#include <string>
#include "FileOpenError.h"

TEST( test001, messageTest ) {
    std::string fileName = "input.txt";
    std::string functionName = "readData()";
    FileOpenError error( fileName, functionName );

    std::string actual = error.message( );
    std::string expected = "Error: unable to open the "
            "file \"" + fileName + "\" in the "
            "function \"" + functionName + "\"";
    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
