//======== Copyright (c) 2022, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - test suite
//
// $NoKeywords: $ivs_project_1 $white_box_tests.cpp
// $Author:     BORIS SEMANCO <xseman06@stud.fit.vutbr.cz>
// $Date:       $2023-03-07
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author BORIS SEMANCO
 * 
 * @brief Implementace testu hasovaci tabulky.
 */

#include <vector>

#include "gtest/gtest.h"

#include "white_box_code.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy hasovaci tabulky, testujte nasledujici:
// 1. Verejne rozhrani hasovaci tabulky
//     - Vsechny funkce z white_box_code.h
//     - Chovani techto metod testuje pro prazdnou i neprazdnou tabulku.
// 2. Chovani tabulky v hranicnich pripadech
//     - Otestujte chovani pri kolizich ruznych klicu se stejnym hashem 
//     - Otestujte chovani pri kolizich hashu namapovane na stejne misto v 
//       indexu
//============================================================================//

class EmptyTable : public ::testing::Test {
protected:
    hash_map_t* map;

    virtual void SetUp(){
        map = hash_map_ctor();
    }

    virtual void TearDown(){
        hash_map_dtor(map);
    }
};

class NonEmptyTable : public ::testing::Test {
protected:
    hash_map_t* map;

    virtual void SetUp(){
        map = hash_map_ctor();
        hash_map_put(map, "hello", 5);
        hash_map_put(map, "hi", 10);
        hash_map_put(map, "howdy", 15);
        hash_map_put(map, "hola", 20);
    }

    virtual void TearDown(){
        hash_map_dtor(map);
    }
};

TEST_F(EmptyTable, contains){
    EXPECT_FALSE(hash_map_contains(map, "hello"));
}

TEST_F(EmptyTable, get){
    int value = 9;
    EXPECT_EQ(hash_map_get(map, "hello", &value), KEY_ERROR);
}

TEST_F(EmptyTable, size){
    EXPECT_EQ(hash_map_size(map), 0);
}


//////////////////////////////////////////////////////////////////////////////

TEST_F(NonEmptyTable, contains){
    EXPECT_TRUE(hash_map_contains(map, "hello"));
    EXPECT_FALSE(hash_map_contains(map, "aaaa"));
}

TEST_F(NonEmptyTable, get){
    int value = 5;
    EXPECT_EQ(hash_map_get(map, "hello", &value), OK);
    value = 6;
    EXPECT_EQ(hash_map_get(map, "hello", &value), OK);
}

TEST_F(NonEmptyTable, size){
    EXPECT_EQ(hash_map_size(map), 4);
}


/*** Konec souboru white_box_tests.cpp ***/