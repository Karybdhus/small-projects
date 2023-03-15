#include "7seg.h"

namespace vgf
{
    CSegment::CSegment()
    {
        init_7seg();
    }

    CSegment::~CSegment()
    {
    }

    void CSegment::init_7seg()
    {
        for (int i = 6; i <= 13; i++)
        {
            pinMode(i, OUTPUT);
        }
    }


    void CSegment::clear()
    {
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
        digitalWrite(dp, LOW);
    }

    void CSegment::display1()
    {
        CSegment::clear();
        digitalWrite(this->B, HIGH);
        digitalWrite(this->C, HIGH);
    }

    void CSegment::display2()
    {
        CSegment::clear();
        digitalWrite(this->A, HIGH);
        digitalWrite(this->B, HIGH);
        digitalWrite(this->G, HIGH);
        digitalWrite(this->E, HIGH);
        digitalWrite(this->D, HIGH);
    }

    void CSegment::display3()
    {
        CSegment::clear();
        digitalWrite(this->A, HIGH);
        digitalWrite(this->B, HIGH);
        digitalWrite(this->G, HIGH);
        digitalWrite(this->C, HIGH);
        digitalWrite(this->D, HIGH);
    }

    void CSegment::display4()
    {
        CSegment::clear();
        digitalWrite(this->B, HIGH);
        digitalWrite(this->G, HIGH);
        digitalWrite(this->F, HIGH);
        digitalWrite(this->C, HIGH);
    }

    void CSegment::display5()
    {
        CSegment::clear();
        digitalWrite(this->A, HIGH);
        digitalWrite(this->F, HIGH);
        digitalWrite(this->G, HIGH);
        digitalWrite(this->C, HIGH);
        digitalWrite(this->D, HIGH);
    }

    void CSegment::display6()
    {
        CSegment::clear();
        digitalWrite(this->A, HIGH);
        digitalWrite(this->F, HIGH);
        digitalWrite(this->G, HIGH);
        digitalWrite(this->C, HIGH);
        digitalWrite(this->D, HIGH);
        digitalWrite(this->E, HIGH);
    }

    void CSegment::display7()
    {
        CSegment::clear();
        digitalWrite(this->A, HIGH);
        digitalWrite(this->B, HIGH);
        digitalWrite(this->C, HIGH);
    }

    void CSegment::display8()
    {
        CSegment::clear();
        digitalWrite(this->A, HIGH);
        digitalWrite(this->B, HIGH);
        digitalWrite(this->C, HIGH);
        digitalWrite(this->D, HIGH);
        digitalWrite(this->E, HIGH);
        digitalWrite(this->F, HIGH);
        digitalWrite(this->G, HIGH);
    }

    void CSegment::display9()
    {
        CSegment::clear();
        digitalWrite(this->A, HIGH);
        digitalWrite(this->B, HIGH);
        digitalWrite(this->G, HIGH);
        digitalWrite(this->F, HIGH);
        digitalWrite(this->C, HIGH);
        digitalWrite(this->D, HIGH);
    }

    void CSegment::display0()
    {
        CSegment::clear();
        digitalWrite(this->A, HIGH);
        digitalWrite(this->B, HIGH);
        digitalWrite(this->C, HIGH);
        digitalWrite(this->D, HIGH);
        digitalWrite(this->E, HIGH);
        digitalWrite(this->F, HIGH);
    }

    void CSegment::displayFail()
    {
        CSegment::clear();
        digitalWrite(this->dp, HIGH);
    }
}