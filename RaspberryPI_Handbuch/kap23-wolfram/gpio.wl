#!/usr/bin/wolfram -script

# Achtung: dieses Script hat bei unseren Tests unter Mathematica 11.0.1
# in Kombination mit Kernel 4.9 nicht mehr funktioniert! Unter Kernel
# 4.4 ist alles OK.

FindDevices["GPIO"]
DeviceConfigure["GPIO", {7 -> "Output", 9 -> "Input"}]

led = 7;            (* GPIO 7 = Pin 26*)
pushbutton = 9;     (* GPIO 9 = Pin 21 *)

(* Button-Zustand auslesen *)
state = DeviceRead["GPIO", pushbutton];
onoff = pushbutton /. state;
Print[onoff];

(* LED einschalten *)
DeviceWrite["GPIO", led -> 1];

