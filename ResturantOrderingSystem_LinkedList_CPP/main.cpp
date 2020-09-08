/**********************************************************************
 * File:Assign1.cpp
 * Author: Noah Alharbi 
 * to: Mrs Liu Huizhu 
 * Created on January 15, 2017, 3:11 PM
 * editted: January 15, 16, 18, 20, 22, 23, 24, 2017 
 * 
 * Purpose: this is a fast_food ordering menu that assigns a number to 
 * every new order. the program contains the following featuers: 
 * submiting a new order, serving an order, terminating if the list is
 * empty
 *
 **********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
//#include "Load_Orders.h"

using namespace std;
class Orders_List {  
 
  public:
    int options_num;   
    struct save_info {
        string name ; 
        float price ; 
        save_info* Next ; 
    }; 

    save_info* burger_head = new save_info ();
    save_info* side_head = new save_info (); 
    save_info* drink_head = new save_info ();
    save_info* move_choice = new save_info(); 
  
void Load_menus (string which_file, save_info* select_options ) { 
    select_options->Next = NULL;
    select_options->name = which_file;
    string temprary_name;
    float temprary_price;
    save_info *temp;
    save_info *link = select_options;
    ifstream info_file;
        info_file.open (which_file.c_str());
    if (!info_file.is_open()) { 
            cout <<"can't open, error reading the file"<<endl; 
    } else{
    int i = 0;
    info_file >> options_num ;
    info_file.ignore(1,'\n');
        while (i<=options_num) {
                temp = new save_info();
                getline (info_file, temprary_name);
                temp ->name = temprary_name;
                info_file >> temprary_price ;
                temp -> price = temprary_price; 
                temp ->Next = NULL ; 
                info_file.ignore(1,'\n');
                i++;
                link ->Next = temp ;
                link = temp;
               }
    }
}

void welcome_page () {
    cout <<" ====================================================== " <<endl;
    cout <<" WELCOME TO THE FAST FOOD ORDERING SYSTEM "<<endl;     
    }

void display_orders (save_info* select_options) { 
    save_info* move_display;
            cout <<"please enter the number of the desired choice: " << endl;
    move_display = select_options ->Next; 
    int i = 1;
    while (move_display->Next != NULL) { 
            cout << i <<"." << move_display ->name << " " << move_display ->price << "$" << endl; 
            i++; 
            move_display = move_display->Next; 
            }
    cout << i << ".none of the above" << endl; 
}        

void user__choice (int choice__num, save_info* select_options) {
    string order;
    if (choice__num <= options_num) {    
        move_choice = select_options ->Next;
        for (int i = 1; i<choice__num ; i++) {
        move_choice = move_choice->Next;
    }
        cout << "you chose: " << move_choice ->name <<endl;
    } else{ 
        cout <<"invalid choice! please make a choice within the menu"<<endl ;
    } return; 
}
};

class Orders {
  public:
struct Node {
    string Burger ; 
    string Side ;
    string Drink ; 
    int Order_Tracker ; 
    float Burger_price;
    float Side_price;
    float Drink_price;
    Node* Next ; 
};
// declaration of global varibles 
    Node* temp = new Node;
    Node* head = NULL;
    int Order_Num;
    int Order_Count=0;
    float Price_tracker = 0;
    float initial_price;
    float Total_price ;
    float temp_burger_price;
    float temp_side_price;
    float temp_drink_price; 
    string Burger_Choice;     
    string Side_Choice;
    string Drink_Choice ; 
    char User_Choice ;  
    
// the help function that displays menu options
void Help () { 
	cout << "======================================================="<<endl;
	cout <<"please chose an option from the following:" <<endl; 
	cout <<" 'N' to place a new order" <<endl; 
	cout <<" 'S' to serve the order" <<endl; 
	cout <<" 'V' to view all orders" <<endl;
	cout <<" 'T' to quit " <<endl; 
	cout <<" 'H' for help" <<endl;
	cout <<"========================================================"<<endl;
}

//function to delete the node at the begining of the list. "the oldest order" 
void Free_Varible(){
    Node* free = new Node();
// starting at the beginning of the list
    free = head ; 
    if (free != NULL) { 
        cout <<"================================================" <<endl; 
        cout << "Order number: "<< free-> Order_Tracker << endl;
        cout <<"Order Consists of: " <<endl;
        cout << "for the burger: " << free ->Burger << endl;  
        cout << "for the side: " << free ->Side <<endl; 
        cout << "for the drink: " << free ->Drink <<endl; 
        cout << " \n " <<endl; 
        cout << " ORDER SERVED " <<endl;         
        cout <<"================================================" <<endl;
// linking the head to the second node and deleting the first node 
    head = head->Next; 
    delete free ; 
    } else{
	cout << " list is empty! " <<endl ; 
        }
}

// function to create and insert user's order data in the linked list  
void New_Order (string Burger_Choice, string Side_Choice, string Drink_Choice, float temp_burger_price, float temp_side_price, float temp_drink_price) { 
    temp -> Burger = Burger_Choice;
    temp -> Burger_price = temp_burger_price;
    temp -> Side = Side_Choice;
    temp -> Side_price = temp_side_price; 
    temp -> Drink = Drink_Choice;
    temp -> Drink_price = temp_drink_price; 
    temp -> Order_Tracker = Order_Num;
    temp -> Next = NULL ;
    Node* link = temp;
    float add_tax; 
// previous order number + 1 
    Order_Num++;
    Order_Count ++ ; 
    link = temp ; 
    if (head == NULL ){
	head = temp ;
      }
    temp = new Node(); 
    link -> Next = temp;
// making "temp" point at a new node and making "link" follow it    
    initial_price = link->Burger_price + link->Side_price + link->Drink_price;
    add_tax = initial_price * 0.05 ;
    Total_price = initial_price + add_tax; 
    Price_tracker = Total_price+ Price_tracker ; 
// displaying order information 
        cout <<"================================================" <<endl;
        cout <<"your order consisits of " << endl;
	cout << "for burger: " << link-> Burger << endl;
       	cout << "for the side: " << link -> Side << endl; 
	cout << "for the drink: " << link ->Drink << endl;
	std::cout << "your total is " << std::fixed << std::setprecision(2) << Total_price << "$"<< endl; 
        cout <<"your order number is " <<endl;
	cout << link->Order_Tracker << endl;
	cout <<"================================================" <<endl;		
}
// function to exit the program " if the list is empty"
int Terminate (){ 
    Node* terminate = new Node();
    terminate = head; 
    if(terminate!= NULL){
        cout <<"Sorry can not terminate! there are unserved orders"<<endl;
    }else{
        cout <<"Total of orders served for today is: " << Order_Count <<endl ; 
        cout <<"Total sales for today was: " << Price_tracker << "$" <<endl ;
        cout << "SHUTTING DOWN!" <<endl;  
        Order_Num = 999; 
     return (Order_Num); 
    }
    return (0);  
}


void display_order_info(){
// start from the begining of the list
    Node* display = head;
// a loop to display all data in the linked list one after the other 
    if (display != NULL) { 
       while (display!=NULL) {
        cout <<"================================================" <<endl; 
        cout <<"Order number: " << display ->Order_Tracker << endl; 
        cout <<"Order Consists of: " <<endl;
        cout <<"for the burger: " << display ->Burger << endl;  
        cout <<"for the side: " << display ->Side <<endl; 
        cout <<"for the drink: " << display ->Drink <<endl;
        cout <<"================================================" <<endl; 
        display = display->Next ;
        }
    return;        		 	     	
    }else{
    // in case the list is empty 
          cout << "the list is empty " << endl; 
       }
}
 
};    
int main(){
   int choice__num; 
   Orders_List load_access ;    
   Orders orders_access ; 
   orders_access.Order_Num = 100;
   load_access.welcome_page();
   orders_access.Help ();
   
   while (orders_access.Order_Num < 999){
    cout <<"Please enter your choice from the given menu "<<endl; 
    cin >> orders_access.User_Choice ;
    cin.ignore(256, '\n');
   
   if (orders_access.User_Choice == 'H' || orders_access.User_Choice == 'h'){
    orders_access.Help ();
   }else if (orders_access.User_Choice == 'V' || orders_access.User_Choice == 'v'){ 
    orders_access.display_order_info();
    orders_access.Help(); 
    }else if (orders_access.User_Choice == 'S' || orders_access.User_Choice == 's'){
    orders_access.Free_Varible ();
    orders_access.Help (); 
    }else if (orders_access.User_Choice == 'T' || orders_access.User_Choice == 't'){ 
    orders_access.Terminate ();  
    }else if (orders_access.User_Choice== 'N' || orders_access.User_Choice== 'n'){ 
 
    load_access.Load_menus("burgers.txt", load_access.burger_head ) ; 
    load_access.Load_menus("sidedish.txt", load_access.side_head) ; 
    load_access.Load_menus("drinks.txt", load_access.drink_head) ;

       
    load_access.display_orders(load_access.burger_head);
    cin >> choice__num; 
    load_access.user__choice(choice__num, load_access.burger_head);
    orders_access.Burger_Choice = load_access.move_choice->name ;
    orders_access.temp_burger_price = load_access.move_choice->price ;
    
    load_access.display_orders(load_access.side_head);
    cin >> choice__num;
    load_access.user__choice(choice__num, load_access.side_head);
    orders_access.Side_Choice = load_access.move_choice->name ;
    orders_access.temp_side_price = load_access.move_choice->price ;
     
    load_access.display_orders(load_access.drink_head);
    cin >> choice__num; 
    load_access.user__choice(choice__num, load_access.drink_head);
    orders_access.Drink_Choice = load_access.move_choice->name ;
    orders_access.temp_drink_price = load_access.move_choice->price ;
    
    orders_access.New_Order (orders_access.Burger_Choice, orders_access.Side_Choice, orders_access.Drink_Choice, orders_access.temp_burger_price, orders_access.temp_side_price, orders_access.temp_drink_price); 
    }else { cout << "invalid choice" << endl ;
    orders_access.Help (); 
   }
   }
} 
