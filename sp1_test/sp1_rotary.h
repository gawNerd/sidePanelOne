/* ------------------------------------------------------------------------- *
 * Name   : sp1_rotary.h
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

#ifndef sp1_rotary_h
#define sp1_rotary_h

#include "Arduino.h"

class sp1_rotary
{

  public:
    sp1_rotary(int encA, int encB, int encP);
    void readRotary();
    int Rvalue;
    int Pvalue;

  private:
    int _encA, _encB, _encP;
    int _prev_value;
    int _cur_value;

};

#endif
