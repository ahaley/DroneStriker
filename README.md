DRONE STRIKER

============

Event 1 of the Code Wars
============

You are tasked with designing the software architecture that will power
the DRONE STRIKER, a defensive network of kinetic energy penetrator weapons
coordinated by a laptop and a USB Web Camera. The purpose of the DRONE STRIKER
is to provide active denial against the coming onslaught of the DRONES.

The DRONE STRIKER system provides a real time image of the drones at the
engagement distance. On firing the HV rounds will instantaneously hit their
target. Unfortunately due to a massive design flaw the HV path are subject
to direct interference from wind. For every meter per second of wind velocity
tangential to the engagement plane the HV round will travel approximately one
pixel. (Don't even try to second guess the physics of instantaneous travel and
the effect of wind against it, you're a computer scientist, not a physicist). 
The DRONE STRIKER will need to adjust targeting according to this contraint.

Implement the DroneStriker::Annihilate method. This method takes in an image
file containing the current engagement situation of the battlefield, as well
as the direction (in radians) of the wind tangential to the normal of the
view, and the magnitude of the wind tangential to the normal of the view(in
meters per second). Taking into account the wind vector paint the target on the
location of the battlefield image where the HV round will need to be fired to
hit each target.

Note: the wind orientation is textbook, meaning that it runs counter-clockwise
from the right side of the unit circle when referencing the engagement plane. 
Keep that in mind when dealing with the origin starting at the top left of the 
image that is the norm for computer graphics.


