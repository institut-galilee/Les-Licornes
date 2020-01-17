import serial
import requests
import json
URLDB_PATCH = "https://careplant-bad6a.firebaseio.com/capteurs.json"

i=0

ser = serial.Serial('COM6',9600)
ser.close()
ser.open()
data = ser.readline()
splt=data.split()

ligne = ''
val = []
payload = ''

def sendPatchRequest(ligne):
	val = ligne.split(' ')
	payload = '{'+ '"' + val[0] + '": ' + str(val[1]) + '}'
	r = requests.patch(URLDB_PATCH, data = payload, headers={"Content-Type": "application/json"})
	if (r.status_code != 200):
		print("Erreur dans l'enregistrement des donnees")

	
while True:

	data = ser.read(1)
	if (data == '\n'):
		print (ligne)
		#faire ligne format "champ val"

	else:
		ligne += data

#sendPatchRequest("temperature 40")
