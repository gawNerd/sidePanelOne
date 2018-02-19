/* ------------------------------------------------------------------------- *
 * Name   : sp1_potmeter.h
 * Author : Gerard Wassink
 * Date   : February 2018
 * Purpose: Potmeter reads for the Side Panel 1 by Totem
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

#ifndef sp1_potmeter_h
#define sp1_potmeter_h

#include "Arduino.h"

class sp1_potmeter
{

  public:
    sp1_potmeter(int pm);
    int readPotmeter();

  private:
    int _pm;
    int _prev_value;
    int _value;

};

#endif
