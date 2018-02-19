/* ------------------------------------------------------------------------- *
 * Name   : sp1_potmeter.cpp
 * Author : Gerard Wassink
 * Date   : February 2018
 * Purpose: Read potmeter values for the Side Panel 1 by Totem
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

#include "sp1_potmeter.h"

/* ------------------------------------------------------------------------- *
    Constructor for this class
 * ------------------------------------------------------------------------- */
sp1_potmeter::sp1_potmeter(int pm)
{
    pinMode(pm, INPUT);

    _pm = pm;                           // initialize privates
    _prev_value = -1;
    _value = -1;
}



/* ------------------------------------------------------------------------- *
    Read a potmeter from Side Panel 1
 * ------------------------------------------------------------------------- */
int sp1_potmeter::readPotmeter()
{
    _prev_value = _value;               // Store previous value (future use?)
    _value = analogRead(_pm);          // read current value
    return(_value);                     //   and return it
}
