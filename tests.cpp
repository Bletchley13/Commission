#include "Commission.h"
#include <gtest/gtest.h>

TEST(BoundaryTest, Lock) { 
	EXPECT_FLOAT_EQ( 0 , Commission(0,0,0)  );
	EXPECT_FLOAT_EQ( 10.0, Commission(1,1,1) );
	EXPECT_FLOAT_EQ( 4.5, Commission(1,0,0) );
	EXPECT_FLOAT_EQ( 490.0, Commission(70,0,0) );
	EXPECT_FLOAT_EQ( 481.0, Commission(69,0,0) );
		

	EXPECT_FLOAT_EQ( Invalid, Commission(71,0,0) );
	EXPECT_FLOAT_EQ( Invalid, Commission(-2,0,0) );
}

TEST(BoundaryTest, Stack) {
        EXPECT_FLOAT_EQ( 3.0, Commission(0,1,0) );
        EXPECT_FLOAT_EQ( 340.0, Commission(0,80,0) );
        EXPECT_FLOAT_EQ( 334.0, Commission(0,79,0) );


        EXPECT_FLOAT_EQ( Invalid, Commission(0,81,0) );
	EXPECT_FLOAT_EQ( Invalid, Commission(0,-2,0) );
        EXPECT_FLOAT_EQ( Invalid, Commission(0,-1,0) );
}
 
TEST(BoundaryTest, Barrel) {
        EXPECT_FLOAT_EQ( 2.5, Commission(0,0,1) );
        EXPECT_FLOAT_EQ( 310.0, Commission(0,0,90) );
        EXPECT_FLOAT_EQ( 305.0, Commission(0,0,89) );


        EXPECT_FLOAT_EQ( Invalid, Commission(0,0,91) );
        EXPECT_FLOAT_EQ( Invalid, Commission(0,0,-1) );
        EXPECT_FLOAT_EQ( Invalid, Commission(0,0,-2) );
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
