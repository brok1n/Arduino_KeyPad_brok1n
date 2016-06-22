//
// Created by brok1n on 2016/6/20.
//

#include "bKeyPad.h"
#include <Arduino.h>


void Bkeypad::init( char value[4][4], int pin[4][4] )
{
    keyValue = value;
    keyPin = pin;
}


char Bkeypad::getKey()
{
    preKeyCode1 = keyCode1;
    preKeyCode2 = keyCode2;
    reversalXY(1);

    //读行
    keyCode1 = getLowIndex( 0 );
    if( keyCode1 < 15 )
    {
        //Serial.println("有键被按下");
        reversalXY(0);
        //读列
        keyCode2 = getLowIndex( 1 );
    }
    else
    {
        //没有按键按下 检测是否有上次的按键
        if( preKeyCode1 != 15 && preKeyCode2 != 15)
        {
            keyIndex1 = getIndex(preKeyCode1);
            keyIndex2 = getIndex(preKeyCode2);
            if( keyIndex1 >= 0 && keyIndex2 >= 0 )
            {
                //上次有键按下、现在没有键按下。所以是抬起状态
                preKey = keyValue[keyIndex1][keyIndex2];
                preKeyCode1 = 0;
                preKeyCode2 = 0;
                keyCode1 = 0;
                keyCode2 = 0;
                keyIndex1 = 0;
                keyIndex2 = 0;
                return preKey;
            }
        }
    }
    return -1;
}

void Bkeypad::reversalXY( int flag )
{
    int i = 0;
    unsigned int pin0Mode = OUTPUT;
    unsigned int pin1Mode = INPUT_PULLUP;
    unsigned int digital0 = LOW;
    unsigned int digital0 = HIGH;
    if( flag )
    {
        pin0Mode = INPUT_PULLUP;
        pin1Mode = OUTPUT;
        digital0 = HIGH;
        digital0 = LOW;
    }

    for( i = 0; i < 4; ++ i )
    {
        pinMode(keyPin[0][i], pin0Mode);
        pinMode(keyPin[1][i], pin1Mode);
    }
    delayMicroseconds(100);
    for( i = 0; i < 4; ++ i )
    {
        digitalWrite(keyPin[0][i], HIGH);
        digitalWrite(keyPin[1][i], LOW);
    }
    delayMicroseconds(100);
}

int Bkeypad::getIndex( int index )
{
    switch( index )
    {
        case 7:
            return 3;
        case 11:
            return 2;
        case 13:
            return 1;
        case 14:
            return 0;
        default:
            return -1;
    }
}

int Bkeypad::getLowIndex( int index )
{
    return ( ( digitalRead( keyPin[index][0]) << 1 | digitalRead( keyPin[index][1]) ) << 1 | digitalRead( keyPin[index][2]) ) << 1 | digitalRead( keyPin[index][3]);
}