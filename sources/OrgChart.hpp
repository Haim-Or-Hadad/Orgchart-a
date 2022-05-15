#pragma once

#include <iostream>
#include <vector>

namespace ariel
{
    /**
     * @brief struct to hold details about the node
     * @param parent:save the father node
     * @param role: save the name/role of the employee
     * @param childs: vector that save the children of curr node
     * @param num_of_children: save the number of node's childs
     */
    struct node
    {
        std::string parent;
        std::string role;
        std::vector<node> childs;
        //int level;
        int num_of_children;
    };

    //class Iterator;
    /**
     * @brief this class represents orgchart that include some types of iterators 
     * level order,reverse order and preorder
     * @param _node: save all the details about the organization
     * @param find_parents: flag to know if son find is father in add_sub func
     */
    class OrgChart
    {
        private:
        node _node;
        bool find_parent;
        std::string out_;

        public:
        /*constructor*/
        OrgChart();

        /*methods for building of the orgchart*/
        OrgChart &add_root(std::string role);
        OrgChart &add_sub(std::string person1, std::string person2);
        
        /*getters*/
        std::string &get_name(){return this->_node.role;}
        std::vector<node> &get_list(){return this->_node.childs;}

        /*vectors that save the order of each iterator*/
        std::vector<std::string> v_level;// level order
        //std::vector<std::string> rev_order;//reverse order
        //std::vector<std::string> pre_order;//pre order

        /*6 methods to return iterators*/
        std::vector<std::string>::iterator begin_level_order();
        std::vector<std::string>::iterator end_level_order();
        std::vector<std::string>::iterator begin_reverse_order();
        std::vector<std::string>::iterator end_reverse_order();
        std::vector<std::string>::iterator reverse_order();
        std::vector<std::string>::iterator begin_preorder();
        std::vector<std::string>::iterator end_preorder();
        std::string &_output(node &head);
        friend std::ostream &operator<<(std::ostream &output,  OrgChart &head);

        
        /*inline implements of begin and end iterator's methods*/
        std::vector<std::string>::iterator begin() {return begin_level_order();}
        std::vector<std::string>::iterator end(){return end_level_order();}
        
        /*recursive traversals for add_sub,level order,reverse order and pre order functions*/
        void parent_exist(node &head,std::string parent, std::string child);
        void level_order(node &head);
            
    ~OrgChart();
    };
}
