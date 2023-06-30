int pump=3;

int flame1=13;
int flame2=12;

int smoke=11;

int ledgreen=10;
int ledyellow=9;
int ledred=8;

int alarm=7;

bool FS1;
bool FS2;
int SS1;
//_____________________________________________________________________
void setup() {

pinMode(pump,OUTPUT);

pinMode(flame1,INPUT);
pinMode(flame2,INPUT);

pinMode(smoke,INPUT);

pinMode(ledgreen,OUTPUT);
pinMode(ledyellow,OUTPUT);
pinMode(ledred,OUTPUT);

pinMode(alarm,OUTPUT);
Serial.begin(9600);
}

//____________________________________________________________________________________
void loop() {


if (FS1==1&&FS2==1&&SS1==1)//safe mode
{digitalWrite(ledgreen,HIGH);digitalWrite(ledred,LOW);digitalWrite(ledyellow,LOW);digitalWrite(pump,LOW);digitalWrite(alarm,LOW);}

if (FS1==1&&FS2==1&&SS1==0)// smoke mode
{digitalWrite(ledgreen,LOW);digitalWrite(ledred,LOW);digitalWrite(ledyellow,HIGH);digitalWrite(pump,LOW);digitalWrite(alarm,HIGH);}

if (FS1==0||FS2==0)
{digitalWrite(ledgreen,LOW);digitalWrite(ledred,HIGH);digitalWrite(ledyellow,LOW);delay(4000);digitalWrite(pump,HIGH);digitalWrite(alarm,HIGH);}

if ((FS1==0||FS2==0)&&(SS1==0))
{digitalWrite(ledgreen,LOW);digitalWrite(ledred,HIGH);digitalWrite(ledyellow,HIGH);delay(4000);digitalWrite(pump,HIGH);digitalWrite(alarm,HIGH);}

if ((FS1==0||FS2==0)&&(SS1==1))
{digitalWrite(ledgreen,LOW);digitalWrite(ledred,HIGH);digitalWrite(ledyellow,LOW);delay(4000);digitalWrite(pump,HIGH);digitalWrite(alarm,HIGH);}

FS1=digitalRead(flame1);
FS2=digitalRead(flame2);
SS1=digitalRead(smoke);

Serial.print("Flame1=");
Serial.print(FS1);
Serial.print("\t");
Serial.print("Flame2=");
Serial.print(FS2);
Serial.print("\t");
Serial.print("Somke=");
Serial.println(SS1);
delay(500);}
