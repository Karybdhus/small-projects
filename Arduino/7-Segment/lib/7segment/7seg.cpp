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
        pinMode(A2, OUTPUT);
        pinMode(A3, OUTPUT);
        pinMode(A4, OUTPUT);
        pinMode(A5, OUTPUT);
        pinMode(A6, OUTPUT);
        pinMode(8, OUTPUT);
        pinMode(9, OUTPUT);
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
        digitalWrite(this->A, HIGH);
        digitalWrite(this->E, HIGH);
        digitalWrite(this->F, HIGH);
        digitalWrite(this->G, HIGH);
    }

    void CSegment::failure0()
    {
        bool change = timer(500);
        
        if (change && !(this->fehler))
        {
            CSegment::clear();
            CSegment::display0();
            this->fehler = true;
        }
        else if (change && this->fehler)
        {
            CSegment::clear();
            CSegment::displayFail();
            this->fehler = false;
        }
    }

    void CSegment::failure1()
    {
        bool change = timer(500);
        
        if (change && !(this->fehler))
        {
            CSegment::clear();
            CSegment::display1();
            this->fehler = true;
        }
        else if (change && this->fehler)
        {
            CSegment::clear();
            CSegment::displayFail();
            this->fehler = false;
        }
    }

    void CSegment::failure2()
    {
        bool change = timer(500);
        
        if (change && !(this->fehler))
        {
            CSegment::clear();
            CSegment::display2();
            this->fehler = true;
        }
        else if (change && this->fehler)
        {
            CSegment::clear();
            CSegment::displayFail();
            this->fehler = false;
        }
    }

    void CSegment::failure3()
    {
        bool change = timer(500);
        
        if (change && !(this->fehler))
        {
            CSegment::clear();
            CSegment::display3();
            this->fehler = true;
        }
        else if (change && this->fehler)
        {
            CSegment::clear();
            CSegment::displayFail();
            this->fehler = false;
        }
    }

    void CSegment::failure4()
    {
        bool change = timer(500);
        
        if (change && !(this->fehler))
        {
            CSegment::clear();
            CSegment::display4();
            this->fehler = true;
        }
        else if (change && this->fehler)
        {
            CSegment::clear();
            CSegment::displayFail();
            this->fehler = false;
        }
    }

    void CSegment::failure5()
    {
        bool change = timer(500);
        
        if (change && !(this->fehler))
        {
            CSegment::clear();
            CSegment::display5();
            this->fehler = true;
        }
        else if (change && this->fehler)
        {
            CSegment::clear();
            CSegment::displayFail();
            this->fehler = false;
        }
    }

    void CSegment::failure6()
    {
        bool change = timer(500);
        
        if (change && !(this->fehler))
        {
            CSegment::clear();
            CSegment::display6();
            this->fehler = true;
        }
        else if (change && this->fehler)
        {
            CSegment::clear();
            CSegment::displayFail();
            this->fehler = false;
        }
    }

    void CSegment::failure7()
    {
        bool change = timer(500);
        
        if (change && !(this->fehler))
        {
            CSegment::clear();
            CSegment::display7();
            this->fehler = true;
        }
        else if (change && this->fehler)
        {
            CSegment::clear();
            CSegment::displayFail();
            this->fehler = false;
        }
    }

    void CSegment::failure8()
    {
        bool change = timer(500);
        
        if (change && !(this->fehler))
        {
            CSegment::clear();
            CSegment::display8();
            this->fehler = true;
        }
        else if (change && this->fehler)
        {
            CSegment::clear();
            CSegment::displayFail();
            this->fehler = false;
        }
    }

    void CSegment::failure9()
    {
        bool change = timer(500);
        
        if (change && !(this->fehler))
        {
            CSegment::clear();
            CSegment::display9();
            this->fehler = true;
        }
        else if (change && this->fehler)
        {
            CSegment::clear();
            CSegment::displayFail();
            this->fehler = false;
        }
    }
}