/* ------------------------------------------------------------------------- *
 * Name   : sp1_switch.h
 * Author : Gerard Wassink
 * Date   : February 2018
 * Purpose: Switch actions for the Side Panel 1 by Totem
 * ------------------------------------------------------------------------- *
 *
 * ------------------------------------------------------------------------- *
 *             Release under the condictions of the enclosed LICENSE file
 * ------------------------------------------------------------------------- *
 *
 * Usage of this library is at the user's own risk, author will not be held
 * responsible for any damage to your hardware. Especially the positioning
 * of servo's has to be done with the greatest possible care.
 *
 * ------------------------------------------------------------------------- *
 *        Copyright (C) 2018 Gerard Wassink
 * ------------------------------------------------------------------------- */

#ifndef sp1_switch_h
#define sp1_switch_h

#include "Arduino.h"

class sp1_switch
{

  public:
    sp1_switch(int sw);
    int readSwitch();

  private:
    int _sw;
    int _prev_value;
    int _value;

};

#endif
