//
// Created by NandanRaj on 19-03-2026.
//

#include<iostream>
#include<chrono>
#include<string>
class Timer {
    std::chrono::high_resolution_clock::time_point start;
    std::string label;
public:
    Timer(const std::string& lbl=""):start(std::chrono::high_resolution_clock::now())
    ,label(lbl) {
        if (!label.empty())std::cout<<"Timer started: "<<label<<std::endl;
    }
    ~Timer() {
        auto end=std::chrono::high_resolution_clock::now();
        auto duration=std::chrono::duration_cast<std::chrono::microseconds>(end-start);
        std::cout << (label.empty() ? "Elapsed time: " : "Timer [" + label + "] elapsed: ");
        std::cout << duration.count() << " micro sec" << std::endl;

    }
};
int main() {
    {
        Timer t("LOOP TIMING");
        for (int i=0;i<100000;i++) {
            if (i%10000==0) {
                std::cout<<"Loop is running\n";
            }
        }
        std::cout<<"End of loop\n";
    }// scope of timer ends here

}