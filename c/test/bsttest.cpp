#include "bstlib.cpp"
#include <gtest/gtest.h>

TEST(findNode, t1) {
    Node* root = NULL;
    BST bst(root);
    bst.addNode(15);
    bst.addNode(10);
    bst.addNode(20);
    bst.addNode(25);
    bst.addNode(8);
    bst.addNode(12);

    ASSERT_EQ(true, bst.findNode(25));
    ASSERT_EQ(false, bst.findNode(24));
}

TEST(serializeLEVEL, t1) {
    Node* root = NULL;
    BST bst(root);
    bst.addNode(15);
    bst.addNode(10);
    bst.addNode(20);
    bst.addNode(25);
    bst.addNode(8);
    bst.addNode(12);

    ASSERT_EQ("15,10,20,8,12,#,25,", bst.serializeLEVEL());
}

TEST(deserializeLEVEL, t2) {
    BST bst("15,10,20,8,12,#,25,");

    ASSERT_EQ("15,10,20,8,12,#,25,", bst.serializeLEVEL());
}

TEST(serializeDLR, t1) {
    Node* root = NULL;
    BST bst(root);
    bst.addNode(15);
    bst.addNode(10);
    bst.addNode(20);
    bst.addNode(25);
    bst.addNode(8);
    bst.addNode(12);

    ASSERT_EQ("15,10,8,12,20,#,25,", bst.serializeDLR());
}

TEST(deserializeDLR, t1) {
    BST bst0((Node*)NULL);
    Node* root = bst0.deserializeDLR("15,10,8,12,20,#,25,");
    BST bst(root);
    
    ASSERT_EQ("15,10,8,12,20,#,25,", bst.serializeDLR());
}
int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
	
