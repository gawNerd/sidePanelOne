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

unsigned long now = millis();         // Keep track
unsigned long prv = millis();         //   of time
long wait_time = 500;                 // displays every 1/2 second

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
    int val_swA, val_swB,val_swC;
    int val_btA, val_btB, val_btC;
    int val_pmA, val_pmB, val_pmC;

    val_swA = swA->readSwitch();
    val_swB = swB->readSwitch();
    val_swC = swC->readSwitch();

    val_btA = btA->readButton();
    val_btB = btB->readButton();
    val_btC = btC->readButton();
    
    val_pmA = pmA->readPotmeter();
    val_pmB = pmB->readPotmeter();
    val_pmC = pmC->readPotmeter();

    rot->readRotary();

    RGB->setColor((val_pmA/4), (val_pmB/4), (val_pmC/4));

    if (val_pmC > 511)
    {
      rel->setRelay();
    }
    else
    {
      rel->clearRelay();
    }

    now = millis();                     // Determine time
    if ((now - prv) >= wait_time) {     // if time passed
      Serial.print("SW's: ");
      Serial.print(val_swA);
      Serial.print(val_swB);
      Serial.print(val_swC);
      
      Serial.print("\tBT's: ");
      Serial.print(val_btA);
      Serial.print(val_btB);
      Serial.print(val_btC);
  
      Serial.print("\tPM's: ");
      Serial.print(val_pmA);
      Serial.print(", ");
      Serial.print(val_pmB);
      Serial.print(", ");
      Serial.print(val_pmC);
      Serial.print(" ");
  
      Serial.print("\tRotary value: ");
      Serial.print(rot->Rvalue);
      Serial.print("\tRotary push: ");
      Serial.print(rot->Pvalue);
  
      Serial.print("\tRGB set to pm values ");
      Serial.print("\tset relay when pmC > 511 ");
  
      Serial.print("\n");

      prv += wait_time;                 // Save the time
    } // if


//     delay(500);
}
