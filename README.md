DRONE STRIKER

============

Event 1 of the Code Wars
============

You are tasked with designing the software architecture that will power
the DRONE STRIKER, a defensive network of kinetic energy velocity penetrator 
weapons coordinated by a laptop and a USB Web Camera. The purpose of the
DRONE STRIKER is to provide an active denial against the coming onslaught of
the DRONES.

The DRONE STRIKER system provides a real time image of the drones at the
engagement distance. On firing the HV rounds will instantaneously hit their
target. Unfortunately due to a massive design flaw the HV routes are subject
to direct interference from wind. 

Implement the DroneStriker::Annihilate method. This method takes in an image
file containing the current engagement situation of the battlefield, as well
as the direction (in radians) of the wind tangential to the normal of the
view, and the magnitude of the wind tangential to the normal of the view(in
meters, 1 meter = 1 pixel). Taking into account the wind vector draw a
crosshairs on the location of the battlefield image where the HV round will
need to be fired to hit each target. If the hit is offscreen of the engagement
screen record to stdout a miss.

