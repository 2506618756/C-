int Pin = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(Pin,OUTPUT);
}

void loop() {
  //put your main code here, to run repeatedly:
  char news[100][10];
  char firstnews[][10] = {
    "11111","11110","11100","11000","10000","00000","00001","00011","00111","01111"
  };
  char secendnews[][10] = {
    "01","1000","1010","100","0","0010","110","0000",
    "00","0111","101","0100","11","10","111","0110",
    "1101","010","000","1","001","0001","011","1001",
    "1011","1100"
  };
  int t = 65;
  for( int i=0; i<10; i++ )
    strcpy(news[i],firstnews[i]);
  for( int i=0; i<26; i++,t++ )
    strcpy(news[t],secendnews[i]);
  char message[100] = "Hello,wrold!"; 
  for( int i = 0; message[i]!='\0'; i++ )
  {
     if( message[i]<'z' && message[i]<'a' )
      message[i] -= 32;
     if( !(message[i]<'Z' && message[i]>'A') && !( (int)(message[i])>-1 && (int)(message[i])<10 ) )
      continue;
      char s[100];
      strcpy( s,news[ (int)(message[i]) ] );
     for( int j=0; s[j]!='\0'; j++ )
     {
        if( s[j]=='1' )
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
