#include <iostream>
using namespace std;

class Car{
    private:
        string model;
    
    public:
        Car(string name) : model(name){}

        void display(){
            cout << model << endl;
        }
};

Car createCar(string name){
    Car c(name);
    return c;
}

int main(){
    Car c = createCar("G 63");
    c.display();
    return 0;
}