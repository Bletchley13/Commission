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

TEST( EquivalentClassTest, LESS1000) {
	EXPECT_FLOAT_EQ( 70.0, Commission(7,7,7) );
	EXPECT_FLOAT_EQ( 100.0, Commission(10,10,10) );
	EXPECT_FLOAT_EQ( 90.0, Commission(5,10,15) );
	EXPECT_FLOAT_EQ( 90.0, Commission(20,0,0) );
	EXPECT_FLOAT_EQ( 60.0, Commission(0,20,0) );
}

TEST( EquivalentClassTest, MORE1000LESS1800) {
	EXPECT_FLOAT_EQ( 220.0, Commission(10,20,30) );
	EXPECT_FLOAT_EQ( 175.0, Commission(15,15,15) );
	EXPECT_FLOAT_EQ( 115.0, Commission(15,10,5) );
	EXPECT_FLOAT_EQ( 152.5, Commission(30,0,0) );
	EXPECT_FLOAT_EQ( 137.5, Commission(0,0,50) );
}

TEST( EquivalentClassTest, MORE1800) {
	EXPECT_FLOAT_EQ( 1060.0, Commission(60,60,60) );
	EXPECT_FLOAT_EQ( 260.0, Commission(20,20,20) );
	EXPECT_FLOAT_EQ( 310.0, Commission(50,0,0) );
	EXPECT_FLOAT_EQ( 280.0, Commission(0,70,0) );
 	EXPECT_FLOAT_EQ( 260.0, Commission(0,0,80) );
}

TEST( EquivalentClassTest, INVALID) {
        EXPECT_FLOAT_EQ( Invalid, Commission(90,60,60) );
        EXPECT_FLOAT_EQ( Invalid, Commission(20,100,20) );
        EXPECT_FLOAT_EQ( Invalid, Commission(50,0,110) );
        EXPECT_FLOAT_EQ( Invalid, Commission(-7,70,0) );
        EXPECT_FLOAT_EQ( Invalid, Commission(0,0,-8) );
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
