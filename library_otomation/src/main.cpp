#include <iostream>
#include <utils/Tools.h>
#include <dataManagerModels/Books.h>
#include <dataManagerModels/Users.h>
#include <dataManagerModels/Transactions.h>
#include <basicModels/Transaction.h>
#include <basicModels/DateTime.h>

using namespace std;



int main(){
    
    // BuildContext
    // cout << "InitBook\n";
    DataManagerBook dmb = DataManagerBook();

    // cout << "InitUser\n";

    DataManagerUser dmu = DataManagerUser();

    // cout << "InitTrans\n";

    DataManagerTransaction dmt = DataManagerTransaction();

    // cout << "InitContext\n";

    Context context = Context(dmb, dmu, dmt);

    // Build Menus
    // Book Menu
    Menu adminMenu = Menu(context,"Book Menu");
    adminMenu.addOption("List Books", [&](){
        cout << "\n--List Books\n";
        context.dataManagerBooks.show(); });
    adminMenu.addOption("Add Book", [&](){
        cout << "\n--Add Book\n";
        Book bk = context.dataManagerBooks.buildBook();
        context.dataManagerBooks.addItem(bk);});
    adminMenu.addOption("Change Deposit", [&](){
        cout << "\n--Change Deposit\n";
        context.dataManagerBooks.changeDepositable(); 
        context.dataManagerBooks.show(); });
    adminMenu.addOption("List Transactions", [&](){
        cout << "\n--List Transactions\n";
        context.dataManagerTransaction.show();
    });

    // User Menu
    Menu accountMenu = Menu(context,"User Menu");
    accountMenu.addOption("Register Admin", [&](){ 
        cout << "\n--Register Admin \n";
        User usr = context.dataManagerUsers.buildUser(1);
        context.dataManagerUsers.addItem(usr);
        ; });
    accountMenu.addOption("Login Admin", [&](){ 
        cout << "\n--Login Admin \n";
        User usr = context.dataManagerUsers.buildUser(1);
        bool suc = context.dataManagerUsers.login(usr)
        ; });
    accountMenu.addOption("Register User", [&](){ 
        cout << "\n--Register User\n";
        User usr = context.dataManagerUsers.buildUser(0);
        context.dataManagerUsers.addItem(usr);
        ; });
    accountMenu.addOption("Login User", [&](){ 
        cout << "\n--Login User\n";
        User usr = context.dataManagerUsers.buildUser(0);
        bool suc = context.dataManagerUsers.login(usr)
        ; });

    // Transaction Menu
    Menu depositMenu = Menu(context, "Transaction Menu");
    depositMenu.addOption("Deposite Book", [&](){
        Transaction trs = dmt.buildTransaction(dmb,dmu);
        dmt.addItem(trs);
    });    

    // Main Menu
    Menu mainMenu = Menu(context,"Main Menu");
    mainMenu.addOption("Login", [&](){ 
        accountMenu.run();
        ; });
    mainMenu.addOption("Admin Operations", [&](){ 
        if(context.dataManagerUsers.isLogin && context.dataManagerUsers.loggedUser.get_flag() == 1){
            adminMenu.run();
        }else{
            cout << "You have'nt got a permission. Must be log in to system with Admin Account" << endl;
        }; });
    mainMenu.addOption("User Operations", [&](){
        if(context.dataManagerUsers.isLogin){
            depositMenu.run();
        }else{
            cout << "You have'nt got a permission. Must be log in to system" << endl;
        };
    });


    // Run Process
    mainMenu.run();
    
    cout << "end";

    return 0;
}