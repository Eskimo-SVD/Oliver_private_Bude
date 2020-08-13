#!/usr/bin/python3
# coding=utf-8
# Datei functions.py

import serial
import pymysql
import sys

# Auslesen der RFID-Transponder

def read_rfid():
    ser = serial.Serial("/dev/ttyAMA0")
    ser.baudrate = 9600
    daten = ser.read(14)
    ser.close()    
    daten = daten.replace(b'\x02', b'' )
    daten = daten.replace(b'\x03', b'' )
    return daten
    

class DB():
    def __init__(self):
        db = pymysql.connect(host="localhost", user="USERNAME", 
                             passwd="PASSWORD", db="rfid") 
        db.autocommit(True)
        self.cur = db.cursor()       

    def close_db( self ):
        self.cur.close()
        

    def add_user(self,rfid_id, name):    
        add=self.cur.execute("INSERT INTO user (rfid, name) " + 
                             "VALUES (%s,%s)", (rfid_id, name))
       

    def mysql_read(self, rfid_id):
        a=self.cur.execute("SELECT id, name, timestamp, rfid " + 
                           "FROM user WHERE rfid = %s" ,rfid_id)     
        id = 0
        name = 0
        timestamp = 0
        rfid = 0
        for row in self.cur.fetchall():
            id = int(row[0])
            name = str(row[1])
            timestamp = str(row[2])
            rfid = str(row[3])
        return id, name, timestamp,rfid

    def update_timestamp(self, rfid_id):      
        a=self.cur.execute("UPDATE user SET timestamp = NOW() " +  
                            "WHERE rfid = %s" ,rfid_id)