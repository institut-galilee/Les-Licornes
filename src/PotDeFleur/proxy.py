import serial
import requests
import json
import time

URLDB_PATCH = "https://careplant-bad6a.firebaseio.com/capteurs.json"

i=0

ser = serial.Serial('COM3',9600)
ser.close()
ser.open()
splt=data.split()

nomData = ["HM", "HP", "TM", "TP"]

ligne = ''
val = []
payload = ''

ts = time.time()
intervalGet = 10

def sendGetRequest():
	r = requests.get("https://careplant-bad6a.firebaseio.com/info.json")
	return json.loads(r.text)

def sendPatchRequest(ligne):
    val = ligne.split(' ')
    payload = '{'+ '"' + val[0] + '": ' + str(val[1]) + '}'
    r = requests.patch(URLDB_PATCH, data = payload, headers={"Content-Type": "application/json"})
    if (r.status_code != 200):
        print("Erreur dans l'enregistrement des donnees")
        



while True:
    data = ser.readline()
    print ("Enregistrement : " + data.decode())
    sendPatchRequest(data.decode())
    if(time.time()-ts > intervalGet):
        donnee = sendGetRequest()
        ts = time.time()
        for (i, e in enumerate(nomData)):
            serial.println(e + str(donnee[i]))
    
    

#sendPatchRequest("temperature 40")
#https://arduino.stackexchange.com/questions/49682/sending-float-values-from-python-to-arduino-via-serial-communication
