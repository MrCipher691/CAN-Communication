#include <SPI.h>              //Library for using SPI Communication 
#include <mcp2515.h>          //Library for using CAN Communication

struct can_frame canMsg; 
MCP2515 mcp2515(10);                 // SPI CS Pin 10 
 
void setup() {
  SPI.begin();                       //Begins SPI communication
  
  Serial.begin(9600);                //Begins Serial Communication at 9600 baudrate 
  
  mcp2515.reset();                          
  mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz 
  mcp2515.setNormalMode();                  //Sets CAN at normal mode
}

void loop() 
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) // To receive data
  {
     float ID = canMsg.data[0];
     float Ax = canMsg.data[1];         
     float Ay = canMsg.data[2];         
     float Az = canMsg.data[3];
     float Gx = canMsg.data[4];         
     float Gy = canMsg.data[5];         
     float Gz = canMsg.data[6];

     Serial.print(ID);
     Serial.print("\t");
     Serial.print(Ax);
     Serial.print("\t");
     Serial.print(Ay);
     Serial.print("\t");
     Serial.print(Az);
     Serial.print("\t");
     Serial.print(Gx);
     Serial.print("\t");
     Serial.print(Gy);
     Serial.print("\t");
     Serial.print(Gz);
     Serial.print("\n");
  }
}