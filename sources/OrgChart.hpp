
#include <iostream>
#include <vector>
#include <string>


using namespace std;

namespace ariel {
    struct Node {
        string Name;
        vector <Node> Sons;
    };
    class OrgChart {
    private:
        Node root;
    public:
        OrgChart &add_root(string name);
        OrgChart &add_sub(string nameONE, string nameTWO);
        string *begin_level_order();
        string *end_level_order();
        string *begin_reverse_order();
        string *end_reverse_order();
        string *begin_preorder();
        string *end_preorder();
        string *reverse_order();
        string* begin();
        string* end();
        friend ostream &operator<<(ostream &output, OrgChart &root);
    };
}