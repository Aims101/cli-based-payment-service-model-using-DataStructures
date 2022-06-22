#pragma once
#include<fstream>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include "DataStructures.h"

using namespace std;
using namespace DataStructures;


namespace Graph
{
    class vertex             // vertex class to create and store vertexes
    {
        double Balance;
        int VertID;
        string UserName;
        string password;
        
    public:
        

        vertex()
        {
            this->Balance = 0;
            this->VertID = 0;
            this->UserName = " ";
            this->password = " ";
        }

        //get_set functions for the memebers of the class vertex

        void set_balance(double bal)   
        {
            this->Balance = bal;
        }
        void set_VertID(int id)
        {
            this->VertID = id;
        }
        void set_UserName(string name)
        {
            this->UserName = name;
        }
        void set_password(string pass)
        {
            this->password = pass;
        }
        double get_balance()
        {
            return Balance;
        }
        int get_VertID()
        {
            return VertID;
        }
        string get_UserName()
        {
            return UserName;
        }
        string get_password()
        {
            return password;
        }
        

        
    };

    class graph
    {
        
        List<vertex> verteces;          // vector/List stroes the vertexs
        int **edgeMatrix;               // 2D dynamic array to stores edges
    public:
        

        graph()
        {
            
            
        }
        // get_set functions of members of the class graph

        List<vertex>& get_vector()
        {
            return this->verteces;
        }
        
        vertex& get_vertex(int reg)
        {
            return verteces[vertex_loc(reg)];
        }
        int** get_matrix()
        {
            return edgeMatrix;
        }

        void add_vertex(double bal, int id, string name,string pass)     // adds the 
        {
            vertex V;
            V.set_balance(bal);
            V.set_VertID(id);
            V.set_UserName(name);
            V.set_password(pass);
            verteces.push_back(V);
            //cout<<"vector size after adding verteces: "<<verteces.get_size()<<endl;
        }
        void initialize_matrix()      // initializes 2D dyanmic array to store edges
        {
            edgeMatrix = new int*[verteces.get_size()];
            for(int i=0; i<verteces.get_size(); i++)
            {
                edgeMatrix[i] = new int [verteces.get_size()];
            }
            
            for(int i=0; i<verteces.get_size(); i++)
            {
                for(int j=0;j<verteces.get_size();j++)
                {
                    edgeMatrix[i][j] = 0;
                }
            }
        }
        void add_edges(int reg1,int reg2)       // adds edges by assigning value of 1 at the memory corresponding to te both verteces
        {
            
            if(vertex_loc(reg1) == vertex_loc(reg2))
            {
                cout<<"Cant make an edge"<<endl;
                
            }
            else
            {
                edgeMatrix[vertex_loc(reg1)][vertex_loc(reg2)] = 1;
                cout<<"edge added\n";
            }
       
        }
        void print_matrix()    // prints edge matrix
        {
            for(int i=0; i<verteces.get_size(); i++)
            {
                for(int j=0;j<verteces.get_size();j++)
                {  
                    
                    cout<<edgeMatrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        void display_edges()          // displays which verteces are connected by edges
        {
            for(int i=0; i<verteces.get_size(); i++)
            {
                
                for(int j=0;j<verteces.get_size();j++)
                {  
                    
                    if(edgeMatrix[i][j] == 1)
                    {
                        cout<<"vertex: "<<verteces[i].get_VertID()<<"<-->"<<"vertex: "<<verteces[j].get_VertID()<<endl;
                    }
                }
            }
        }

        
        void display_verteces()          // displays stored verteces and their data
        {
            cout<<"Verteces display:\n";
            for(int i=0;i<verteces.get_size();i++)
            {
                cout<<"vertex : "<<i<<endl;
                cout<<verteces[i].get_balance()<<endl;
                cout<<verteces[i].get_VertID()<<endl;
                cout<<verteces[i].get_UserName()<<endl;
                cout<<endl;
            }

        }
        int vertex_loc(int reg)         // returns the Vertex number in the List/vector
        {
            for(int i=0;i<verteces.get_size();i++)
            {
                if(reg == verteces[i].get_VertID())
                {
                    return i;
                    
                }
            }
            cout<<"Regno does not exist"<<endl;
            return -1;
        }
        void check_valid_login()         // displays the login page and validates the login details provided by the user
        {
            
            int loginReg;
            string password;
            string name;
            int choice;
            bool loginFlag = false;
            bool endflag =false;
            while(endflag == false)
            {
                system("clear");
                cout<<"###########################################################################"<<endl;
                cout<<"                            GIKIPay                                        "<<endl;
                cout<<"###########################################################################"<<endl;
                cout<<">>>>>>>>LOGIN/SIGN-UP<<<<<<<<<<"<<endl;
                cout<<">>>>Press 1: To Login "<<endl;
                cout<<">>>>Press 2: To SignUp "<<endl;
                cout<<">>>>Press 3: To Exit "<<endl;
                cin>>choice;
                system("clear");
                if(choice == 1)
                {
                    
                    cout<<"Enter your RegNo: ";
                    cin>>loginReg;
                    cout<<"Enter your Password: ";
                    cin>>password;

                    for(int i=0;i<verteces.get_size();i++)
                    {
                        if(loginReg == verteces[i].get_VertID() && password == verteces[i].get_password())
                        {
                            loginFlag = true;
                            endflag = true;
                            cout<<"Login Successful"<<endl;
                            
                        }
                        
                        
                    }
                    system("clear");
                    if(loginFlag == true)
                    {
                        operations(loginReg);
                    }
                    else
                    {
                        cout<<"\nInvalid Login!\nTry again or Sign up first to use the system"<<endl;
                    }
                }
                system("clear");
                if(choice == 2)
                {
                    sign_up();
                }
                system("clear");
                if(choice == 3)
                {
                    endflag = true;
                }
                
                if(choice != 1 && choice != 2 && choice != 3)
                {
                    cout<<"Enter a valid option";
                }
                
            }
            
        }    
        void sign_up()        // displays the sign up screen and stores the new details in the Data.txt file
        {
            int reg;
            string pass;
            string name;
            double bal = 0.0;
            ofstream addUser;
            addUser.open("Data.txt", ios::app);
            cout<<"\nEnter your RegNo: ";
            cin>>reg;
            cout<<"\nEnter your name: ";
            cin>>name;
            cout<<"\nEnter your password: ";
            cin>>pass;

            addUser<<bal<<"\n"<<reg<<"\n"<<name<<"\n"<<pass;

            addUser.close();

        }
        void operations(int Lreg)            // displays the available opertaions screen and directs towards the selected option
        {
            int Ochoice;
            bool O_flag = false;
            while(O_flag != true)
            {
                cout<<"Press 1: To make a transaction "<<endl;
                cout<<"Press 2: for Balance inquiry "<<endl;
                cout<<"Press 3: To search the graph"<<endl;
                cout<<"Press 4: To go back"<<endl;
                cin>>Ochoice;
                if(Ochoice == 1)
                {
                    trans_options(Lreg);      // redirects towards the transactions screen 
                    
                }
                if(Ochoice == 2)
                {
                    balanceInquiry(Lreg);        // call to the balance inquiry function
                }
                if(Ochoice == 3)
                {
                    int dest;
                    cout<<"Entr the reg of dest vertex"<<endl;
                    cin>>dest;
                    
                    
                    BFS(Lreg ,dest);

                }
                if(Ochoice == 4)
                {
                    O_flag = true;
                    break;
                }
                if(Ochoice != 1 && Ochoice != 2 && Ochoice != 3 && Ochoice !=4)
                {
                    cout<<"Enter a valid choice"<<endl;
                }

            }
            system("clear");
            
        }
        void balanceInquiry(int reg)         // Displays the balance of the Loged in user
        {
            system("clear");
            time_t currtime = time(NULL);
            cout<<"Balance Inquiry:"<<endl;
            cout<<"Remaining balance as of "<<ctime(&currtime)<<"is: "<<verteces[vertex_loc(reg)].get_balance()<<endl;
            system("clear");
        }
        
        void trans_options(int reg)        // displays different transaction options 
        {
            int Tchoice;
            bool Tflag = false;
            while(Tflag == false)
            {
                system("clear");
                
                cout<<"Press 1: To Send payment"<<endl;
                cout<<"Press 2: To reciece payment"<<endl;
                cout<<"Press 3: To go back"<<endl;
                cin>>Tchoice;
                if(Tchoice == 1)
                {
                    system("clear");
                    ofstream TransHistory;                                           // fstream variable declaration to store transaction history
                    TransHistory.open("transactionHistory.txt", ios::in | ios::app);   // accessess the transactionHistory.txt to append it for every transaction made 
                    time_t currtime = time(NULL);
                    srand(time(0));
                    int Rreg;
                    double transAmount;
                    cout<<"Enter the receiever`s regno: ";
                    cin>>Rreg;
                    cout<<endl;
                    cout<<"Enter the Amount: ";
                    cin>>transAmount;
                    cout<<endl;
                    int transactionCount = 0;                   // variable declaration to create a unique transaction id
                    while(transactionCount<1000)                    // loop stores transaction id only greater then 1000
                    {
                        transactionCount = rand()%10000;
                    }
                    
                    
                    if(transAmount > verteces[vertex_loc(reg)].get_balance())     // checks if the users has sufficient balance to make the transaction
                    {
                        cout<<"insufficient Balance"<<endl;
                    }
                    else{

                        int RecieverVert = BFS(reg,Rreg);                  // BFS() called to search for the desired vertex
                        if (RecieverVert < 0)                              // checks if the destination vertex was found by BFS or not
                        {
                            cout<<"Reg no is not in the system"<<endl;
                            break;
                        }
                        else{
                            verteces[vertex_loc(reg)].set_balance(verteces[vertex_loc(reg)].get_balance() - transAmount) ;
                            verteces[RecieverVert].set_balance(verteces[RecieverVert].get_balance() + transAmount) ;
                            cout<<"Transcation Successful"<<endl;
                            transactionCount++;
                            TransHistory<<"Transaction ID: "<<transactionCount<<endl;
                            TransHistory<<"Amount: "<<transAmount<<"\nSenders RegNo: "<<verteces[vertex_loc(reg)].get_VertID()<<"\nRecievers RegNo: "<<verteces[RecieverVert].get_VertID()<<endl;
                            TransHistory<<"At time "<<ctime(&currtime)<<endl<<endl;
                            update_vertex_data(verteces);
                        }
                        
                        
                    }

                    TransHistory.close();
                }
                if(Tchoice == 2)
                {
                    system("clear");
                    ofstream TransHistory;                                             // fstream variable to store transaction history
                    TransHistory.open("transactionHistory.txt", ios::in | ios::app);    // opens transactionHistory.txt
                    time_t currtime = time(NULL);
                    srand(time(0));
                    int Sreg;
                    double transAmount;
                    cout<<"Enter the Sender`s regno: ";
                    cin>>Sreg;
                    cout<<endl;
                    int transactionCount = 0;
                    while(transactionCount<1000)
                    {
                        transactionCount = rand()%10000;
                    }
                    

                    
                    int SendersVert = BFS(reg,Sreg);       // called to search for the destination vertex
                    if(SendersVert < 0)
                    {
                        cout<<" Reg No not in the system"<<endl;
                    }
                    else{
                        do
                        {
                            transAmount = (rand()%abs(int(verteces[SendersVert].get_balance())));        //randomly assigna a transaction amount 
                            
                        }while(transAmount > verteces[SendersVert].get_balance());
                        cout<<transAmount<<endl;

                        verteces[vertex_loc(reg)].set_balance(verteces[vertex_loc(reg)].get_balance() + transAmount);
                        verteces[SendersVert].set_balance(verteces[SendersVert].get_balance() - transAmount);
                        
                        cout<<"Transcation Successful"<<endl;
                        transactionCount++;
                        TransHistory<<"Transaction ID: "<<transactionCount<<endl;
                        TransHistory<<"Amount: "<<transAmount<<"\nSenders RegNo: "<<verteces[SendersVert].get_VertID()<<"\nRecievers RegNo: "<<verteces[vertex_loc(reg)].get_VertID()<<endl;
                        TransHistory<<"At time "<<ctime(&currtime)<<endl<<endl;
                        update_vertex_data(verteces);
                        TransHistory.close();
                    }

                }
                if(Tchoice == 3)
                {
                    Tflag =true;
                }
                
                    
            }
            
            
        }
        void update_vertex_data(List<vertex> &v)            // updates the vertex list/vector s data
        {
            ofstream updateData;
            updateData.open("Data.txt", ios::out);

            for(int i=0; i<verteces.get_size();i++)
            {
                updateData<<verteces[i].get_balance()<<"\n"<<verteces[i].get_VertID()<<"\n"<<verteces[i].get_UserName()<<"\n"<<verteces[i].get_password()<<"\n"<<endl;
                
            }
            cout<<"data updated"<<endl;
            updateData.close();
        }
        void read_data()          // accesses the Data.txt file to read the vertex data
        {
            int reg;
            string name;
            double bal;
            string pass;

            bool flag = true;
            ifstream infile;
            infile.open("Data.txt", ios::in | ios::out);
            
            while(true)
            {
                infile>>bal>>reg>>name>>pass;
                //cout<<bal<<" "<<reg<<" "<<name<<endl;

                if(infile.eof() == true)
                    break;
                else
                    add_vertex(bal,reg,name,pass);
                
                
            }
            
            infile.close();
        }
        void assign_edges()        //randomly assigns edges
        {
            srand(time(0));
            for(int i=0; i<verteces.get_size(); i++)
            {
                for(int j=0;j<verteces.get_size();j++)
                {
                    edgeMatrix[i][j] = rand()%2;
                }
            }

        }
        int BFS(int srcVertexReg, int destVertexReg)            // breath first search to find destination vertex to make transactions
        {
            int srcVertloc = vertex_loc(srcVertexReg);
            int destVertloc = vertex_loc(destVertexReg);
            bool found = false;
            bool *visited = new bool[verteces.get_size()];
            
            //int *Queue = new int[verteces.get_size()];
            //int Q_slots = verteces.get_size() - 1;
            
            for(int i = 0; i < verteces.get_size(); i++)
            {
                visited[i] = false;
                
            }
            List<int> Queue;
            
            visited[srcVertloc] = true;
            Queue.push_back(srcVertloc);
            
            while(Queue.is_empty()!= true)
            {
                
                int currVertex = Queue.front();
                cout << "Visited " << verteces[currVertex].get_VertID() << " ";
                if(currVertex == destVertloc)
                {
                    cout<<"Vertex found:"<<endl;
                    //cout<<verteces[destVertloc].get_balance()<<endl;
                    //cout<<verteces[destVertloc].get_VertID()<<endl;
                    //cout<<verteces[destVertloc].get_UserName()<<endl;
                    return currVertex;
                    found = true;
                    break;
                }
                Queue.pop_front();
                
                for(int j = 0; j < verteces.get_size(); j++)
                {

                    if(edgeMatrix[currVertex][j] == 1)
                    {
                        int adjVertex = j;
                        if(visited[adjVertex] != true)
                        {
                            visited[adjVertex] = true;
                            Queue.push_back(adjVertex);
                        }
                    }
                    
                    
                }
            }
            if (found == false)
            {
                return -1;
            }
            
            

            

        }

        
    };
}
