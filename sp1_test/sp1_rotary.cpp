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
    _cur_value = -1;
}



/* ------------------------------------------------------------------------- *
    Read the rotary and rotary push button from Side Panel 1
 * ------------------------------------------------------------------------- */
void sp1_rotary::readRotary()
{    
    int A_val = digitalRead(_encA);     // read current rotary Contact A
    int B_val = digitalRead(_encB);     // read current rotary Contact B
    
    _cur_value = B_val<<1 | A_val;      // Combine the two values
    
    if (_prev_value == 3) {             // previous value 3?
        if (_cur_value == 1) {          // counter-clockwise?
          this->Rvalue -= 10;           // increment
          if (this->Rvalue <0)          // See that
          {                             //  value
            this->Rvalue = 0;           //   does not go
          } // if                       //    below zero
        } else if (_cur_value == 2) {   // clockwise?
          this->Rvalue += 10;           // increment
        } // if
    } // if
    _prev_value = _cur_value;           // save current to previous value

    this->Pvalue = digitalRead(_encP);    // read current push button value

} // readRotary


