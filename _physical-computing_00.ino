
  // Input Definition (Encoder) 
 
 #define Rotary01 A2
 #define Rotary02 A3

  // Output Definition (LED's)
 
 #define LED01 2
 #define LED02 3
 #define LED03 4

  // Statusdefinition für den Zähler und vorwärts/rückärts Schritte
  
 int counter = 0; 
 int currentStateRotary01;
 int previousStateRotary01; 

 String RotaryDirection ="";

  

 void setup() { 
   
   pinMode (Rotary01,INPUT);
   pinMode (Rotary02,INPUT);
   
   pinMode (LED01,OUTPUT);
   pinMode (LED02,OUTPUT);
   
   Serial.begin (9600);
   
   previousStateRotary01 = digitalRead(Rotary01);

 } 

 void loop() { 

      // aktelles Signal des Encoders A2 
   currentStateRotary01 = digitalRead(Rotary01);

      // Signal für Drehschritt A2 veränder sich
   if (currentStateRotary01 != previousStateRotary01){ 

      //  Signal für Richtung A3 nach Drehung nicht A2 entspricht, wird linksrum gedreht (ergo Wert -1)
     if (digitalRead(Rotary02) != currentStateRotary01) { 
       counter --;
       RotaryDirection ="Left";
     

      //  Falls Bedingung dadrübernicht erfüllt ist, wird rechtsrum gedreht  (ergo Wert +1)
     } else {
       counter ++;
       RotaryDirection ="Right";
     }

   
      // Verschiedene LED Feedbacks, je nach counterzahl
  
   if (counter<5){
    
  
      digitalWrite(LED01,LOW);
      digitalWrite(LED02,LOW);
    
  }

      if (counter>5){
      
  
      digitalWrite(LED01,HIGH);
      digitalWrite(LED02,LOW);
     
    
  }
      if (counter>10){
      
  
      digitalWrite(LED01,LOW);
      digitalWrite(LED02,HIGH);
    
    
  }
      if (counter>15){
    
  
      digitalWrite(LED01,HIGH);
      digitalWrite(LED02,HIGH);
    
  }

      if (counter>20){
    
  
      digitalWrite(LED01,HIGH);
      digitalWrite(LED02,HIGH);
      delay(100);
      digitalWrite(LED01,LOW);
      digitalWrite(LED02,LOW);
      delay(100);
      digitalWrite(LED01,HIGH);
      digitalWrite(LED02,HIGH);
      delay(100);
      digitalWrite(LED01,LOW);
      digitalWrite(LED02,LOW);
      delay(100);
      digitalWrite(LED01,HIGH);
      digitalWrite(LED02,HIGH);
      delay(200);
      digitalWrite(LED01,LOW);
      digitalWrite(LED02,LOW);
      delay(200);
      digitalWrite(LED01,HIGH);
      digitalWrite(LED02,HIGH);
    
  }
     


      // Anzeige des Zählerwertes im "serial"

     Serial.print("Value: ");
     Serial.println(counter);
    } 
   previousStateRotary01 = currentStateRotary01; 
 }
