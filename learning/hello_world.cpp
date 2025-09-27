// for cin cout standdart
#include <iostream>
// for string standart
#include <string>
// for math standart
#include <cmath>
// for dynmaic array standart
#include <vector>

using namespace std;

int main() {
  //
  const string text = "hello world with text";
  cout << text;

  //
  int x;
  cout << "\nsome number: ";
  cin >> x;
  cout << "num: " << x;
  
  // string.char() = string.size()
  string txt = "AK47";
  cout << "\nThe size of the txt string is: " << txt.size();
  cout << "\nThe length of the txt string is: " << txt.length();


  // 
  string text2 = "Hello";
  text2[0] = 'J';
  cout << "\n" <<text2;

  //
  string name;
  cout << "\nYour name: ";
  cin >> name;
  cout << "\nName: " << name; 

  //
  string name2;
  cout << "\nYour name: ";
  getline(cin,name2);
  cout << "Your name is: \n" << name2;


  // embedded math functs
  max(2,3);
  min(2,3);

  // others can be find on <cmath>
  cout << sqrt(64)<<endl;
  cout << round(2.6)<<endl;
  cout << log(2)<<endl;

  // basic condition
  if (false){

  }
  else if (true){
    cout << "wow!"<<endl;
  }
  else {

  }

  // short hand  condition
  (2 > 1) ? cout << "Bigger!"<<endl : cout <<"Lower!"<<endl ;

  // switch
  int a = 1;
  switch (a){
    case 0:
      break;
    case 1:
      cout << "a is 1" <<endl;
      break;
    default:
      //
      cout <<"Switch done"; 
  };

  // loop while
  int i = 0;
  while (i < 5) {
    cout << i << "\n";
    i++;
  }

  // loop for
  for (int i = 0; i <= 10; i = i + 2) {
  cout << i << "\n";
  }

  // loop for each
  int myNumbers[5] = {10, 20, 30, 40, 50};
  for (int num : myNumbers) {
    cout << num << "\n";
  }

  // array
  string cars5[4] = {"Volvo", "BMW", "Ford", "Mazda"};
  string cars6[] = {"Volvo", "BMW", "Ford", "Mazda"};


  // dinamik uznluklu arrayler için vector'ler kullanılır
  vector<string> cars2 = {"Volvo", "BMW", "Ford"};
  cars2.push_back("Tesla");
  
  // get array size
  int nums[] = {1,2,3,4,5};
  sizeof(nums); // -> 20, 4 byte her numara için 
  
  // multi dimensional arrays
  string letters[2][4] = {
    { "A", "B", "C", "D" },
    { "E", "F", "G", "H" }
  };
  
  // structers
  struct {
    int myNum;
    string myString;
  } myStruct1, myStruct2, myStruct3; 

  myStruct1.myNum = 0;
  cout << myStruct1.myNum << endl;

  // named structers
  struct some {
    int nyNum;
    string myString;
  };
  some mysome;
  mysome.myString = "123";
  mysome.nyNum = 1;

  // enums
  enum Level {
    LOW = 25,
    MEDIDUM = 50,
    HIGH = 75
  };

  enum Level mylevel = LOW;

  // references
  string food = "Pizza";
  string &meal = food;

  cout << food << "\n";  // Outputs Pizza
  cout << meal << "\n";  // Outputs Pizza

  // memory adress
  cout << &food;

  // pointers
  string food2 = "Pizza";
  string* ptr = &food2;
  cout << ptr << endl; // --> 0x7ffd290e4c200x7ffd290e4c40
  cout << *ptr << endl; // --> 0x7ffd290e4c200x7ffd290e4c40

  // modify using pointers
  *ptr = "Shavarma";
  cout << *ptr << endl;
  cout << food2 << endl;

  // new and delete keywords: Kendi memory management'ıı kullanabilmek için varlar

  // functionlar'da burada yok
  
  return 0;
}
