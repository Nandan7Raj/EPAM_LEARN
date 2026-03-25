//
// Created by NandanRaj on 21-03-2026.
//
#include "Tsk10_6_4.h"
#include <iostream>
#include<string>
struct NetworkConnection::Impl {
    std::string endPoint;
    bool connected;
public:
    Impl(std::string ep):endPoint(std::move(ep)),connected(false) {
        connected=true;
        std::cout<<"CONSTRUCTOR[Impl]: Connection established to Endpoint: "<<endPoint<<std::endl;
    }
    ~Impl() {
        if (connected) {
            connected=false;
            std::cout<<"DESTRUCTOR[Impl]: Disconnected to EndPoint: "
            <<endPoint<<std::endl;
        }
    }
};

NetworkConnection::NetworkConnection(const std::string &endpoints):impl(std::make_unique<Impl>(endpoints)) {
    std::cout<<"CONSTRUCTOR [NetworkConnection class]\n";
}

NetworkConnection::~NetworkConnection() {
    std::cout<<"DESTRUCTOR [NetworkConnection class]\n";
}

void NetworkConnection::sendData(const std::string &data) {
    if (!isConnected()) {
        std::cerr<<"No endpoint is connected\n";
        return;
    }
    std::cout<<" Sending data to endpoint:"<<impl->endPoint
    <<" DATA: "<<data<<std::endl;
}

bool NetworkConnection::isConnected() const {
    return impl->connected;
}
