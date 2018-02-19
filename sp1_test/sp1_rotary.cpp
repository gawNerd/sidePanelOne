/* ------------------------------------------------------------------------- *
 * Name   : sp1_rotary.cpp
 * Author : Gerard Wassink
 * Date   : February 2018
 * Purpose: Actions for the rotary encoder in the Side Panel 1 by Totem
 * ------------------------------------------------------------------------- *
 *
 * ------------------------------------------------------------------------- *
 *             Release under the condictions of the enclosed LICENSE file
 * ------------------------------------------------------------------------- *
 *
 * Usage of this library is at the user's own risk, author will not be held
 * responsible for any damage to your hardware.
 *
 * ------------------------------------------------------------------------- *
 *        Copyright (C) 2018 Gerard Wassink
 * ------------------------------------------------------------------------- */

#include "Arduino.h"

#include "sp1_rotary.h"

/* ------------------------------------------------------------------------- *
    Constructor for this class
 * ------------------------------------------------------------------------- */
sp1_rotary::sp1_rotary(int encA, int encB, int encP)
{
    pinMode(encA, INPUT_PULLUP);        // make sure unconnected = high
    pinMode(encB, INPUT_PULLUP);
    pinMode(encP, INPUT_PULLUP);

    _encA = encA;                       // initialize privates
    _encB = encB;
    _encP = encP;
    _prev_value = -1;
    _value = -1;
}



/* ------------------------------------------------------------------------- *
    Read the rotary from Side Panel 1
 * ------------------------------------------------------------------------- */
int sp1_rotary::readRotary()
{
    int retValue = 0;
    
    _prev_value = _value;               // Store previous value (future use?)
    
    int A_val = digitalRead(_encA);     // read current values
    int B_val = digitalRead(_encB);     // read current values
    
    _value = B_val<<1 | A_val;          // Combine the two values

    if (_prev_value == 3) {             // previous value 3?
        if (_value == 1) {              // clockwise?
          retValue = +10;               // increment
        } else if (_value == 2) {       // counter-clockwise?
          retValue = -10;               // decrement
        } // if
    } // if
    _prev_value = _value;               // save current to previous value
    
    return(retValue);                   //   and return it
}



/* ------------------------------------------------------------------------- *
    Read rotary Push button from Side Panel 1
 * ------------------------------------------------------------------------- */
int sp1_rotary::readPush()
{
    int P_val = digitalRead(_encP);     // read current value
    return(P_val);                      //   and return it
}
