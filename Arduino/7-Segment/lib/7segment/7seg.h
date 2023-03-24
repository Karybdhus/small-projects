#pragma once
#include <Arduino.h>
#include "timer.h"

namespace vgf
{
    class CSegment
    {
        private:
            int A = PIN_A2;
            int B = PIN_A3;
            int C = PIN_A4;
            int D = PIN_A5;
            int E = PIN_A6;
            int F = 8;
            int G = 9;
            bool fehler = false;
            
            void init_7seg();

        public:
            CSegment();
            ~CSegment();
            void clear();
            void display1();
            void display2();
            void display3();
            void display4();
            void display5();
            void display6();
            void display7();
            void display8();
            void display9();
            void display0();
            void displayFail();
            void failure0();
            void failure1();
            void failure2();
            void failure3();
            void failure4();
            void failure5();
            void failure6();
            void failure7();
            void failure8();
            void failure9();
    };
}