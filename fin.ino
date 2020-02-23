int temperature,newtemp,move,previousmove=0,moving,total,level;
float timeLeft=28800;

void setup() {


  pinMode(D4, INPUT);
  pinMode(A1, INPUT);

}


void loop() {
 
  temperature=analogRead(D4);
  newtemp=map(temperature, 800, 1100, 0, 100);
  move=analogRead(A1);
  moving=map(move, 900, 1400, 0, 50);
  total=moving+newtemp;
  if(total<50){
      level=0;
  }
  if((total>50)&&(total<110)){
      level=1;
      timeLeft=timeLeft-1;
  }
  if((total>110)&&(total<140)){
      level=2;
      timeLeft=timeLeft-1.5;
  }
  if(total>140){
      level=3;
      timeLeft=timeLeft-2;
  }
  delay(1000);
    
  
   
  

  Particle.publish("total", String(total), PRIVATE);
  Particle.publish("Level signal", String(level), PRIVATE);
  Particle.publish("Time Left(s)", String(timeLeft), PRIVATE);

  

}