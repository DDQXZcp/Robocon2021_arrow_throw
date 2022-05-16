#include "main.h"
#include <string>

DigitalIn pos_control(USER_BUTTON);

void inverse()
{
        motor1 = -13000;
        motor2 = -13000;
        motor3 = -13000;
        motor4 = -13000;
}

void motorUpdate()
{
    if(pos_control == 1)motor1 = 1;
    else motor1 = 0;
    motor.update(motor1, motor2, motor3, motor4);
}



float map(float in, float inMin, float inMax, float outMin, float outMax)
{
    // check it's within the range
    if (inMin < inMax)
    {
        if (in <= inMin)
            return outMin;
        if (in >= inMax)
            return outMax;
    }
    else
    { // cope with input range being backwards.
        if (in >= inMin)
            return outMin;
        if (in <= inMax)
            return outMax;
    }
    // calculate how far into the range we are
    float scale = (in - inMin) / (inMax - inMin);
    // calculate the output.
    return outMin + scale * (outMax - outMin);
}
int main()
{
    printf("hello");
    printf("\n");
    //motor.manual();
    while (1)
    {
            inverse();
            motorUpdate();
            printf("Update");
            printf("\n");
    }
}
