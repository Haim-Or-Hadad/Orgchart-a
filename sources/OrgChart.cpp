#include <iostream>
#include <vector>

#include "OrgChart.hpp"

using namespace std;


namespace ariel
{
    OrgChart::OrgChart(){
        this->num_of_children =0;
    };

     OrgChart &OrgChart::add_root(string role)
     {
         this->_node.role = role;//put role's name in field
         return *this;//return pointer to the head of tree
     }
   
    OrgChart &OrgChart::add_sub(string person1, string person2)
    {
        std::vector<node> temp = this->_node.childs;
        if (this->_node.role == person1)
        {
        node new_son;
        new_son.role = person2;
        this->_node.parent = person1;
        this->_node.childs.push_back(new_son);
        }
        else
        {
        for (size_t i = 0; i < temp.size(); i++)
        {
            if (temp.at(i).role == person1)
            {
                node new_son;
                new_son.role = person2;
                this->_node.childs.push_back(new_son);
                break;
            }
            
        }
            }  
        return *this;
    }
   ///////////////////////////////////////////////////////
   ///-----------------level-order---------------------///
    void OrgChart::level_order(node &head)
    {

    }
    vector<string>::iterator OrgChart::begin_level_order()
    {

        ///////////////////////
        this->v_level.clear();
        this->v_level.push_back(this->_node.role);
        for (size_t i = 0; i < this->_node.childs.size(); i++)
        {
            this->v_level.push_back(this->_node.childs.at(i).role);
        }
        return this->v_level.begin();
    }

    vector<string>::iterator  OrgChart::end_level_order()
    {
    return this->v_level.end();
    }

     vector<string>::iterator OrgChart::begin_reverse_order()
    {
        this->v_level.clear();
        for (int i = this->_node.childs.size()-1; i >= 0; i--)
        {
            this->v_level.push_back(this->_node.childs[(size_t)i].role);
        }
        this->v_level.push_back(this->_node.role);
        return this->v_level.begin();
    }

     vector<string>::iterator OrgChart::end_reverse_order()
    {
    return this->v_level.end();
    }

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
    ostream &operator<<(ostream &output,  OrgChart &head)
    {
        for (auto i = head.begin_level_order(); i != head.end_level_order(); i++)
        {
            output <<(*i) << " ";
            if ((*i)==head._node.role)
            {
                output << endl;
                output << "|-----|-----|" << endl ;
            }
            
        }
         return output;
    }
    OrgChart::~OrgChart(){

    };


}
// using namespace ariel;
// int main(){
//     OrgChart organization;
//     organization.add_root("manager");
//     //cout << organization.get_name() << endl;
//     organization.add_sub("manager","Assistant");
//     //cout << organization.get_list().at(0).role << endl;
//     organization.add_sub("manager","Assistant");
//     //cout << organization.get_list().at(1).role << endl;
//     organization.add_sub("Assistant","player");
//     //cout << organization.get_list().at(2).role << endl;
//     organization.add_sub("Assistant","player");
//     organization.add_sub("Assistant","player");
//     //organization.add_root("haim");
//     //cout << organization.get_list().at(3).role << endl;
//     //cout << organization.get_list().at(4).role << endl;
//     // for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//     // {
//     //cout << organization << endl ;
//     //} // prints: CEO CTO CFO COO VP_SW VP_BI
//     //return 1;
//     cout << "level order:" << endl;
// for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//   {
//     cout << (*it) << " " ;
//   }
//   cout <<  endl ;
//   cout << "reverse order:" << endl;
//     for (auto it = organization.begin_reverse_order(); it != organization.end_reverse_order(); ++it)
//   {
//     cout << (*it) << " " ;
//   } // prints: VP_SW VP_BI CTO CFO COO CEO
// //     cout <<  endl ;
// }
