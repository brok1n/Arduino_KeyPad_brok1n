//
// Created by brok1n on 2016/6/20.
//

#ifndef BROK1N_BKEYPADS_H
#define BROK1N_BKEYPADS_H

class Bkeypad
{

private:
    char (*keyValue)[4];
    //int  keyPin[][4] = { { 30, 32, 34, 36 }, { 22, 24, 26, 28}};
    int (*keyPin)[4];

    char preKey = -1;
    int  keyIndex1 = -1;
    int  keyIndex2 = -1;
    int  keyCode1 = -1;
    int  keyCode2 = -1;
    int  preKeyCode1 = 15;
    int  preKeyCode2 = 15;

public:
    void init( char value[4][4], int pin[4][4] );

    char getKey();

private:
    void reversalXY( int flag );

    int getIndex( int index );

    int getLowIndex( int index );

};

#endif //BROK1N_BKEYPADS_H
