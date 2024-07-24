#include <Wire.h>                    // Esta librería le permite comunicarse al arduino por medio de modulo interno i2c, ya sea como maestro a otros dispositivos o como esclavo recibiendo peticiones y respondiendo datos.
#include <NewPing.h>                // SE DEFINE LA LIBRERIA AL SENSOR ULTRASONICO
#define TRIG_PIN A0                 // SE DEFINE EL SENSOR ULTRASONICO, TRIG VA AL PIN A0 DEL ARDUINO UNO. Naranja
#define ECHO_PIN A1                 // SE DEFINE EL SENSOR ULTRASONICO, ECHO VA AL PIN A1 ARDUINO UNO.  Verde
#define MAX_DISTANCE 200              
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);  // DEFINIMOS LAS VARIABLES GLOBALES TRIG_PIN , ECHO_PIN , MAX_DISTANCE
#include <Servo.h>                  // SE DEFINE LA LIBRERIA AL SERVOMOTOR.
#include <Adafruit_PWMServoDriver.h> // SE DEFINE LA LIBRERIA ADAFRUIT PARA LA SHIELD
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver();

int pos0=102;     // VARIABLES PARA CONVERTIR LAS FRECUENCIAS EN GRADOS DE LOS SERVOS (0 ,90 ,180)
int pos180=512;

     
int distance = 100;        // VARIABLE DE DISTANCIA DE ULTRASONIDO          
int buzzer = 9;             // BUZZER
void setup() {

servos.begin();
servos.setPWMFreq(50);

  delay(1000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
 
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  pinMode(9,OUTPUT);



}

void loop() {
posicioninicial();                  //EJECUTA LA POSICION INICIAL CON EL ROBOT
delay(1000);                    
moveForward();                      //EL ROBOT AVANZA

int distanceR = 0;                  // VARIABLE PARA GUARDAR LA DISTANCIA EN LA DERECHA QUE TOMA EL SENSOR ULTRASONICO
 int distanceL =  0;                // VARIABALE PARA GUARDAR LA DISTANCIA EN LA IZQUIERDA QUE TOMA EL SENSOR ULTRASONICO
 delay(40);
 
 if(distance <=20 && distance >= 0)                //SE ACTIVA EL SENSOR ULTRASONICO CUANDO DETECTA OBSTACULOS A MENOS DE 20CM.
 {
  sonarBuzzer();
  moveStop();                  // El ROBOT SE DETIENE POR 200 MILISEGUNDOS.  
  delay(200);              
  moveBackward();              //EL ROBOT RETROCEDE POR 800 MILISEGUNDOS.
  delay(200);                      
  moveStop();                   // El ROBOT SE DETIENE
  delay(2000);
  distanceR = lookRight();       // EL ROBOT MIRA A LA DERECHA
  delay(200);
  distanceL = lookLeft();         //EL ROBOT MIRA A LA IZQUIERDA
  callarBuzzer();
  delay(200);

  if(distanceR>=distanceL)          // SI LA DISTANCIA DERECHA ES MAYOR O IGUAL A LA DISTANCIA IZQUIERDA
  {
    turnRight();                    //EL ROBOT GIRA A LA DERECHA Y AVANZA
    moveStop();                     // EL ROBOT SE DETIENE
  }
 
      else                        // SI NO EL ROBOT EJECUTARA LO CONTRARIO
     
  {
    turnLeft();                 // EL ROBOT GIRA A LA IZQUIERDA Y AVANZA
    moveStop();                 // EL ROBOT SE DETIENE
  }
 
 }else                            // SI NO ENTONCES EL ROBOT SEGUIRA AVANZANDO HACIA ADELANTE
                           
 {
  moveForward();        
 }
 distance = readPing();      
}

int lookRight()                        //DEFINIMOS LA VARIABLE PARA MIRAR A LA DERECHA
{
    setServo(8,50);                    // SE MUEVE cuello A LA ( der ) #8      
    delay(500);
    int distance = readPing();         //TOMA LA DISTANCIA Y LA LEE
    delay(100);  
    setServo(8,90);                    //SE MUEVE EL cuello AL  ( centro ) #8
    return distance;                   //REGRESA EL VALOR A DISTANCIA
}

int lookLeft()                        //DEFINIMOS LA VARIABLE PARA MIRAR A LA IZQUIERDA
{
    setServo(8,180);                  //SE MUEVE cuello A LA (izq ) #8
    delay(500);
    int distance = readPing();        //TOMA LA DISTANCIA Y LA LEE
    delay(100);
     setServo(8,90);                   //SE MUEVE cuello AL ( centro ) #8  
    return distance;
    delay(100);
}

int readPing() {                        //DEFINIMOS LA VARIABLE PARA GUARDAR LAS DISTANCIAS Y LEERLAS
  delay(70);
  int cm = sonar.ping_cm();             //DEFINIMOS UNA VARIABLE PARA GUARDAR LA DISTANCIA EN CENTIMETROS
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}


void posicioninicial() {
//femur delantero izq  #0
setServo(0,50);
//pata delantera izq #1
setServo(1,140);
//femur posterior izq #4
setServo(4,40);
//femur delantero der #2
setServo(2,120);
// pata posterior izq #5
setServo(5,180);
//pata delantero der #3
setServo(3,20);
//femur posterior der #6
setServo(6,120);
//pata posterior der #7
setServo(7,160);
//cuello (izq - der ) #8
setServo(8,90);
//cabeza (up-down) #9
setServo(9,100);


}




void posicionatras() {
//femur delantero izq  #0
setServo(0,0);
//pata delantera izq #1
setServo(1,140);
//femur posterior izq #4
setServo(4,90);
//femur delantero der #2
setServo(2,100);
// pata posterior izq #5
setServo(5,90);
//pata delantero der #3
setServo(3,20);
//femur posterior der #6
setServo(6,120);
//pata posterior der #7
setServo(7,160);
//cuello (izq - der ) #8
setServo(8,90);
//cabeza (up-down) #9
setServo(9,100);


}
void moveStop() {           //DETENERSE
//femur delantero izq  #0
setServo(0,50);
//pata delantera izq #1
setServo(1,140);
//femur posterior izq #4
setServo(4,40);
//femur delantero der #2
setServo(2,120);
// pata posterior izq #5
setServo(5,180);
//pata delantero der #3
setServo(3,20);
//femur posterior der #6
setServo(6,120);
//pata posterior der #7
setServo(7,160);
//cuello (izq - der ) #8
setServo(8,90);
//cabeza (up-down) #9
setServo(9,100);
moveBackward();
}

void moveForward() {     //AVANZAR
//femur delantero izq  #0
setServo(0,0);
//femur delantero der #2
setServo(2,180);
//femur posterior izq #4
setServo(4,140);
//femur posterior der #6
setServo(6,80);

}

void moveBackward() {        //RETROCEDER

//femur delantero izq  #0
setServo(0,0);
//femur delantero der #2
setServo(2,180);
//femur posterior izq #4
setServo(4,70);
//femur posterior der #6
setServo(6,80);
delay(1000);
//femur posterior izq #4
setServo(4,140);
//femur posterior der #6
setServo(6,120);



}  

void turnRight() {     //GIRA A LA DERECHA
//femur delantero izq  #0
setServo(0,0);
delay(50);

//femur posterior izq #4
setServo(4,120);


 moveForward();    // El ROBOT VUELVE A AVANZAR
}
 
void turnLeft() {           //GIRA A LA IZQUIERDA

//femur delantero der #2
setServo(2,100);
delay(50);

//femur posterior der #6
setServo(6,80);

moveForward(); // El ROBOT VUELVE A AVANZAR
             
}  

void sonarBuzzer(){
digitalWrite(9,HIGH);
//delay(distance);
//digitalWrite(9,LOW);
//delay(distance);
}

void callarBuzzer(){
digitalWrite(9,LOW);
}

void setServo(uint8_t n_servo, int angulo) {  //DEFINIMOS UNA FUNCION PARA CONVERTIR LAS FRECUENCIAS EN GRADOS PARA LOS SERVOS EN 0,90,180
  int duty;
duty = map (angulo,0,180,pos0,pos180);
servos.setPWM(n_servo, 0, duty);
}
