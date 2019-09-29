# Python code to illustrate Sending mail from 
# your Gmail account 
import smtplib
import serial 
# creates SMTP session
s = smtplib.SMTP('smtp.gmail.com', 587)
 
# start TLS for security
s.starttls()
ser = serial.Serial('/dev/ttyACM1',9600)
#s = [0]
while True:
	read_serial=ser.readline()
	#s[0] = str(int (ser.readline(),16))
	#print s[0]
	print (read_serial)
# Authentication
s.login("nikhil.nagpal98@gmail.com", "karan10300")
 
# message to be sent
# message = "THIS IS AN ALERT MESSAGE 4"
 
# sending the mail
s.sendmail("nikhil.nagpal98@gmail.com", "ayushjain034@gmail.com", read_serial)
 # terminating the session
s.quit()
