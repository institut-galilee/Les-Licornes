import serial
import requests
import json
import time

URLDB_PATCH = "https://careplant-bad6a.firebaseio.com/capteurs.json"

i=0

#ouverture du port serial
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

#Interval auquel récupérer les données
intervalGet = 10

#Recupere les infos sur la plante sur firebase
def sendGetRequest():
	r = requests.get("https://careplant-bad6a.firebaseio.com/info.json")
	return json.loads(r.text)

#fonction qui envoie une requete pour modifier firebase (PATCH)
#parametre au format : "champAModifier valeur" (chaine de caractere)
def sendPatchRequest(ligne):
    val = ligne.split(' ')
    #craft le body de la requete
    payload = '{'+ '"' + val[0] + '": ' + str(val[1]) + '}'
    print (payload)
    #envoie de la requete
    r = requests.patch(URLDB_PATCH, data = payload, headers={"Content-Type": "application/json"})
    if (r.status_code != 200):
        print("Erreur dans l'enregistrement des donnees")
        



while True:
    data = ser.readline()
    print ("Enregistrement : " + data.decode())
    sendPatchRequest(data.decode())

    #A chaque 10 secondes on envoie une requete get et envoie des données à l'arduino
    if(time.time()-ts > intervalGet):
        donnee = sendGetRequest()
        print("recuperation des infos")
        ts = time.time()
        for e in nomData:
            valeur = str(donnee.get(e))
            if (len(valeur) != 2):
                valeur = '0' + valeur
            print ("Donnee envoye : " + e+valeur)

            #envoie des données
            ser.write(bytes(e + valeur + '\n', 'ascii'))
   
