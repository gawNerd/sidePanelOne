/* ------------------------------------------------------------------------- *
 * Name   : sp1_relay.h
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

#ifndef sp1_relay_h
#define sp1_relay_h

#include "Arduino.h"

class sp1_relay
{

  public:
    sp1_relay(int rel);
    void setRelay();
    void clearRelay();

  private:
    int _rel;

};

#endif
