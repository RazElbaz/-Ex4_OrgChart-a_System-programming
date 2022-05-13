#include <string>
#include <vector>
#include <algorithm>
#include "doctest.h"
#include "sources/OrgChart.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Good input") {
    OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")
            .add_sub("CEO", "CFO")
            .add_sub("CEO", "COO")
            .add_sub("CTO", "VP_SW")
            .add_sub("COO", "VP_BI");
    vector<string> result = {"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
    vector<string> reverseOrder = {"VP_BI", "VP_SW", "COO", "CFO", "CTO", "CEO"};;
    size_t index=0;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        CHECK_EQ(*it, result.at(index++));
    }
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
                CHECK_EQ(*it, reverseOrder.at(index++));
    }
}

TEST_CASE("Good input 2") {
    OrgChart organization;
    organization.add_root("Benny")
            .add_sub("Benny", "Raz")         // Now the CTO is subordinate to the CEO
            .add_sub("Benny", "Elbar")         // Now the CFO is subordinate to the CEO
            .add_sub("Benny", "Yamit")         // Now the COO is subordinate to the CEO
            .add_sub("Raz", "Oria") // Now the VP Software is subordinate to the CTO
            .add_sub("Yamit", "Laki");      // Now the VP_BI is subordinate to the COO
    vector<string> result = {"Benny", "Raz", "Elbar", "Yamit", "Oria", "Laki"};
    size_t index=0;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
                CHECK_EQ(*it, result.at(index++));
    }
}

TEST_CASE("Check false") {
    OrgChart organization1;
    OrgChart organization2;

    organization1.add_root("Benny")
            .add_sub("Benny", "Raz")
            .add_sub("Benny", "Elbar")
            .add_sub("Benny", "Yamit")
            .add_sub("Raz", "Oria")
            .add_sub("Yamit", "Laki");

    organization2.add_root("CEO")
            .add_sub("CEO", "CTO")
            .add_sub("CEO", "CFO")
            .add_sub("CEO", "COO")
            .add_sub("CTO", "VP_SW")
            .add_sub("COO", "VP_BI");
    for (auto it = organization1.begin_level_order(); it != organization1.end_level_order(); ++it)
    {
                CHECK_FALSE(*it=="False");
    }
    for (auto it = organization2.begin_level_order(); it != organization2.end_level_order(); ++it)
    {
                CHECK_FALSE(*it=="False");
    }
}
TEST_CASE("Check throw add sub") {
    OrgChart organization1;
    OrgChart organization2;
    OrgChart organization3;
    OrgChart organization4;
    organization1.add_root("Benny")
            .add_sub("Benny", "Raz")
            .add_sub("Benny", "Elbar")
            .add_sub("Benny", "Yamit")
            .add_sub("Raz", "Oria")
            .add_sub("Yamit", "Laki");

    organization2.add_root("CEO")
            .add_sub("CEO", "CTO")
            .add_sub("CEO", "CFO")
            .add_sub("CEO", "COO")
            .add_sub("CTO", "VP_SW")
            .add_sub("COO", "VP_BI");

    organization3.add_root("1")
            .add_sub("1", "2")
            .add_sub("1", "3")
            .add_sub("1", "4")
            .add_sub("2", "5")
            .add_sub("4", "6");

    organization4.add_root("A")
            .add_sub("A", "B")
            .add_sub("A", "C")
            .add_sub("A", "D")
            .add_sub("B", "E")
            .add_sub("D", "F");

    CHECK_THROWS(organization1.add_sub("nobody","Benny"));
    CHECK_THROWS(organization1.add_sub("nobody","RAZ"));
    CHECK_THROWS(organization1.add_sub("nobody","Elbar"));
    CHECK_THROWS(organization1.add_sub("nobody","Yamit"));
    CHECK_THROWS(organization1.add_sub("nobody","Oria"));
    CHECK_THROWS(organization1.add_sub("nobody","Laki"));

    CHECK_THROWS(organization2.add_sub("nobody","CEO"));
    CHECK_THROWS(organization2.add_sub("nobody","CTO"));
    CHECK_THROWS(organization2.add_sub("nobody","CFO"));
    CHECK_THROWS(organization2.add_sub("nobody","COO"));
    CHECK_THROWS(organization2.add_sub("nobody","VP_SW"));
    CHECK_THROWS(organization2.add_sub("nobody","VP_BI"));

    CHECK_THROWS(organization3.add_sub("nobody","1"));
    CHECK_THROWS(organization3.add_sub("nobody","2"));
    CHECK_THROWS(organization3.add_sub("nobody","3"));
    CHECK_THROWS(organization3.add_sub("nobody","4"));
    CHECK_THROWS(organization3.add_sub("nobody","5"));
    CHECK_THROWS(organization3.add_sub("nobody","6"));

    CHECK_THROWS(organization3.add_sub("nobody","A"));
    CHECK_THROWS(organization3.add_sub("nobody","B"));
    CHECK_THROWS(organization3.add_sub("nobody","C"));
    CHECK_THROWS(organization3.add_sub("nobody","D"));
    CHECK_THROWS(organization3.add_sub("nobody","E"));
    CHECK_THROWS(organization3.add_sub("nobody","F"));
}
