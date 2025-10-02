#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <vector>
#include <functional>

#include <iostream>
#include <utils/Tools.h>
#include <dataManagerModels/Books.h>
#include <dataManagerModels/Users.h>
#include <dataManagerModels/Transactions.h>
#include <basicModels/Transaction.h>
#include <basicModels/DateTime.h>

using namespace std;

int main(int argc, char *argv[]) {
    // BuildContext
    // cout << "InitBook\n";
    DataManagerBook dmb = DataManagerBook();
    // cout << "InitUser\n";
    DataManagerUser dmu = DataManagerUser();
    // cout << "InitTrans\n";
    DataManagerTransaction dmt = DataManagerTransaction();
    // cout << "InitContext\n";
    Context context = Context(dmb, dmu, dmt);

    // Application
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("RaLibrary Gui");
    window.resize(1000, 400);

    // ----------------------
    // Main layout
    QHBoxLayout *mainLayout = new QHBoxLayout(&window);

    // Section 1 - Ana butonlar
    QVBoxLayout *section1 = new QVBoxLayout();
    mainLayout->addLayout(section1);

    // Section 2 - Alt butonlar
    QVBoxLayout *section2 = new QVBoxLayout();
    mainLayout->addLayout(section2);

    // Section 3 - Çıktı
    // Section 3 - Çıktı
    QTextEdit *outputLine = new QTextEdit();
    outputLine->setReadOnly(true); 
    outputLine->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->addWidget(outputLine, 1);


    // Section 4 - 5 adet input line edit
    QVBoxLayout *section4 = new QVBoxLayout();
    std::vector<QLineEdit*> inputEdits;
    for (int i = 0; i < 5; ++i) {
        QLineEdit *edit = new QLineEdit();
        edit->setPlaceholderText(QString("Input %1").arg(i+1));
        section4->addWidget(edit);
        inputEdits.push_back(edit);
    }
    mainLayout->addLayout(section4);

    // ----------------------
    // Section 1 buton isimleri
    std::vector<QString> mainNames = {"Login", "Admin Operations", "User Operations"};

    // Section 2 alt buton isimleri
    std::vector<std::vector<QString>> subNames = {
        {"Register Admin","Login Admin","Register User","Login User"},
        {"List Books","Add Book","Change Deposit","List Transactions"},
        {"Deposite Book", "Give Back Book"}
    };
    // Section 2 fonksiyonları - önceden tanımlı
    std::vector<std::vector<std::function<void()>>> subFuncs = {
        {
            [&](){ 
                inputEdits[0]->setPlaceholderText(QString::fromStdString("Name"));
                inputEdits[1]->setPlaceholderText(QString::fromStdString("Surname"));
                inputEdits[2]->setPlaceholderText(QString::fromStdString("Username"));
                inputEdits[3]->setPlaceholderText(QString::fromStdString("Password"));

                if (inputEdits[0]->text().isEmpty() || 
                    inputEdits[1]->text().isEmpty() ||
                    inputEdits[2]->text().isEmpty() ||
                    inputEdits[3]->text().isEmpty()
                ){
                    outputLine->setText("You must fill the 1-2-3-4. spaces.\n1:NAME\n2:SURNAME\n3:USERNAME\n4:PASSWORD"); 
                    return;
                }

                User usr = User(inputEdits[0]->text().toStdString(),
                            inputEdits[1]->text().toStdString(),
                            inputEdits[2]->text().toStdString(),
                            inputEdits[3]->text().toStdString(),1,1);

                context.dataManagerUsers.addItem(usr);
                outputLine->setText("Admin account builded successfully.");

                // remove inputs
                for (auto edt : inputEdits){
                    edt->setText(QString::fromStdString(""));};
                
            },
            [&](){ 
                inputEdits[0]->setPlaceholderText(QString::fromStdString("Name"));
                inputEdits[1]->setPlaceholderText(QString::fromStdString("Surname"));
                inputEdits[2]->setPlaceholderText(QString::fromStdString("Username"));
                inputEdits[3]->setPlaceholderText(QString::fromStdString("Password"));

                if (inputEdits[0]->text().isEmpty() || 
                    inputEdits[1]->text().isEmpty() ||
                    inputEdits[2]->text().isEmpty() ||
                    inputEdits[3]->text().isEmpty()
                ){
                    outputLine->setText("You must fill the 1-2-3-4. spaces.\n1:NAME\n2:SURNAME\n3:USERNAME\n4:PASSWORD"); 
                    return;
                }

                User usr = User(inputEdits[0]->text().toStdString(),
                            inputEdits[1]->text().toStdString(),
                            inputEdits[2]->text().toStdString(),
                            inputEdits[3]->text().toStdString(),1,1);

                bool success = context.dataManagerUsers.login(usr,false);
                if (success){
                    string _text = "Admin Logged: " + usr.get_username();
                    outputLine->setText(QString::fromStdString(_text));
 
                }else {
                    string _text = "Can not logged to account";
                    outputLine->setText(QString::fromStdString(_text));
                }
                // remove inputs
                for (auto edt : inputEdits){
                    edt->setText(QString::fromStdString(""));};
            },
            [&](){
                inputEdits[0]->setPlaceholderText(QString::fromStdString("Name"));
                inputEdits[1]->setPlaceholderText(QString::fromStdString("Surname"));
                inputEdits[2]->setPlaceholderText(QString::fromStdString("Username"));
                inputEdits[3]->setPlaceholderText(QString::fromStdString("Password"));

                if (inputEdits[0]->text().isEmpty() || 
                    inputEdits[1]->text().isEmpty() ||
                    inputEdits[2]->text().isEmpty() ||
                    inputEdits[3]->text().isEmpty()
                ){
                    outputLine->setText("You must fill the 1-2-3-4. spaces.\n1:NAME\n2:SURNAME\n3:USERNAME\n4:PASSWORD"); 
                    return;
                }

                User usr = User(inputEdits[0]->text().toStdString(),
                            inputEdits[1]->text().toStdString(),
                            inputEdits[2]->text().toStdString(),
                            inputEdits[3]->text().toStdString(),1,0);

                context.dataManagerUsers.addItem(usr);
                outputLine->setText("User account builded successfully.");

                // remove inputs
                for (auto edt : inputEdits){
                    edt->setText(QString::fromStdString(""));};
                
            },
            [&](){ 
                inputEdits[0]->setPlaceholderText(QString::fromStdString("Name"));
                inputEdits[1]->setPlaceholderText(QString::fromStdString("Surname"));
                inputEdits[2]->setPlaceholderText(QString::fromStdString("Username"));
                inputEdits[3]->setPlaceholderText(QString::fromStdString("Password"));

                if (inputEdits[0]->text().isEmpty() || 
                    inputEdits[1]->text().isEmpty() ||
                    inputEdits[2]->text().isEmpty() ||
                    inputEdits[3]->text().isEmpty()
                ){
                    outputLine->setText("You must fill the 1-2-3-4. spaces.\n1:NAME\n2:SURNAME\n3:USERNAME\n4:PASSWORD"); 
                    return;
                }

                User usr = User(inputEdits[0]->text().toStdString(),
                            inputEdits[1]->text().toStdString(),
                            inputEdits[2]->text().toStdString(),
                            inputEdits[3]->text().toStdString(),1,1);

                bool success = context.dataManagerUsers.login(usr,false);
                if (success){
                    string _text = "User Logged: " + usr.get_username();
                    outputLine->setText(QString::fromStdString(_text));
 
                }else {
                    string _text = "Can not logged to account";
                    outputLine->setText(QString::fromStdString(_text));
                }
                // remove inputs
                for (auto edt : inputEdits){
                    edt->setText(QString::fromStdString(""));};
            }
        },
        {
            [&](){ 
                string _text = "";
                for (auto item : context.dataManagerBooks.data){
                    _text += item.info() + "\n";
                }
                outputLine->setText(QString::fromStdString(_text));
             },
            [&](){ 
                inputEdits[0]->setPlaceholderText(QString::fromStdString("Name"));
                inputEdits[1]->setPlaceholderText(QString::fromStdString("Author"));
                inputEdits[2]->setPlaceholderText(QString::fromStdString("Isbn"));

                if (inputEdits[0]->text().isEmpty() || 
                    inputEdits[1]->text().isEmpty() ||
                    inputEdits[2]->text().isEmpty()
                ){
                    outputLine->setText("You must fill the 1-2-3."); 
                    return;
                }
                int _isbn;
                try{
                    _isbn = stoi(inputEdits[2]->text().toStdString());
                    throw "ISBN must be numeric";

                }catch(string err){
                    outputLine->setText(QString::fromStdString(err));
                    return;
                };

                Book bk = Book(
                    inputEdits[0]->text().toStdString(),
                    inputEdits[1]->text().toStdString(),
                    _isbn,
                    1);
                context.dataManagerBooks.addItem(bk);

                outputLine->setText(QString::fromStdString("Added book: " + bk.info()));

                // remove inputs
                for (auto edt : inputEdits){
                    edt->setText(QString::fromStdString(""));};
            },
            [&](){ 

                inputEdits[0]->setPlaceholderText(QString::fromStdString("Index"));
                
                int _iidx = 0;
                // List
                for (Book bk: context.dataManagerBooks.data){
                    cout << "[" +std::to_string(_iidx) + "]" + bk.info() + "\n";
                    _iidx += 1;
                };

                // Checks
                if (inputEdits[0]->text().isEmpty() 
                ){
                    outputLine->setText("You must fill the 1"); 
                    return;
                }

                // Choose Index
                int idx;
                try {
                    int idx = stoi(inputEdits[0]->text().toStdString());
                    throw("Index must be integer");
                }catch(string err){
                    outputLine->setText(QString::fromStdString(err)); 
                }

                if(idx < 0 || idx > context.dataManagerBooks.data.size()-1){
                    outputLine->setText(QString::fromStdString("Index must be in interval")); 
                    return;
                }

                context.dataManagerBooks.data[idx].is_depositable = !context.dataManagerBooks.data[idx].is_depositable;
                cout << "\n Book Deposit Changed Successfully!";
                outputLine->setText(QString::fromStdString("Book Deposit Changed Successfully!")); 

                context.dataManagerBooks.save_data();
                // remove inputs
                for (auto edt : inputEdits){
                    edt->setText(QString::fromStdString(""));};

            },
            [&](){
                int _iidx = 0;
                // List
                for (Transaction trs : context.dataManagerTransaction.data){
                    cout << "[" +std::to_string(_iidx) + "]" + trs.show() + "\n";
                    _iidx += 1;
                };
                // remove inputs
                for (auto edt : inputEdits){
                    edt->setText(QString::fromStdString(""));}; 
             }
        },
        {
            [outputLine](){ outputLine->setText("Alt 3-1 tıklandı"); },
            [outputLine](){ outputLine->setText("Alt 3-2 tıklandı"); }
        }
    };

    // Section 2 butonları
    std::vector<std::vector<QPushButton*>> subButtons(subNames.size());
    for (size_t i = 0; i < subNames.size(); ++i) {
        for (size_t j = 0; j < subNames[i].size(); ++j) {
            QPushButton *btn = new QPushButton(subNames[i][j]);
            btn->setVisible(false);
            section2->addWidget(btn);
            subButtons[i].push_back(btn);

            QObject::connect(btn, &QPushButton::clicked, subFuncs[i][j]);
        }
    }

    // Section 1 butonları
    for (size_t i = 0; i < mainNames.size(); ++i) {
        QPushButton *btn = new QPushButton(mainNames[i]);
        section1->addWidget(btn);

        QObject::connect(btn, &QPushButton::clicked, [i, &subButtons]() {
            // Tüm alt butonları gizle
            for (auto &vec : subButtons) {
                for (auto *b : vec) b->setVisible(false);
            }
            // Seçilen ana butonun alt butonlarını göster
            for (auto *b : subButtons[i]) b->setVisible(true);
        });
    }

    
    dmt.save_data();
    dmu.save_data();
    dmb.save_data();
    cout << "Program ended\n";


    window.show();
    return app.exec();
}


