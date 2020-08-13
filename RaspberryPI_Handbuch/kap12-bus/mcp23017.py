#!/usr/bin/python3
import smbus, time
bus = smbus.SMBus(1)
adresse = 0x20 # I2C-Adresse des MCP23017

def get(register):
    read = bus.read_byte_data(adresse, register)
    return read

def set(register, daten):
    write = bus.write_byte_data(adresse, register, daten)
    return
 
set (0x00,0x20)

while True:
    state = get(0x12)
    print(state)
    if state == 0x00:
        set(0x14,0x01)
        print("Taster erkannt, LED an!")
    time.sleep(1)
    set (0x14,0x00)