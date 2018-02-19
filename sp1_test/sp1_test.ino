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
 * responsible for any damage to your hardware. Especially the positioning
 * of servo's has to be done with the greatest possible care.
 *
 * ------------------------------------------------------------------------- *
 *        Copyright (C) 2018 Gerard Wassink
 * ------------------------------------------------------------------------- */

#include "Arduino.h"
#include "sp1_switch.h"
#include "sp1_button.h"
#include "sp1_potmeter.h"

sp1_switch *swA, *swB, *swC;
sp1_button *btA, *btB, *btC;
sp1_potmeter *pmA, *pmB, *pmC;


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

    val = pmA->readPotmeter();
    Serial.print(val);
    Serial.print(", ");

    val = pmB->readPotmeter();
    Serial.print(val);
    Serial.print(", ");

    val = pmC->readPotmeter();
    Serial.print(val);
    Serial.print(" ");

    Serial.print("\n");
    delay(500);
}
