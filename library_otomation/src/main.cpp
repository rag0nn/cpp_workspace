#include <iostream>
#include <utils/Tools.h>
#include <dataManagerModels/Books.h>
#include <dataManagerModels/Users.h>

using namespace std;



int main(){
    
    // BuildContext
    DataManagerBook dmb = DataManagerBook();
    DataManagerUser dmu = DataManagerUser();

    Context context = Context(dmb, dmu);

    // Build Menus

    // Book Menu
    Menu bookMainMenu = Menu(context,"Book Menu");
    bookMainMenu.addOption("List Books", [&](){
        cout << "\n--List Books\n";
        context.dataManagerBooks.show(); });
    bookMainMenu.addOption("Add Book", [&](){
        cout << "\n--Add Book\n";
        Book bk = context.dataManagerBooks.buildBook();
        context.dataManagerBooks.addItem(bk);});
    bookMainMenu.addOption("Change Deposit", [&](){
        cout << "\n--Change Deposit\n";
        context.dataManagerBooks.changeDepositable(); 
        context.dataManagerBooks.show(); });

    // User Menu
    Menu userMainMenu = Menu(context,"User Menu");
    userMainMenu.addOption("Admin Register", [&](){ 
        cout << "\n--Admin Register\n";
        User usr = context.dataManagerUsers.buildUser(1);
        context.dataManagerUsers.addItem(usr);
        ; });
    userMainMenu.addOption("User Register", [&](){ 
        cout << "\n--User Register\n";
        User usr = context.dataManagerUsers.buildUser(0);
        context.dataManagerUsers.addItem(usr);
        ; });
    userMainMenu.addOption("Admin login", [&](){ 
        cout << "\n--Admin Login\n";
        User usr = context.dataManagerUsers.buildUser(1);
        bool suc = context.dataManagerUsers.login(usr)
        ; });
    userMainMenu.addOption("User login", [&](){ 
        cout << "\n--User Login\n";
        User usr = context.dataManagerUsers.buildUser(0);
        bool suc = context.dataManagerUsers.login(usr)
        ; });

    // Main Menu
    Menu mainMenu = Menu(context,"Main Menu");
    mainMenu.addOption("Login", [&](){ 
        userMainMenu.run();
        ; });
    mainMenu.addOption("Admin Operations", [&](){ 
        if(context.dataManagerUsers.isLogin){
            bookMainMenu.run();

        }else{
            cout << "You have'nt got a permission. Must be log in to system" << endl;
        }; });


    // Run Process
    mainMenu.run();
    
    cout << "end";

    return 0;
}