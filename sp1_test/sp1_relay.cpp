/* ------------------------------------------------------------------------- *
 * Name   : sp1_relay.cpp
 * Author : Gerard Wassink
 * Date   : February 2018
 * Purpose: Operate the relay in the Side Panel 1 by Totem
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

#include "sp1_relay.h"

/* ------------------------------------------------------------------------- *
    Constructor for this class
 * ------------------------------------------------------------------------- */
sp1_relay::sp1_relay(int rel)
{
    pinMode(rel, OUTPUT);

    _rel = rel;                           // initialize privates
}



/* ------------------------------------------------------------------------- *
    Set the relay at the Side Panel 1
 * ------------------------------------------------------------------------- */
void sp1_relay::setRelay()
{
    digitalWrite(_rel, HIGH);
}


/* ------------------------------------------------------------------------- *
    Clear the relay at the Side Panel 1
 * ------------------------------------------------------------------------- */
void sp1_relay::clearRelay()
{
    digitalWrite(_rel, LOW);
}
