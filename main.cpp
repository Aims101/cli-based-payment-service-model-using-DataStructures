#include<iostream>
#include "Graph.h"
using namespace Graph;



int main()
{
    
    int loginReg;
    
    graph G;                   // object created
    G.read_data();             // reads login details of reg numbers from Data.txt
    G.initialize_matrix();     // initializes 2D dynamic array
    G.assign_edges();          // randomly assigns edges
    cout<<endl;
    G.check_valid_login();     // displays login screen and checks for valid login details
    G.operations(loginReg);    // calls different options like transactions or balance inquiry
    
    //G.print_matrix();
    //G.display_edges();

    return 0;

}


