//
// Created by NandanRaj on 12-02-2026.
//
#include<iostream>
class Playable {
    public:
    virtual void play()=0;
    virtual void pause()=0;
    virtual ~Playable()=default;
};
class Recordable {
    public:
    virtual void record() = 0;
    virtual void stop() = 0;
    virtual ~Recordable()=default;
};
class MediaPlayer: public Playable,public Recordable {
    public:
    void play() {
        std::cout<<"I am Playing"<<std::endl;
    }
    void stop() {
        std::cout<<"I am Stopped"<<std::endl;
    }
    void pause() {
        std::cout<<"I am Paused"<<std::endl;
    }
    void record() {
        std::cout<<"I am Recording"<<std::endl;
    }
};
int main() {
    MediaPlayer mp;
    Playable* p = &mp;
    p->play();
    p->pause();
    Recordable* r = &mp;
    r->record();
    r->stop();
}