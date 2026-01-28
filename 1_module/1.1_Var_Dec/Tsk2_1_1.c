//
// Created by NandanRaj on 27-01-2026.
//

#include <stdio.h>
#include <stdbool.h>  // C99+ boolean support

// ---- Sensor mode/status flags (bit masks) ----
// Using individual bits lets you combine multiple states efficiently.
enum {
    MODE_ACTIVE      = 0x01, // Device is active
    MODE_LOW_POWER   = 0x02, // Low power mode
    MODE_ERROR       = 0x04, // Error condition
    MODE_CALIBRATING = 0x08  // Calibration in progress
};

int main(void)
{
    //Environmental Data Logger Setup

    // Primitive configuration/state
    char   sensorRegionCode        = 'N';         // Region: N/S/E/W
    int    currentReadingID        = 101;         // Current sensor reading ID
    float  avgSoilMoisture         = 45.7f;       // Soil moisture percentage
    double preciseLightIntensity   = 1234.56789;  // Light intensity (lumens)
    short  temperatureCelsius      = 27;          // Temperature (°C)
    long   totalReadingsCollected  = 150000L;     // Total readings logged
    unsigned int serverThreshold   = 500;         // Threshold for server upload

    // Logical state → use bool
    bool isConnected               = true;        // Simple true/false state
    bool hasRecentUpdate           = false;       // Another boolean example

    // Mode as bit‑flags → use unsigned char
    unsigned char sensorModeFlags  = 0x00;

    // Initialize flags: active + low power (example combination)
    sensorModeFlags |= MODE_ACTIVE;
    sensorModeFlags |= MODE_LOW_POWER;

    // Clear a flag example (ensure not in error mode)
    sensorModeFlags &= (unsigned char)~MODE_ERROR;

    // Toggle a flag example (simulate calibration start/stop)
    sensorModeFlags ^= MODE_CALIBRATING; // start calibration
    // ... later:
    sensorModeFlags ^= MODE_CALIBRATING; // stop calibration


       //Output Section

    printf("=== Environmental Data Logger Report ===\n\n");

    printf("Sensor Region Code           : %c\n", sensorRegionCode);
    printf("Current Reading ID           : %d\n", currentReadingID);
    printf("Average Soil Moisture (%%)    : %.2f\n", avgSoilMoisture);
    printf("Light Intensity (lumens)     : %.5f\n", preciseLightIntensity);
    printf("Temperature (Celsius)        : %hd\n", temperatureCelsius);
    printf("Total Readings Collected     : %ld\n", totalReadingsCollected);
    printf("Server Threshold (readings)  : %u\n", serverThreshold);

    // Booleans printed as human-friendly text
    printf("Connectivity                 : %s\n", isConnected ? "Connected" : "Disconnected");
    printf("Recent Update Present        : %s\n", hasRecentUpdate ? "Yes" : "No");

    // Flags printed as hex and decoded
    printf("Sensor Mode Flags            : 0x%02X\n", sensorModeFlags);
    printf(" - Active                    : %s\n", (sensorModeFlags & MODE_ACTIVE) ? "Yes" : "No");
    printf(" - Low Power                 : %s\n", (sensorModeFlags & MODE_LOW_POWER) ? "Yes" : "No");
    printf(" - Error                     : %s\n", (sensorModeFlags & MODE_ERROR) ? "Yes" : "No");
    printf(" - Calibrating               : %s\n", (sensorModeFlags & MODE_CALIBRATING) ? "Yes" : "No");

    return 0;
}
