#ifndef KG_TIMER2_MANAGER_H
#define KG_TIMER2_MANAGER_H

#include <MsTimer2.h>

class Timer2Manager
{
private:
    static void f0();
    static void f1();
    static void f2();
    static void f3();
    static void f4();
    static void(*functions[5])();
    static int size ;
public:
    Timer2Manager();
    static void launch();
    static void add(void(*g)());
};

#endif  //KG_TIMER2_MANAGER_H