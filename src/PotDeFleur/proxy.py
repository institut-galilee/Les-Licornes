import serial
import requests

URLDB_PATCH = "https://careplant-bad6a.firebaseio.com/capteurs.json"

i=0

ser = serial.Serial('COM3',9600)
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
    data = ser.readline()
    print (data.decode())
    sendPatchRequest(data.decode())

#sendPatchRequest("temperature 40")
