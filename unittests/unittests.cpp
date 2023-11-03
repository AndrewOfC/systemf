//
// Created by andrew on 11/3/23.
//
#include <gtest/gtest.h>
#include <systemf/systemf.h>
#include <sstream>

using namespace std ;

TEST(unittests, simple_command)
{
    GTEST_ASSERT_EQ(0, systemf("ls %s", ".")) ;
}

TEST(unittests, big_command)
{
    stringstream ss ;

    for(int i = 0 ; i < 8 ; i++ )
        ss << "000000000000000000000000000000000000000000000000000000000000000000000000" << endl ;

    GTEST_ASSERT_GT(ss.str().size(), SYSTEMF_MAXIMUM_SMALL_BUFFER) ;

    GTEST_ASSERT_EQ(0, systemf("cat - <<!\n%s!\n", ss.str().c_str())) ;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}