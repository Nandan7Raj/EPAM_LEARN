//
// Created by NandanRaj on 21-03-2026.
//

#ifndef TSK10_6_4_H
#define TSK10_6_4_H
#include <memory>

class NetworkConnection {
    struct Impl;
    std::unique_ptr<Impl> impl;
public:
    NetworkConnection(const std::string& endpoints);
    ~NetworkConnection();
    bool isConnected() const;
    void sendData(const std::string& data);
};
#endif //TSK10_6_4_H