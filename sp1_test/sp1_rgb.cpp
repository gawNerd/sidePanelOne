/* ------------------------------------------------------------------------- *
 * Name   : sp1_rgb.cpp
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

#include "Arduino.h"

#include "sp1_rgb.h"

/* ------------------------------------------------------------------------- *
    Constructor for this class
 * ------------------------------------------------------------------------- */
sp1_rgb::sp1_rgb(int R, int G, int B)
{
    pinMode(R, OUTPUT);

    _R = R;                             // initialize privates
    _G = G;
    _B = B;
}



/* ------------------------------------------------------------------------- *
    Set colors and intensities for the rgb from Side Panel 1
 * ------------------------------------------------------------------------- */
void sp1_rgb::setColor(int Rvalue, int Gvalue, int Bvalue)
{
    analogWrite(_R, 0xFF - Rvalue);     // Set R value value
    analogWrite(_G, 0xFF - Gvalue);     // Set G value value
    analogWrite(_B, 0xFF - Bvalue);     // Set B value value
}
