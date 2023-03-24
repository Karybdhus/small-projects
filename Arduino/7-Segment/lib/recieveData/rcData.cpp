#include "rcData.h"
 
const byte numChars = 32;
char receivedChars[numChars];  

boolean newData = false;

int dataNumber = 0;             

void rcWithEndMarker() 
{
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
    
    if (Serial.available() > 0) 
    {
        rc = Serial.read();
        if (rc != endMarker) 
        {
            receivedChars[ndx] = rc;
            ndx++;

            if (ndx >= numChars) 
            {
                ndx = numChars - 1;
            }
        }
        else 
        {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}

int transmitNumber() 
{
    if (newData == true) 
    {
        dataNumber = 0;             
        dataNumber = atoi(receivedChars);   
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        Serial.print("Data as Number ... ");    
        Serial.println(dataNumber);    
        newData = false;
    }
    return dataNumber;
}