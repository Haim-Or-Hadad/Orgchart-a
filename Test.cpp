#include "doctest.h"
#include <iostream>
using namespace std;
#include "sources/OrgChart.hpp"
using namespace ariel;
#include <vector>

/*firstly the correctness of level and reverse
order are being tested*/
TEST_CASE("level-order and reverse order"){
    OrgChart org_level;
    org_level.add_root("a")
             .add_sub("a", "b")
             .add_sub("a", "c")
             .add_sub("b", "d")
             .add_sub("c" , "e")
             .add_sub("d", "f")
             .add_sub("d", "g")
             .add_sub("e", "h");
    SUBCASE("level-order"){
    char ch = 'a';
    for (auto it = org_level.begin_level_order(); it < org_level.end_level_order(); it++)
    {
        CHECK_EQ(to_string(ch++), (*it));
    }
    }
    //order-level:a,b,c,d,e,f,g,h!!
    SUBCASE("reverse-order"){
    char ch = 'h';
    for (auto it = org_level.begin_reverse_order(); it < org_level.end_reverse_order(); it++)
    {
        CHECK_EQ(to_string(ch--), (*it));
    }    
    }
    //reverse-level-order:h,g,f,e,d,c,b,a    
    SUBCASE("pre-order"){
    size_t i =0;
    vector<std::string> pre_order= {"a","b","d","f","g","c","e","h"};
    for (auto it = org_level.begin_preorder(); it < org_level.end_preorder(); it++)
    {
    CHECK_EQ(pre_order.at(i++),(*it));
    }    
    }
    //pre order:a,b,d,f,g,c,e,h  
}

TEST_CASE("change the root"){
    SUBCASE("change the root"){
    OrgChart org1;
    org1.add_root("manager");  // the root now is manager
    org1.add_root("new_manager"); // the root now is manager
    auto it1 = org1.begin_level_order();
    CHECK_FALSE((*it1)=="manager");// check if the root is realy manager
    CHECK_NOTHROW(org1.add_root("new manager"));//change the root to be new_manager
    CHECK_EQ((*it1), "new manager");//check if now the root is new manager
    }
    SUBCASE("the first element Doesn't exist"){
    OrgChart org2;
    org2.add_root("manager");
    CHECK_THROWS(org2.add_sub("ceo","assistant1"));//the root is manager!!
    CHECK_NOTHROW(org2.add_sub("manager","assistant1"));
    CHECK_NOTHROW(org2.add_sub("manager","assistant2"));
    CHECK_THROWS(org2.add_sub("assistant3","player1"));//no assistant3
    }
}
