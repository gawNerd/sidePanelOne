/* ------------------------------------------------------------------------- *
 * Name   : sp1_button.cpp
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
 * responsible for any damage to your hardware.
 *
 * ------------------------------------------------------------------------- *
 *        Copyright (C) 2018 Gerard Wassink
 * ------------------------------------------------------------------------- */

#include "Arduino.h"

#include "sp1_button.h"

/* ------------------------------------------------------------------------- *
    Constructor for this class
 * ------------------------------------------------------------------------- */
sp1_button::sp1_button(int bt)
{
    pinMode(bt, INPUT_PULLUP);          // make sure unconnected = high

    _bt = bt;                           // initialize privates
    _prev_value = -1;
    _value = -1;
}



/* ------------------------------------------------------------------------- *
    Read a button from Side Panel 1
 * ------------------------------------------------------------------------- */
int sp1_button::readButton()
{
    _prev_value = _value;               // Store previous value (future use?)
    _value = digitalRead(_bt);          // read current value
    return(_value);                     //   and return it
}
