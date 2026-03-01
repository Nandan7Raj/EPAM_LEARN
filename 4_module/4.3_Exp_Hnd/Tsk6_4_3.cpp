//
// Created by NandanRaj on 22-02-2026.
//
#include<iostream>
#include <ctime>      // time
#include <cstdlib>    // srand, rand
#include <stdexcept>  // runtime_error, invalid_argument
class MedicalMemoryTracker {
    static int totalMemAllocation;
    static int tolatMemDeallocation;
public:
    static void recordAllocation(const char* medicalResource,int size) {
        totalMemAllocation+=size;
        std::cout<<"Memory Allocation by "<<medicalResource<<"\n";
        std::cout<<"Total Memory Allocation: "<<totalMemAllocation<<"\n";
    }
    static void recordDeallocation(const char* medicalResource, int size) {
       tolatMemDeallocation+=size;
        std::cout<<"Total Memory Deallocation: "<< tolatMemDeallocation<<"\n";
    }
    static void reportLeaks() {
        if (totalMemAllocation-tolatMemDeallocation==0)
            std::cout<<"NO memory Leak\n";
        else
            std::cout<<"Memory Leak\n";
    }
    static void reset() {
        totalMemAllocation=0;
        tolatMemDeallocation=0;
    }
};
int MedicalMemoryTracker::totalMemAllocation=0;
int MedicalMemoryTracker::tolatMemDeallocation=0;

class MedicalDeviceException:public std::runtime_error {
public:
    explicit MedicalDeviceException(const std::string& msg):std::runtime_error(msg){};
};
class PatientDataException: public std::runtime_error {
public:
    explicit PatientDataException(const std::string& msg):std::runtime_error(msg){};
};
//stage 3
class PatientVitalMonitor {
    int* heartRateData;
    float* bloodPressureData;
    bool deviceConnected;
    const char* patientId;
    void connectToMedicalDevice() {
        if (rand()%2==0)
            throw MedicalDeviceException("Error: failer in connecting to medical device");
    }
    void calibrateSensors() {
        if (rand()%2==0)
            throw MedicalDeviceException("Error: error in calibrate sensor");
    }
    void validatePatientData() {
        if (rand()%2==0)
            throw MedicalDeviceException("Error: error in validating Patient Data");
    }
    void analyzeCriticalTrend() {
        if (rand()%2==0)
            throw MedicalDeviceException("Error: error in analyzing Critical Trend");
    }
public:
    PatientVitalMonitor(const char* id):patientId(id),heartRateData(nullptr),
    bloodPressureData(nullptr),deviceConnected(false) {
        heartRateData = new int[36000];
        MedicalMemoryTracker::recordAllocation("Heart Rate Buffer", (36000 * sizeof(int)));
        bloodPressureData = new float[18000];
        MedicalMemoryTracker::recordAllocation("Blood Pressure Buffer", 18000 * sizeof(float));

        connectToMedicalDevice();
        calibrateSensors();
    };
    ~PatientVitalMonitor() {
        std::cout<<"Shutdown message\n";
        if (heartRateData)
            delete[] heartRateData;
        MedicalMemoryTracker::recordDeallocation("Heart Rate Buffer", 36000 * sizeof(int));
        if (bloodPressureData)
            delete[] bloodPressureData;
        MedicalMemoryTracker::recordDeallocation("Blood Pressure Buffer", 18000 * sizeof(float));
    }

    void monitorPatientVitals(int durationMinutes ) {
         if (durationMinutes <= 0) {
             throw std::invalid_argument("E001: Monitoring duration must be positive!");
         }
        float* ecgAnalysisBuffer = new float[5000];
        MedicalMemoryTracker::recordAllocation("ECG Analysis Buffer", (5000 * sizeof(float)));
        validatePatientData();
        int *criticalTrendBuffer=new int[1000];
        MedicalMemoryTracker::recordAllocation("Critical Trend Buffer", (1000 * sizeof(int)));
        analyzeCriticalTrend();
        delete[] ecgAnalysisBuffer;
        MedicalMemoryTracker::recordDeallocation("ECG Analysis Buffer", 5000 * sizeof(float));
        std::cout << " ECG analysis completed - buffer freed" << std::endl;
        delete[]  criticalTrendBuffer;
        MedicalMemoryTracker::recordDeallocation("Critical Trend Buffer", 1000 * sizeof(int));
        std::cout << " Critical Trend analysis completed - buffer freed" << std::endl;

    }
};
int main() {
    std::cout
        << "Program: Emergency Patient Vital Monitoring (Stack Unwinding + Exceptions + Memory Tracking)\n"
        << "This program attempts to setup a PatientVitalMonitor and run critical monitoring.\n"
        << "It demonstrates that resources are cleaned up correctly across failures.\n\n";

    // Seed random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Capture user input for number of attempts
    int attempts = 0;
    std::cout << "Enter number of attempts (5 to 10 recommended): ";
    std::cin >> attempts;

    // Reset memory tracker
    MedicalMemoryTracker::reset();

    // Local variables as per instructions
    PatientVitalMonitor* emergencyMonitor = nullptr;
    bool setupSuccessful = false;

    int attemptNo = 1;
    while (attemptNo <= attempts) {
        std::cout << "\nAttempt " << attemptNo << "\n";

        // For each attempt, start clean
        emergencyMonitor = nullptr;
        setupSuccessful = false;

        // First try-catch block (setup)
        try {
            emergencyMonitor = new PatientVitalMonitor("EMERGENCY-001");
            setupSuccessful = true;
            std::cout << "Setup successful: PatientVitalMonitor created.\n";
        }
        catch (const MedicalDeviceException& e) {
            std::cout << "Setup failed (MedicalDeviceException): " << e.what() << "\n";
        }

        // If setup successful, attempt critical monitoring
        if (setupSuccessful && emergencyMonitor) {

            // Second try-catch block (monitoring)
            try {
                emergencyMonitor->monitorPatientVitals(10);
                std::cout << "Monitoring finished successfully.\n";
            }
            catch (const PatientDataException& e) {
                std::cout << "Monitoring failed (PatientDataException): " << e.what() << "\n";
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Monitoring failed (invalid_argument): " << e.what() << "\n";
            }
        }

        // Finally clean-up
        delete emergencyMonitor;
        emergencyMonitor = nullptr;

        attemptNo++;
    }

    // Report memory leaks during all attempts
    std::cout << "\nMemory Leak Report\n";
    MedicalMemoryTracker::reportLeaks();

    return 0;
}