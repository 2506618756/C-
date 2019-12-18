int Pin = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(Pin,OUTPUT);
}

void loop() {
  //put your main code here, to run repeatedly:
  char news[][10] = {
    "01","1000","1010","100","0","0010","110","0000",
    "00","0111","101","0100","11","10","111","0110",
    "1101","010","000","1","001","0001","011","1001",
    "1011","1100"
  };
  char message[100] = "HELLOWROLD"; 
  for( int i = 0; message[i]!='\0'; i++ )
  {
  	int index = (int)(message[i]-65);
     for( int j=0; news[index][j]!='\0'; j++ )
     {
        if( news[index][j]=='1' )
        {
            digitalWrite(Pin,HIGH);
            delay(1500);
            digitalWrite(Pin,LOW);
            delay(100);
        }
        else
        {
            digitalWrite(Pin,HIGH);
            delay(500);
            digitalWrite(Pin,LOW);
            delay(100);
        }
         delay(200);
     }
  }
}
