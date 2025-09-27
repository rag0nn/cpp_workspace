#include <iostream>
#include <string>
using namespace std;

class A {

    // herkese açık
    public:
        int age;
        string name;

        // inner func
        void say (){
            cout << "Name: " << name << endl;
        }
        
        // outer func
        void sayOuter();

        // friend member func
        friend void sayId(A aObject);
        // cunstractor
        A(int age_, string name_ ){
          age = age_;
          name = name_;  
        }
        // constractor overloading
        A(){
            age = 20;
            name = "Unknown";
        }

    // sadece class içinde
    private:
        int counter = -1;
    //inherited class'larda kullanabilir
    protected:
        int id;

};

void A::sayOuter (){
    cout << "Outer Decleration";
};
void sayId(A aObject){
    cout << "Id: " << aObject.counter << endl;
};

void tryA(){
    A aObject(25,"Hassani");
    aObject.age = 24;
    aObject.name = "noname";
    aObject.say();

    A aObject2;
    aObject2.say();
    sayId(aObject2);
};


class A2: public A {
    public:
        string title = "This is a A2";
};


class B{
    public:
        string some = "some";
};

class Father: public A2, public B {

};

void tryA2(){
    A2 a2Object;
    a2Object.say();
    Father paps;
    paps.some;
};


// generic functions
template <typename T>
    T add(T a, T b) {
    return a + b;
    }

// generic class
template <typename T>
class Box {
  public:
    T value;
    Box(T v) {
      value = v;
    }
    void show() {
      cout << "Value: " << value << "\n";
    }
};

void otherThings(){

        cout << add<int>(5, 3) << "\n";
        cout << add<double>(2.5, 1.5) << "\n";

};

int main(){
    tryA();
    tryA2();
    otherThings();
    return 0;
}