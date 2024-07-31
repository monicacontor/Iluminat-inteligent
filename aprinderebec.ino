#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);   
int bec = 2;  //pinul corespunzator becului
int senzor=4;  //pinul corespunzator senzorului



void setup()     //functie folosita pentru a initializa variabile, pinuri 
{
  BT.begin("Sistem bluetooth bec");
  Serial.begin(9600);   // initializam serialul
  pinMode(bec, OUTPUT); //initializam becul 
  pinMode(senzor, INPUT);  //initializam senzorul 
  digitalWrite(bec, LOW);   //Ne asiguram ca becul este oprit la inceput
  }

void loop()   //functie utilizata pentru a controla activ placa Arduino
{
  if(BT.available())  //Verificam daca este vreo intrare de la telefon
  {
    int x = BT.read();  //Stocam tot ce este citit de pe un dispozitiv bluetooth intr-o variabila 'x'
    Serial.write(x);  

  if (char(x) == '0')     //conditia ca daca apasam '0' 
  {
    digitalWrite(bec, LOW);    //sa se stinga becul 
    BT.print("Lumina OFF\n");
    }
    
  if (char(x) == '1')    //conditia ca daca apasam '1'
  {
    digitalWrite(bec, HIGH); //sa se aprinda becul 
    BT.print("Lumina ON\n");
  }
    
  }
   
  if (digitalRead(bec) == HIGH && digitalRead(senzor)==LOW)    //conditie ca daca becul este aprins si nu se detecteaza miscare 
  {
    digitalWrite(bec, LOW);  //senzorul sa-l stinga 

    }
  }
  
