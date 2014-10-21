#include "Commission.h"
#include <gtest/gtest.h>

TEST(BoundaryTest, Lock) { 
	EXPECT_EQ( 0 , Commission(0,0,0)  );
	EXPECT_EQ( 1, Commission(1,1,1) );
	
}

TEST(BoundaryTest, Stack) {
	
}
 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
