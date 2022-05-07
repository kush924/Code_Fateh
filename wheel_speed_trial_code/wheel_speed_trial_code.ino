 int proximity = 2;
 unsigned long duration; // 
float AngularSpeed=0;
float speedkmh=0;
float speedms=0;
float WheelRadius= 0.265;
float Circum = (1.66)/6;
float Dist=0;
long unsigned int counter=0;
void setup() {
Serial.begin(9600);
  pinMode(proximity,INPUT);
}

void loop() {

   duration = pulseIn(proximity, LOW);
  if (duration>10){
  AngularSpeed= (0.8377*1000000)/duration;
  speedms=(AngularSpeed*WheelRadius);
  speedkmh=(speedms*3.6);
  counter=counter+1;
  Dist = counter*Circum;
  }

    Serial.print(speedkmh);
  Serial.print(" km/hr");
  Serial.print("   ,   ");
  Serial.print(Dist);
  Serial.print(" m");  
  Serial.println();
  
}
