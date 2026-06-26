#include <iostream>
using namespace std;

class TrafficSignal{
private:
    string signalID;
    string location;
protected:
    int greenDuration;
    int redDuration;
//helper function for display status function to avoid extra lines of code
    const void print() const {
        cout <<"Signal ID: "<<this->get_signalID()<<"\n"
        <<"Location: "<<this->get_location()<<"\n"
        <<"Green Duration: "<<this->get_greenDuration()<<"\n"
        <<"Red Duration: "<<this->get_redDuration()<<endl;
    }
public:
//======Constructor
    TrafficSignal(string id, string lcn, int gd, int rd)
    : signalID(id), location(lcn), greenDuration(gd), redDuration(rd){}
//====== Virtual Destructor
    virtual ~TrafficSignal() = default;
//======Pure Virtual Function make this class abstract 
    virtual void displayStatus() const = 0;
//======All Getter Functions
    const string& get_signalID()const{return signalID;} 
    const string& get_location()const{return location;}
    
    const int get_greenDuration()const{return greenDuration;}
    const int get_redDuration()const{return redDuration;}
};

class VehicleSensorSignal : public TrafficSignal{
private:
    int vehicleCount;
public:
//======Constructor 
    VehicleSensorSignal(string id, string lcn, int gd, int rd, int vc) 
    : TrafficSignal(id, lcn, gd, rd), vehicleCount(vc){}

//======Overriding Display status function
    void displayStatus() const override{
        cout << "Vehicle Sensor Signal Information \n";
        TrafficSignal::print();    
        cout <<"Vehicle Count: "<<this->vehicleCount<<endl;
    };
//======Function to Calculate Efficiency
   float calculateEfficiency() {
        float green = get_greenDuration();
        float total = green + get_redDuration();
        return (total == 0.0f) ? 0.0f : (green / total) * 100.0f;
    }
};

class PedestrianSensorSignal : public TrafficSignal{
private:
    int PedestrianCount;
    bool emergencyMode;
public:
//======Constructor
    PedestrianSensorSignal(string id, string lcn, int gd, int rd, int pdc,bool em)
    : TrafficSignal(id, lcn, gd, rd), PedestrianCount(pdc), emergencyMode(em){}
//======Overriding display status
    void displayStatus() const override {
        cout <<"Pedestrian Sensor Signal Information \n";
        TrafficSignal::print();
        cout <<"Pedestrian Count: "<<this->PedestrianCount<<"\n"
        <<"Emergency Mode: " << (this->emergencyMode ? "True" : "False") << endl;

    }

//function to acess protected adta member greenDuration
    const int getGreenDuration() const {
        return this->greenDuration;
    }
};

int main(){
    VehicleSensorSignal VSS("V771", "Main Street", 60, 40, 25);
    PedestrianSensorSignal PSS("P771", "Central Park", 50, 60, 30, true);
    
    VSS.displayStatus();
    cout<<endl;
    
    PSS.displayStatus();
    cout<<endl;

    cout << "Signal Efficiency: " << VSS.calculateEfficiency() << "%" << endl;
    cout <<"Green Duration of Pedestrian Signal: " <<PSS.getGreenDuration()<<endl;

    return 0;
}