void setup()
{

  Serial.begin(9600); 
  delay(100);
}


void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
    case 'r':
      RecieveMessage();
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    
  delay(1000);  
  mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); 
  delay(1000);
  mySerial.println("I am SMS from GSM Module");
  delay(100);
   mySerial.println((char)26);
  delay(1000);
}


 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); 
  delay(1000);
 }