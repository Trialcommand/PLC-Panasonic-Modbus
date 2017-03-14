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
#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>


modbusDevice regBank;
modbusSlave slave;
 
void setup()
{   
    pinMode(7, INPUT_PULLUP);

//Assign the modbus device ID.  
  regBank.setId(1);


// Holding registers

  regBank.add(40001);  
  regBank.add(40002);  
  regBank.add(40003);  
  regBank.add(40004);  
  regBank.add(40005);  
  regBank.add(40006);  
  regBank.add(40007);  
  regBank.add(40008);  
  regBank.add(40009);  
  regBank.add(40010);  
  
 

  slave._device = &regBank;  

  Serial.begin(9600);
  delay(100);
// Initialize the serial port for coms at 9600 baud  
  slave.setBaud(9600);
  delay(100);
  Serial.println("Connected "); 
  Serial.println("Modbus RTU Slave Online");  
}

void loop()
{    
  
///////// Holding Register [0] [2]   = 2 Holding Registers Lectura 
///////// Holding Register [0] [2]   = 2 Holding Registers Reading 

   
     int Mdelay = 5; // microdelay     

     Serial.print("[1] ");
     Serial.print(regBank.get(40001));
     delay(Mdelay);
     Serial.print("  ");    

      
     Serial.print("[3] ");
     Serial.print(regBank.get(40003));
     delay(Mdelay);
     Serial.print("  ");
    

///////// Holding Register [5]   =  1 Holding  Registers Escritura
/////     Holding Register [5]   =  1 Holding  Registers Writing

    regBank.set(40006, digitalRead(7)); 
    Serial.print("[5] ");
    Serial.print(digitalRead(7)); 
    Serial.print(" "); 
    Serial.println("--    Arduino Mega ");    
   
    slave.run();  

}
