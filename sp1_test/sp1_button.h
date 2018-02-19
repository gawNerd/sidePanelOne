/* ------------------------------------------------------------------------- *
 * Name   : sp1_button.h
 * Author : Gerard Wassink
 * Date   : February 2018
 * Purpose: Button actions for the Side Panel 1 by Totem
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

#ifndef sp1_button_h
#define sp1_button_h

#include "Arduino.h"

class sp1_button
{

  public:
    sp1_button(int bt);
    int readButton();

  private:
    int _bt;
    int _prev_value;
    int _value;

};

#endif
