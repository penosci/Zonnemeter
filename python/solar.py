#!/usr/bin/python
import MySQLdb
import time
import serial

db = MySQLdb.connect(host="localhost",    # your host, usually localhost
                     user="solar",         # your username
                     passwd="kaas",  # your password
                     db="PV-data")        # name of the data base

# you must create a Cursor object. It will let
#  you execute all the queries you need
cur = db.cursor()

# Use all the SQL you like


# print all the first cell of all the rows


ser = serial.Serial(
               port='/dev/ttyUSB0',
               baudrate = 2400,
               parity=serial.PARITY_NONE,
               stopbits=serial.STOPBITS_ONE,
               bytesize=serial.EIGHTBITS,
               timeout=1
           )

while 1:
    x=ser.readline()
    if x is not "":
        data = x.replace("\r\n",'').split(";")
        print data
        try:
            cur.execute("INSERT INTO Solar_power (`value`) VALUES (%s)" % data[0])
            db.commit()
        except:
            db.rollback()
        #print "the value is: %s" % data[0]
        #print "INSERT INTO Solar_power (`value`) VALUES (%s)" % data[0]
db.close()
