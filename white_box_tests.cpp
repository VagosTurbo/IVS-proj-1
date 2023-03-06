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
    hash_map_t* table;
};

class NonEmptyTable : public ::testing::Test {
protected:
    hash_map_t* table;

    void SetUp(){
        hash_map_item_t item;
    }

};


TEST(BasicTests, TableConstructor) {
    hash_map_t* table;
    EXPECT_NE(table, nullptr);
    EXPECT_NE(table->last, nullptr);
}

TEST(BasicTests, TableDestructor) {
    hash_map_t* table;
    EXPECT_NE(table, nullptr);
    EXPECT_NE(table->last, nullptr);
}


/*** Konec souboru white_box_tests.cpp ***/