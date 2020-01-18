const int TEMP = A0;
const int LEVEL = A1;
const int HUM = A2;
const int MOT = 13;

const double a = 0.0011129148;
const double b = 0.000234125;
const double c = 0.0000000876741;

const int analogMaxTemp = 1024;
const int analogMinTemp = 0;
const int analogMaxHum = 1024; //sec
const int analogMinHum = 120;  //dans l'eau
const int analogMaxNiv = 1000; //plein
const int analogMinNiv = 100;  //vide

double TM = 15;
double Tm = 10;
double HM = 0;
double Hm = 1;

void setup() {
  Serial.begin(9600);
  pinMode(MOT, OUTPUT);
}

void loop() {
    static char buffer[32];
    static size_t pos = 0;
    while (Serial.available()) {
        char c = Serial.read();
        if (c == '\n') {  // on end of line, parse the number
            buffer[pos] = '\0';

            Serial.print("received: ");
            Serial.println(buffer);
            pos = 0;
            if(buffer[0] == 'H' && buffer[1] == 'M'){
              HM = ((int)buffer[2]-'0')*10 + ((int)buffer[3]-'0');
            }
            else if (buffer[0] == 'H' && buffer[1] == 'P'){
              Hm = ((int)buffer[2]-'0')*10 + ((int)buffer[3]-'0');
            }
             else if (buffer[0] == 'T' && buffer[1] == 'M'){
              TM = ((int)buffer[2]-'0')*10 + ((int)buffer[3]-'0');
            }
             else if (buffer[0] == 'T' && buffer[1] == 'P'){
              Tm = ((int)buffer[2]-'0')*10 + ((int)buffer[3]-'0');
            }
            
        } else if (pos < sizeof buffer - 1) {  // otherwise, buffer it
            buffer[pos] = c;
            pos++;

        }
    }
  Serial.print("TEMPPLUS ");
  Serial.println(Tm);
  Serial.print("TEMPMOINS ");
  Serial.println(TM);
  Serial.print("HUMPLUS ");
  Serial.println(Hm);
  Serial.print("HUMMOINS ");
  Serial.println(HM);
   
  //TEMPERATURE
  int bit_temperature = analogRead(TEMP);
  double R = log(1000.0*(1024/bit_temperature-1));
  double temperature = 1/(a+b*R+c*R*R*R);
  temperature = temperature - 273.15;
  Serial.print("temperature ");
  Serial.println(temperature);  
  
  //NIVEAU EAU
  double niveau = analogRead(LEVEL);
  double niveau1 = (niveau*100)/analogMaxNiv;
  Serial.print("niveau ");
  Serial.println(niveau1);

  //HUMIDITE
  double humidite = analogRead(HUM);
  humidite = 100-((humidite*100)/analogMaxHum);
  Serial.print("humidite ");
  Serial.println(humidite);

  lancement_moteur(temperature, humidite, niveau);

  delay(10000);
  //delay(1000*60*60*3); //toute les trois heures on active les capteurs
  

}

void lancement_moteur(int temp, int humi, int niv){
  if(niv >= analogMinNiv){                         //Si il reste suffisamment d'eau pour un arrossage
    if((temp >= TM) && (humi <= Hm)){              //s'il fait trop chaud et que la terre est sèche, on arrose
      digitalWrite(MOT, HIGH);
      delay(7000);
      digitalWrite(MOT, LOW);
    }
    else if(((temp >= Tm) && (temp <= TM)) && (humi<=Hm)){ //Si la temperature est normal mais que la terre est sèche, on arrose
      digitalWrite(MOT, HIGH);
      delay(7000);
      digitalWrite(MOT, LOW);
    }
    else if(((temp <= Tm) && (temp >= 0)) && (humi <= Hm)){ //Si la temperature est très basse mais pas négative (risque de geler) et que la terre est sèche, on arrose
      digitalWrite(MOT, HIGH);
      delay(7000);
      digitalWrite(MOT, LOW);
    }
    else
      //Serial.println("Pas besoin d'arroser !"); //Sinon on arrose pas
      return;
  }
  else                                          //On ne fait rien rien pour ne pas habimer la pome tant que le réservoir n'est pas plein
    //Serial.println("Niveau d'eau trop faible pour activé la pompe!");
    return;
}
  humidite = 100-((humidite*100)/analogMaxHum);
  Serial.print("humidite ");
  Serial.println(humidite);

  lancement_moteur(temperature, humidite, niveau);
  delay(10000);
  //delay(1000*60*60*3); //toute les trois heures on active les capteurs
  

}

void lancement_moteur(int temp, int humi, int niv){
  if(niv >= analogMinNiv){                         //Si il reste suffisamment d'eau pour un arrossage
    if((temp >= TM) && (humi <= Hm)){              //s'il fait trop chaud et que la terre est sèche, on arrose
      digitalWrite(MOT, HIGH);
      delay(3000);
      digitalWrite(MOT, LOW);
    }
    else if(((temp >= Tm) && (temp <= TM)) && (humi<=Hm)){ //Si la temperature est normal mais que la terre est sèche, on arrose
      digitalWrite(MOT, HIGH);
      delay(3000);
      digitalWrite(MOT, LOW);
    }
    else if(((temp <= Tm) && (temp >= 0)) && (humi <= Hm)){ //Si la temperature est très basse mais pas négative (risque de geler) et que la terre est sèche, on arrose
      digitalWrite(MOT, HIGH);
      delay(3000);
      digitalWrite(MOT, LOW);
    }
    else
      //Serial.println("Pas besoin d'arroser !"); //Sinon on arrose pas
      return;
  }
  else                                          //On ne fait rien rien pour ne pas habimer la pome tant que le réservoir n'est pas plein
    //Serial.println("Niveau d'eau trop faible pour activé la pompe!");
    return;
}
