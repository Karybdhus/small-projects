#pragma once
#include <Arduino.h>

namespace vgf
{
    class CSegment
    {
        private:
            int A = 6;
            int B = 7;
            int C = 8;
            int D = 9;
            int E = 10;
            int F = 11;
            int G = 12;
            int dp = 13;
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
    };
}