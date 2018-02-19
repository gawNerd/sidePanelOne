/* ------------------------------------------------------------------------- *
 * Name   : sp1_test.ino
 * Author : Gerard Wassink
 * Date   : February 2018
 * Purpose: Test libraries for the Side Panel 1 by Totem
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
#include "sp1_switch.h"
#include "sp1_button.h"
#include "sp1_potmeter.h"
#include "sp1_rgb.h"
#include "sp1_relay.h"
#include "sp1_rotary.h"

sp1_switch *swA, *swB, *swC;
sp1_button *btA, *btB, *btC;
sp1_potmeter *pmA, *pmB, *pmC;
sp1_rgb *RGB;
sp1_relay *rel;
sp1_rotary *rot;


/* ---------------------------------------------------------- *
    Setup runs once
 * ---------------------------------------------------------- */
void setup()
{
    swA = new sp1_switch(10);
    swB = new sp1_switch(11);
    swC = new sp1_switch(12);

    btA = new sp1_button(2);
    btB = new sp1_button(3);
    btC = new sp1_button(4);

    pmA = new sp1_potmeter(A0);
    pmB = new sp1_potmeter(A1);
    pmC = new sp1_potmeter(A2);

    RGB = new sp1_rgb(7, 8, 9);

    rel = new sp1_relay(5);

    rot = new sp1_rotary(A3, A4, A5);

    Serial.begin(9600);
}



/* ---------------------------------------------------------- *
    Loop runs repeatedly
 * ---------------------------------------------------------- */
void loop()
{
    int val = 0;
    
    Serial.print("SW's: ");

    val = swA->readSwitch();
    Serial.print(val);

    val = swB->readSwitch();
    Serial.print(val);

    val = swC->readSwitch();
    Serial.print(val);

    
    Serial.print("\tBT's: ");

    val = btA->readButton();
    Serial.print(val);

    val = btB->readButton();
    Serial.print(val);

    val = btC->readButton();
    Serial.print(val);

    
    Serial.print("\tPM's: ");

    int pA = pmA->readPotmeter();
    Serial.print(pA);
    Serial.print(", ");

    int pB = pmB->readPotmeter();
    Serial.print(pB);
    Serial.print(", ");

    int pC = pmC->readPotmeter();
    Serial.print(pC);
    Serial.print(" ");

    Serial.print("\tRotary value: ");
    val = rot->readRotary();
    Serial.print(val);

    Serial.print("\tRotary push: ");
    val = rot->readPush();
    Serial.print(val);

    Serial.print("\tsetting RGB ");
    RGB->setColor((pA/4), (pB/4), (pC/4));


    Serial.print("\tset relay when pC > 511 ");
    if (pC > 511)
    {
      rel->setRelay();
    }
    else
    {
      rel->clearRelay();
    }

    Serial.print("\n");
//     delay(500);
}
