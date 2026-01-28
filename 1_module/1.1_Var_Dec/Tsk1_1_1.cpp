//
// Created by NandanRaj on 27-01-2026.
//

#include <iostream>
using namespace std;

int main()
{
    // ---- Sensor Information ----
    const char sen_type = 'B';       // constant because sensor type does not change
    unsigned int sen_id = 2;        // unsigned because ID cannot be negative

    // ---- Sensor Readings ----
    float temp = 30.5;              // temperature reading
    double hum = 34.675;            // humidity reading
    bool active = true;             // system status (true/false)

    // ---- Additional Data Types ----
    short batteryLevel = 95;        // short (small range is enough)
    long uptimeSeconds = 452300;    // long (bigger value for uptime)
    long long totalPackets = 9823749823LL; // very large count

    // ---- Output Section ----
    cout << "=== Sensor Data Report ===" << endl;

    cout << "Sensor type code     : " << sen_type << endl;
    cout << "Sensor ID            : " << sen_id << endl;

    cout << "Temperature (C)      : " << temp << endl;
    cout << "Humidity level (%)   : " << hum << endl;

    cout << "System status        : "
         << (active ? "Active" : "Inactive") << endl;

    cout << "Battery Level (%)    : " << batteryLevel << endl;
    cout << "Uptime (seconds)     : " << uptimeSeconds << endl;
    cout << "Total Packets Sent   : " << totalPackets << endl;

    return 0;
}
