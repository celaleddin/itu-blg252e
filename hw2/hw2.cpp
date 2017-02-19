/***************************************
Student Number : 040130332
Student Name   : Celaleddin Hidayetoglu
Course         : BLG252E
CRN            : 11922
Term           : 2016-Fall
Homework       : #2
***************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Vehicle {
    protected:
        string brand_name;
        int number_of_wheels;
        int number_of_seats;
        int current_location;

    public:
        Vehicle(string brand_name, int number_of_wheels, int number_of_seats);
        void virtual print();
        int virtual drive(int);
};


class Car: public Vehicle {
    private:
        string color;
        int engine_capacity;

    public:
        Car(string brand_name, int number_of_wheels, int number_of_seats, string color, int engine_capacity);
        void print();
};

class Bicycle: public Vehicle {
    public:
        Bicycle(string brand_name, int number_of_wheels, int number_of_seats);
        void print();
        int drive(int);
};

class Motorbike: public Bicycle {
    private:
        int engine_capacity;

    public:
        Motorbike(string brand_name, int number_of_wheels, int number_of_seats, int engine_capacity);
        void print();
};


Vehicle::Vehicle(string brand_name, int number_of_wheels, int number_of_seats) {
    this->brand_name = brand_name;
    this->number_of_wheels = number_of_wheels;
    this->number_of_seats = number_of_seats;
    current_location = 0;
}

Car::Car(string brand_name, int number_of_wheels, int number_of_seats, string color, int engine_capacity): Vehicle::Vehicle(brand_name, number_of_wheels, number_of_seats) {
    this->color = color;
    this->engine_capacity = engine_capacity;

    if (number_of_seats < 4) {
        cout << setw(12);
        cout << right << this->brand_name << " ";
        cout << "---> Constructor Warning: A car can't have " << number_of_seats << " seats." << '\n';
    }

    if (number_of_wheels < 4) {
        cout << setw(12);
        cout << right << this->brand_name << " ";
        cout << "---> Constructor Warning: A car can't have " << number_of_wheels << " wheels." << '\n';
    }
}

Bicycle::Bicycle(string brand_name, int number_of_wheels, int number_of_seats): Vehicle::Vehicle(brand_name, number_of_wheels, number_of_seats) {
    if (number_of_wheels != 2) {
        cout << setw(12);
        cout << right << this->brand_name << " ";
        cout << "---> Constructor Warning: A bicycle/motorbike can't have " << number_of_wheels << " wheel(s)." << '\n';
    }

    if (!(number_of_seats == 1 || number_of_seats == 2)) {
        cout << setw(12);
        cout << right << this->brand_name << " ";
        cout << "---> Constructor Warning: A bicycle/motorbike can't have " << number_of_seats << " seats." << '\n';
    }
}

Motorbike::Motorbike(string brand_name, int number_of_wheels, int number_of_seats, int engine_capacity): Bicycle::Bicycle(brand_name, number_of_wheels, number_of_seats) {
    this->engine_capacity = engine_capacity;
}

int Vehicle::drive(int distance) {
    current_location += distance;

    return current_location;
}

int Bicycle::drive(int distance) {
    if (distance >= 0) {
        current_location += distance;
    }

    else {
        cout << setw(12);
        cout << right << this->brand_name << " ";
        cout << "---> Drive Error: A bicycle/motorbike can't drive " << distance << "." << '\n';
    }

    return current_location;
}

void Vehicle::print() {
    cout << setw(21) << left << brand_name;
    cout << setw(21) << left << number_of_wheels;
    cout << setw(21) << left << number_of_seats;
    cout << setw(21) << left << current_location;
}

void Car::print() {
    cout << setw(18) << right << "Car" << setw(3) << left << ":";
    Vehicle::print();
    cout << setw(21) << left << color;
    cout << setw(21) << left << engine_capacity;
    cout << '\n';
}

void Bicycle::print() {
    cout << setw(18) << right << "Bicycle" << setw(3) << left << ":";
    Vehicle::print();
    cout << '\n';
}

void Motorbike::print() {
    cout << setw(18) << right << "Motorbike" << setw(3) << left << ":";
    Vehicle::print();
    cout << setw(21) << " ";
    cout << setw(21) << left << engine_capacity;
    cout << '\n';
}

int main() {
    Vehicle *vehicles[9];

    cout << "PHASE 1: CONSTRUCTINGS" << "\n\n";

    vehicles[0] = new Car("Car1", 4, 4, "Color1", 1400);
    vehicles[1] = new Car("Car2", 4, 5, "Color2", 1600);
    vehicles[2] = new Car("Car3", 4, 4, "Color3", 1200);
    vehicles[3] = new Car("Car4", 3, 4, "Color4", 1300);
    vehicles[4] = new Car("Car5", 4, 4, "Color5", 1700);

    vehicles[5] = new Bicycle("Bicycle1", 2, 1);
    vehicles[6] = new Bicycle("Bicycle2", 2, 10);

    vehicles[7] = new Motorbike("Motorbike1", 1, 2, 900);
    vehicles[8] = new Motorbike("Motorbike2", 2, 1, 700);

    cout << "\n\n";

    cout << "PHASE 2: DRIVINGS" << "\n\n";

    for (int i = 0; i < 9; i++) {
        vehicles[i]->drive(200);
        vehicles[i]->drive(-50);
    }

    cout << "\n\n";

    cout << "PHASE 3: PRINTINGS" << "\n\n";
    cout << setw(19) << right << "Vehicle Type" << setw(2) << "" << setw(21) << left << "Brand Name"
         << setw(21) << "Num. of Wheels" << setw(21) << "Num. of Seats" << setw(21) << "Current Location"
         << setw(21) << "Color" << setw(21) << "Engine Capacity" << '\n';

    cout << setfill('-') << setw(21*7) << " " << '\n';
    cout << setfill(' ');

    for (int i = 0; i < 9; i++) {
        vehicles[i]->print();
    }

    for (int i = 0; i < 9; i++) {
        delete vehicles[i];
    }

    return 0;
}

