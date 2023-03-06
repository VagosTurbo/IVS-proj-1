//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     BORIS SEMANCO <xseman06@stud.fit.vutbr.cz>
// $Date:       $2023-03-03
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author BORIS SEMANCO
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//

/*** Konec souboru black_box_tests.cpp ***/

class EmptyTree : public ::testing::Test {
protected:
    BinaryTree tree;
};

class NonEmptyTree : public ::testing::Test {
protected:
    BinaryTree tree;
    virtual void SetUp() {
        for(int i = 0; i < 10; i++){
            tree.InsertNode(i);
        }
    }
};

class TreeAxioms : public ::testing::Test {
protected:
    BinaryTree tree;
    virtual void SetUp() {
        for(int i = 0; i < 10; i++){
            tree.InsertNode(i);
        }
    }    
};

//EMPTY TREE TESTS

TEST_F(EmptyTree, InsertNode){
    auto result = tree.InsertNode(10);
    EXPECT_TRUE(result.first);
    EXPECT_NE(tree.FindNode(10), nullptr);
    EXPECT_EQ(result.second->key,10);

    auto result2 = tree.InsertNode(10);
    EXPECT_FALSE(result2.first);
    EXPECT_EQ(result.second->key, result2.second->key);
}

TEST_F(EmptyTree, DeleteNode){
    EXPECT_FALSE(tree.DeleteNode(1));
}

TEST_F(EmptyTree, FindNode){
    EXPECT_EQ(tree.FindNode(1), nullptr);
    tree.InsertNode(1);
    EXPECT_NE(tree.FindNode(1), nullptr);
}

//NON-EMPTY TREE TESTS

TEST_F(NonEmptyTree, InsertNode){
    auto result = tree.InsertNode(2);
    EXPECT_FALSE(result.first);
    EXPECT_EQ(result.second, tree.FindNode(2));
    EXPECT_EQ(result.second->key, 2);
    auto result2 = tree.InsertNode(10);
    EXPECT_TRUE(result2.first);
}

TEST_F(NonEmptyTree, DeleteNode){
    EXPECT_TRUE(tree.DeleteNode(2));
    EXPECT_EQ(tree.FindNode(2), nullptr);
    EXPECT_FALSE(tree.DeleteNode(10));
}

TEST_F(NonEmptyTree, FindNode){
    EXPECT_NE(tree.FindNode(5), nullptr);
    EXPECT_EQ(tree.FindNode(10), nullptr);
}

//AXIOMS TESTS
//Všechny listové uzly (tedy uzly bez potomků) jsou černé.
TEST_F(TreeAxioms, Axiom1){
    std::vector<BinaryTree::Node_t *> outLeafNodes;
    tree.GetLeafNodes(outLeafNodes);
    
    for(BinaryTree::Node_t *leafNode : outLeafNodes){
        EXPECT_EQ(leafNode->color, BLACK);
    }
}


//Pokud je uzel červený, pak jsou jeho oba potomci černé
TEST_F(TreeAxioms, Axiom2){
    std::vector<BinaryTree::Node_t *> allNodes;
    tree.GetAllNodes(allNodes);

    for(BinaryTree::Node_t *node : allNodes){
        if(node->color == RED){
            EXPECT_EQ(node->pLeft->color, BLACK);
            EXPECT_EQ(node->pRight->color, BLACK);
        }
    }
}

//Každá cesta od každého listového uzlu ke kořeni obsahuje stejný počet černých uzlů (vizte oranžové cesty v obrázku).
TEST_F(TreeAxioms, Axiom3){
    std::vector<BinaryTree::Node_t *> outLeafNodes;
    tree.GetLeafNodes(outLeafNodes);
    int NumOfBlackNodes = 0;
    int IterationCnt = 0;

    for(BinaryTree::Node_t *LeafNode : outLeafNodes){
        int blackNodeCounter = 0;
        while (LeafNode != nullptr)
        {
            if(LeafNode->color == BLACK){
                blackNodeCounter++;
            }
            LeafNode = LeafNode->pParent;
        }
        if(IterationCnt == 0){
            NumOfBlackNodes = blackNodeCounter;
        }
        EXPECT_EQ(NumOfBlackNodes, blackNodeCounter);
        IterationCnt++;
    }
}
