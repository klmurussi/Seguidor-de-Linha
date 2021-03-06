const int motorDir = 5; //velocidade motor Direito - de 0 a 255
const int motorEsq = 6; //velocidade motor Esquerdo - de 0 a 255

const int dirDir = 7; //direcao do motor Direito - HIGH (pra frente) ou LOW (pra tras)
const int dirEsq = 8; //direcao do motor Esquerdo - HIGH (pra frente) ou LOW (pra tras)

const int SensorParar = 2; //ver se ja no chegou no fim do circuito
const int SensorDir = 3; //ler faixa infravermelho e ainda no entendi como que funciona isso
int Valor_SensorDir = 0; 
const int SensorEsq = 4; 
int Valor_SensorEsq = 0;
int limiar = 700;
int vel_max = 255;
int chegada = LOW; //se LOW nao for falso, entao testar com HIGH

void setup(){
  pinMode(motorDir, OUTPUT);
  pinMode(motorEsq, OUTPUT);
  pinMode(dirDir, OUTPUT);
  pinMode(dirEsq, OUTPUT);
  pinMode(SensorParar, INPUT);
  pinMode(SensorDir, INPUT);
  pinMode(SensorEsq, INPUT);
}

void loop(){
  //ler se no eh o fim do circuito
  chegada = digitalRead(SensorParar);
  if (chegada == LOW) { //se LOW nao for falso, entao testar com HIGH
      //ler sensores infravermelhos
      Valor_SensorDir = analogRead(SensorDir); 
      Valor_SensorEsq = analogRead(SensorEsq);

      //imprimir os resultados dos sensores para saber qual eh o limiar
      Serial.print("Sensor Direito = ");
      Serial.print(Valor_SensorDir);
      Serial.print(" | ");
      Serial.print("Sensor Esquerdo = ");
      Serial.println(Valor_SensorEsq); 

      //ir pra frente
      if((Valor_SensorDir > limiar) && (Valor_SensorEsq > limiar)){
        digitalWrite(dirDir, HIGH); 
        digitalWrite(dirEsq, HIGH);
        analogWrite(motorDir, vel_max); 
        analogWrite(motorEsq, vel_max);
      }
  } else {
    analogWrite(motorDir, 0);
    analogWrite(motorEsq, 0);
  }

}