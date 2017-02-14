#include "bstlib.cpp"
#include <gtest/gtest.h>

TEST(MinValueTest, t1) {
	BstNode *root = 0;
	root = Insert(root, 14);
	root = Insert(root, 10);
	root = Insert(root, 20);
	ASSERT_EQ(10, MinValue(root));
}

TEST(MinValueTest, t2) {
	BstNode *root = 0;
	root = Insert(root, 14);
	root = Insert(root, 30);
	root = Insert(root, 32);
	ASSERT_EQ(14, MinValue(root));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
	
