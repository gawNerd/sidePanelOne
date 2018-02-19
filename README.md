# sidePanelOne
Code for using the Totem Side Panel 1 (SP1) components. A library will be available for all components of the Side Panel 1 as made by [the guys at Totem](https://totemmaker.net/en/product/side-panel-1-soldered-add-on-for-totem-mini-lab).

## Components of Side Panel 1
The different components that this side Panel offers are:

### Switches
The SP1 offers three switches with two contacts each. One of these contacts is used to drive a LED to indicate it's status. The other one connected to our Arduino to give us a digital (On / Off) value. A class named **sp1_switch*** will be given to be able to work with these switches.

### Potmeters
The SP1 offers three variable resistors (or potentiometers). Using jumpers, one of the outer contacts of each potmeter can be connected to VCC and the other one to ground. In this case one can vary the middle pin between those values. When the jumpers are removed one can of course supply other voltages as well. A class named **sp1_potmeter** will be given to be able to read the values of the potmeters.

### Rotary
The SP1 offers one rotary Switch. It has three contacts, two for Contact A and Contact B that are used when rotating the knob. A third contact is used to detect the pushing of the know laterally. A class named **sp1_rotary** will be given to be able to read the functions of this rotary knob.

### Buttons
The SP1 offers three push buttons with one contact each. This contact is used to pull the open side to ground (so it's active low). A class named **sp1_button** will be given to be able to work with these buttons.

### Tri-color (RGB) LED
The SP1 offers a RGB LED. It has three connections (R, G and B). Each of these connections can be supplied with a value to have the LED change color and intensity. A class named **sp1_rgb** will be given to be able to work with this LED.

### Relay
The SP1 offers a relay (an electrically operable switch). This relay has a LED beside it to indicate it's state and a couple of contacts with which we can switch things on or off using external power. A class named **sp1_relay** will be given to be able to work with this relay.


## See also:

[Readme file](./README.md)

[Roadmap or TODO file](./TODO.md)

[License file](./LICENSE)
