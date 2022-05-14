#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

namespace ariel
{
    class Iterator;
    struct node
    {
        std::string parent;
        std::string role;
        std::vector<node> childs;
    };
    
    class OrgChart
    {
        private:
        node _node;
        int num_of_children;

        public:
        OrgChart();

        OrgChart &add_root(std::string role);
        OrgChart &add_sub(std::string person1, std::string person2);
        
        /////////getters/////////
        std::string &get_name(){return this->_node.role;}
        std::vector<node> &get_list(){return this->_node.childs;}
        //////vectors fot iterate over tree////
        std::vector<std::string> v_level;


        
        std::vector<std::string>::iterator begin_level_order();
        std::vector<std::string>::iterator end_level_order();
        std::vector<std::string>::iterator begin_reverse_order();
        std::vector<std::string>::iterator end_reverse_order();
        std::vector<std::string>::iterator reverse_order();
        std::vector<std::string>::iterator begin_preorder();
        std::vector<std::string>::iterator end_preorder();

        friend std::ostream &operator<<(std::ostream &output,  OrgChart &head);
        
        std::vector<std::string>::iterator begin(){
            return begin_level_order();
            }
        std::vector<std::string>::iterator end(){
            return end_level_order();
            }
        /////////////recursive traversals//////////////
        void level_order(node &head);
            
    ~OrgChart();
    };
}
