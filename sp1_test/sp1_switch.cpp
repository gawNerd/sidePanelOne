/* ------------------------------------------------------------------------- *
 * Name   : sp1_switch.cpp
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

#include "Arduino.h"

#include "sp1_switch.h"

/* ------------------------------------------------------------------------- *
    Constructor for this class
 * ------------------------------------------------------------------------- */
sp1_switch::sp1_switch(int sw)
{
    pinMode(sw, INPUT_PULLUP);          // make sure unconnected = high

    _sw = sw;                           // initialize privates
    _prev_value = -1;
    _value = -1;
}



/* ------------------------------------------------------------------------- *
    Read a switch from Side Panel 1
 * ------------------------------------------------------------------------- */
int sp1_switch::readSwitch()
{
    _prev_value = _value;               // Store previous value (future use?)
    _value = digitalRead(_sw);          // read current value
    return(_value);                     //   and return it
}
