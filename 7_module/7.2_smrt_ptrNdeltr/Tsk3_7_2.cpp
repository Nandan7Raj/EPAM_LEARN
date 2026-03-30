//
// Created by NandanRaj on 30-03-2026.
//
#include<iostream>
#include<memory>
#include<string>
class SensorReport {
    int value;
    std::string sensorName;
public:
    SensorReport(int value,std::string sensorName):value(value),sensorName(std::move(sensorName)) {
        std::cout<< "SensorReport for "<<this->sensorName<<" created.\n";
    }
    void displayDetails() const {
        std::cout<<"Sensor Name: "<<sensorName<<", Value: "<<value<<std::endl;
    }
    ~SensorReport() {
        std::cout<<"SensorReport for "<<this->sensorName<<" destroyed\n";
    }
};
int main() {
    int rawSensorValue=75;
    std::string sensorIdentifier="Pressure_A01";
    std::unique_ptr<SensorReport> sensor_report=std::make_unique<SensorReport>(rawSensorValue,sensorIdentifier);
    std::cout << "\nProcessing critical sensor report:" << std::endl;
    sensor_report->displayDetails();

    // std::unique_ptr<SensorReport> copy_sensor_report=sensor_report;// compile time error as unique ptr does not share ownership

    std::cout<<"End of main function\n";
}