#include <Arduino.h>

void SetInterval(void (*FUNCTION)(), int DELAY, bool LOOP)
{
    int currenTMillis = millis();
    int isLOOP = 1;
    if (currenTMillis > DELAY && isLOOP)
    {
        if (LOOP == false)
        {
            isLOOP = 0;
        }
        FUNCTION();
        currenTMillis -= millis();
    }
}
