class Vehicle {
public:
    // your code here
    Vehicle();
    Vehicle(string, int, float);
    Vehicle(string, int, bool, float);

    void autoPilot(bool onOff);
    void runFDS() const;
    void displayEfficiency() const;
private:
    std::string name;
    int range;
    bool hasFDS;
    float batteryCapacity;
};
