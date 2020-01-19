import serial
import requests
import json
import time

URLDB_PATCH = "https://careplant-bad6a.firebaseio.com/capteurs.json"

i=0

ser = serial.Serial('COM3',9600)
ser.close()
ser.open()
time.sleep(2)
data = ser.readline()
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
    print (payload)
    r = requests.patch(URLDB_PATCH, data = payload, headers={"Content-Type": "application/json"})
    if (r.status_code != 200):
        print("Erreur dans l'enregistrement des donnees")
        



while True:
    data = ser.readline()
    print ("Enregistrement : " + data.decode())
    sendPatchRequest(data.decode())
    if(time.time()-ts > intervalGet):
        donnee = sendGetRequest()
        print("recuperation des infos")
        ts = time.time()
        for e in nomData:
            valeur = str(donnee.get(e))
            if (len(valeur) != 2):
                valeur = '0' + valeur
            print ("Donnee envoye : " + e+valeur)

            ser.write(bytes(e + valeur + '\n', 'ascii'))
   
