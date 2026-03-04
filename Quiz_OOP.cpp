#include<iostream>
using namespace std;
class SmartRide
{
    protected:
    string passengerName;
    int rideID;
    double baseFare;
    double distance;
    public:
    SmartRide(string Name, int id, double bfare, double d)
    {
        passengerName = Name;
        rideID = id;
        baseFare = bfare;
        distance = d;

    }
    virtual double calculateFare(double baseFare, double distance, double serviceCharge) {}
    virtual void Display(){}
};
class EconomyRide: public SmartRide
{
    public:
EconomyRide(string name, int id, double basefare1,double distancekm): SmartRide(name, id, basefare1, distancekm){}
    int finalfare = 0;
    double calculateFare(double baseFare, double distance, double serviceCharge )override{
         finalfare = baseFare + (distance*8);
        return finalfare;
    }
    void Display()override{
        cout<<"Passenger Name: "<<passengerName<<endl;
        cout<<"Ride ID: "<<rideID<<endl;
        cout<<"Final Fare: "<<finalfare<<endl;
    }


};
class LuxuryRide: public SmartRide{
    protected:
    double servicecharge;
    public:
    LuxuryRide(string name, int id, double basefare1,double distancekm): SmartRide(name, id, basefare1, distancekm){}
    int finalfare;
    double calculateFare(double baseFare, double distance, double serviceCharge )override{
        finalfare = baseFare + (distance*12) + serviceCharge;
        return finalfare;
    }
    void Display()override{
        cout<<"\nPassenger Name: "<<passengerName<<endl;
        cout<<"Ride ID: "<<rideID<<endl;
        cout<<"Final Fare: "<<finalfare<<endl;
    }
    

};
main()
{
    EconomyRide e1("sara", 201, 100,15);
    e1.calculateFare(100,15,0);
    e1.Display();
    LuxuryRide l1("Hassaan", 305, 120, 10);
    l1.calculateFare(120,10,80);
    l1.Display();
    
}