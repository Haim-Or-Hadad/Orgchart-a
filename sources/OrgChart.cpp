#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "OrgChart.hpp"

using namespace std;


namespace ariel
{
    OrgChart::OrgChart(){
        this->find_parent = false;
        //this->_node.level =0;
    };

     OrgChart &OrgChart::add_root(string role)
     {
         this->_node.role = role;
         return *this;//return pointer to the head of tree
     }

     /*traversal over the tree if parent found so "find_parent" flag change to true */
    void OrgChart::parent_exist(node &head,string parent, string child){
        if(head.role == parent)
        {
        node new_node;
        new_node.parent=parent;
        new_node.role=child;
        //new_node.level = head.level++;
        head.childs.push_back(new_node);
        head.num_of_children++;
        this->find_parent = true;
        }
        else
        {
        for (auto& it : head.childs) {
            parent_exist((it),parent,child);
        }
        }
    }
    /*this function add a new node to tree, if the parent's node doesn't exist so exception throws*/
    OrgChart &OrgChart::add_sub(string person1, string person2)
    {
        this->parent_exist(this->_node,person1,person2);
        if (!this->find_parent)
        {
            throw ("no parent");
        }
        this->find_parent = false;
        return *this;
    }

   ///////////////////////////////////////////////////////
   ///-----------------level-order---------------------///
   ///////////////////////////////////////////////////////
   /*traversal over the tree in level order*/
    void OrgChart::level_order(node &head)
    {      
        for (auto& child : head.childs) {
            this->v_level.push_back(child.role);
        }
        for (auto& child : head.childs)
        {
            level_order(child);
        }
    }
    vector<string>::iterator OrgChart::begin_level_order()
    {

        this->v_level.clear();
        this->v_level.push_back(this->_node.role);
        this->level_order(this->_node);
        return this->v_level.begin();
    }
    vector<string>::iterator  OrgChart::end_level_order()
    {
    return this->v_level.end();
    }

   ///////////////////////////////////////////////////////
   ///-----------------reverse-order---------------------///
   ///////////////////////////////////////////////////////
   /*traversal over the tree in reverse order*/
     vector<string>::iterator OrgChart::begin_reverse_order()
    {
        this->begin_level_order();
        reverse(this->v_level.begin(), this->v_level.end());
        return this->v_level.begin();
    }

     vector<string>::iterator OrgChart::end_reverse_order()
    {
    return this->v_level.end();
    }

   ///////////////////////////////////////////////////////
   ///-----------------pre-order---------------------///
   ///////////////////////////////////////////////////////
   /*traversal over the tree in pre order*/
    std::vector<string>::iterator OrgChart::begin_preorder()
    {
return {};
    }

    std::vector<string>::iterator OrgChart::end_preorder()
    {
return {};
    }

     std::vector<string>::iterator OrgChart::reverse_order()
     {
return {};
     }
    // string & OrgChart::_output(node &head)
    // {      
    //     for (auto& child : head.childs) {
    //        this->out_ += child.role;
    //        this->out_ += "-------";
    //     }
    //     this->out_ += '\n';
    //     this->out_ += '|';
    //     this->out_ += '\n';
    //     for (auto& child : head.childs)
    //     {
    //         _output(child);
    //         this->out_ += '      ';
    //     }
    //     return out_ ;
    // }
    ostream &operator<<(ostream &output,  OrgChart &head)
    {
        //string print_ = head._output(head._node);
        for (auto i = head.begin_level_order(); i != head.end_level_order(); i++)
        {
            output <<(*i) << " ";
            if ((*i)==head._node.role)
            {
                output << endl;
                output << "|-----|-----|" << endl ;
            }
        //output << print_ <<endl;
        }
         return output;
    }

    
    OrgChart::~OrgChart(){

    }
};



// using namespace ariel;
// int main(){
//     OrgChart organization;
//     organization.add_root("manager");
//     //cout << organization.get_name() << endl;
//     organization.add_sub("manager","Assistant1");
//     //cout << organization.get_list().at(0).role << endl;
//     organization.add_sub("manager","Assistant2");
//     //cout << organization.get_list().at(1).role << endl;
//     organization.add_sub("Assistant1","player");
//     //cout << organization.get_list().at(2).role << endl;
//     organization.add_sub("Assistant2","player");
//     organization.add_sub("Assistant2","player");
//     //organization.add_root("haim");
//     //cout << organization.get_list().at(3).role << endl;
//     //cout << organization.get_list().at(4).role << endl;
//     // for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     // {
//     cout << organization << endl ;
//     //} // prints: CEO CTO CFO COO VP_SW VP_BI
//     //return 1;
//     //cout << "level order:" << endl;
// // for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
// //   {
// //     cout << (*it) << " " ;
// //   }
// //   cout <<  endl ;
// //   cout << "reverse order:" << endl;
// //     for (auto it = organization.begin_reverse_order(); it != organization.end_reverse_order(); ++it)
// //   {
// //     cout << (*it) << " " ;
// //   } // prints: VP_SW VP_BI CTO CFO COO CEO
// //     cout <<  endl ;
// }