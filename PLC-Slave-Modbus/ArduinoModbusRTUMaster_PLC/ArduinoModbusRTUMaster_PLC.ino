/*
 *  More info      : http://pdacontrolen.com
 *  Mas informacion: http://pdacontroles.com
 *  Channel  Youtube https://www.youtube.com/c/JhonValenciaPDAcontrol/videos   
 *
 *
 *
 *  Modified by Trialcommand
 *   More Tutorials: 
 *   Website http://trialcommand.com
 *	 In English: http://en.trialcommand.com
 *	 En Español: http://en.trialcommand.com  
 *   
 */
#include <ModbusMaster232.h> 
///#include <SoftwareSerial.h>  // Modbus RTU pins   D7(13),D8(15)   RX,TX

// Instantiate ModbusMaster object as slave ID 1
  ModbusMaster232 node(1);

void setup()
{

  pinMode(7, INPUT_PULLUP);

  Serial.begin(9600);
  delay(100);  
  node.begin(9600);  // Modbus RTU
  delay(100);
  Serial.println("Connected "); 
  Serial.println("Modbus RTU Master Online");
  
}


void loop()
{

///////// Holding Register [0] [2]   = 2 Holding Registers Lectura 
///////// Holding Register [0] [2]   = 2 Holding Registers Reading 

int Mdelay = 5;   // microdelay

node.readHoldingRegisters(0, 1); 
Serial.print("[0] ");
Serial.print(node.getResponseBuffer(0));
node.clearResponseBuffer();
delay(Mdelay);

 Serial.print(" ");  
  
node.readHoldingRegisters(2, 1); 
Serial.print("[2] ");
Serial.print(node.getResponseBuffer(0));
node.clearResponseBuffer();
delay(Mdelay);

 Serial.print(" ");
  
///////// Holding Register [4]   =  1 Holding  Registers Escritura
/////     Holding Register [4]   =  1 Holding  Registers Writing  
node.writeSingleRegister(4,digitalRead(7));
Serial.print("[4] ");
Serial.print(digitalRead(7));

Serial.print(" "); 

Serial.println("       --    Arduino Mega ");
delay(Mdelay);

  
  
}






