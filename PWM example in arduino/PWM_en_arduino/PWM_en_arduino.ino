#include <PWM.h>


int32_t frequency = 10; // Establezca la Frecuencia en Hertz (HZ), se pueden operar frecuencias de 10Hz a 300kHz aprox
bool flag = true;
unsigned long time; 


void setup()
{
  InitTimersSafe(); 

  //Establece la frecuencia para el pin especificado
  bool success = SetPinFrequencySafe(9, frequency);
  pinMode(3, OUTPUT);


  //SI LA FRECUENCIA DEL PIN SE CONFIGURO CORRECTAMENTE, ENCIENDA EL PIN 13.
  if(success) {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);    
  }
}

void loop()
{                                   //Potenciometro para ajustar el DUTY CYCLE de 10Kohms
  int sensorValue = analogRead(A4); //Conectar las dos terminales laterales del potenciometro a +5V y Gnd 
                                    //(Lado izquierdo(pin 1) a GND y lado derecho (Pin 3) a +5V
  pwmWrite(9, sensorValue / 4);     //la terminal de enmedio(2) conectarla a una entrada analogica (A2)
  delay(30);                        //La salida PWM será el pin digital (9) con respecto a tierra.

  if(flag == true && analogRead(A3) >= 220){
    digitalWrite(3, HIGH);
    flag = false;
  }else{
    flag = true;
  }

  if(analogRead(A3) <=100){
    digitalWrite(3, LOW);
    flag = false;
  }



}
