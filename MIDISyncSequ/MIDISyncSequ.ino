byte midi_start = 0xfa;
byte midi_stop = 0xfc;
byte midi_clock = 0xf8;
byte midi_continue = 0xfb;
int play_flag = 0;
byte data;
int ClckCnt = 0;
int StpCnt = 0;
int StpNmbr = 7;

void setup() {
 Serial.begin(31250);
 pinMode(LED_BUILTIN, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
 data = Serial.read();
 if(data == midi_start) 
    {
      ClckCnt = 0;
    }
 if(data == midi_clock)
 {
  if(ClckCnt < 94)
    {
      ClckCnt = ClckCnt + 2;
    }
  else
    {
      ClckCnt = 0;
    }
 }
 if((ClckCnt == 0) || (ClckCnt == 12) || (ClckCnt == 24) || (ClckCnt == 36) || (ClckCnt == 48) || (ClckCnt == 60) || (ClckCnt == 72) || (ClckCnt == 84))
 {
   if (StpCnt < 7)
   {StpCnt = StpCnt + 1;}
   else
   {StpCnt = 0;}
   Sync();
 }  
}

void Sync() {
  switch (StpCnt)
    {
      case 0:
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        break;
      case 1:
        digitalWrite(2, HIGH);    
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        break;
      case 2:
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        break;
      case 3:
        digitalWrite(2, HIGH);    
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        break;
      case 4:
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        break;
      case 5:
        digitalWrite(2, HIGH);    
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        break;
      case 6:
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        break;
      case 7:
        digitalWrite(2, HIGH);    
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        break;
    }
}
