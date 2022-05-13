#include "OrgChart.hpp"
using namespace std;
namespace ariel{
    OrgChart& OrgChart::add_root(string name){
        this->root.Name=name;
        return *this;}
    OrgChart& OrgChart::add_sub(string nameONE, string nameTWO) {return *this;}
    string* OrgChart::begin_level_order(){return NULL;}
    string *OrgChart::end_level_order(){return NULL;}
    string* OrgChart::begin_reverse_order(){return NULL;}
    string* OrgChart::end_reverse_order(){return NULL;}
    string* OrgChart::begin_preorder(){return NULL;}
    string* OrgChart::end_preorder(){return NULL;}
    string* OrgChart::reverse_order(){return NULL;}
    string* OrgChart::begin(){return begin_level_order();}
    string* OrgChart::end(){return end_level_order();}
    //I used the website https://www.geeksforgeeks.org/introduction-iterators-c/
    ostream &operator<<(ostream &output, OrgChart &start){
        for (auto i = start.begin_level_order(); i != start.end_level_order(); i++)
            output << *i << " ";
        return output;
    }
}