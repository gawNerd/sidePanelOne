/* ------------------------------------------------------------------------- *
 * Name   : sp1_rgb.h
 * Author : Gerard Wassink
 * Date   : February 2018
 * Purpose: Set values for the RGD LED in the Side Panel 1 by Totem
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

#ifndef sp1_rgb_h
#define sp1_rgb_h

#include "Arduino.h"

class sp1_rgb
{

  public:
    sp1_rgb(int R, int G, int B);
    void setColor(int Rvalue, int Gvalue, int Bvalue);

  private:
    int _R, _G, _B;

};

#endif
