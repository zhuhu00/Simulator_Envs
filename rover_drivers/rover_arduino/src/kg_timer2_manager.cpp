#include "kg_timer2_manager.h"

int Timer2Manager::size = 0;
void(*Timer2Manager::functions[5])() {Timer2Manager::f0,Timer2Manager::f1,Timer2Manager::f2,Timer2Manager::f3,Timer2Manager::f4};
void Timer2Manager::f0(){;}
void Timer2Manager::f1(){;}
void Timer2Manager::f2(){;}
void Timer2Manager::f3(){;}
void Timer2Manager::f4(){;}

void Timer2Manager::launch()
{
    int i = 0;
    while (i < size)
    {
        (*functions[i++])();
    }
    
}

void Timer2Manager::add(void(*newFunction)())
{
    MsTimer2::stop();
    if (size < 5)
    {
        functions[size]=newFunction;
        size ++;
    }
    MsTimer2::set(5,launch);
    MsTimer2::start();
}