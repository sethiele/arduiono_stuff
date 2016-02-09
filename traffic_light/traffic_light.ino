int car_red       = 4;
int car_yellow    = 3;
int car_green     = 2;

int walker_red    = 6;
int walker_green  = 5;

int green_time    = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Traffic light start");
  for (int i = 2; i <= 6; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  randomSeed(analogRead(0));
}

void loop() {
  set_car_green();
  green_time = (random(10000)%9) * 1000 + 5000;
  Serial.print("Green for: ");
  Serial.println(green_time);
  delay(green_time);
  set_car_red();
}

void set_car_green(){
  Serial.println("#####################################");
  Serial.println("START CAR GREEN");

  set_walker_red();
  
  Serial.println("CAR   : RED   : ON");
  digitalWrite(car_red, HIGH);
  
  Serial.println("CAR   : YELLOW: ON");
  digitalWrite(car_yellow, HIGH);
  
  delay(2000);
  
  Serial.println("CAR   : RED   : OFF");
  digitalWrite(car_red, LOW);
  
  Serial.println("CAR   : YELLOW: OFF");
  digitalWrite(car_yellow, LOW);
  
  Serial.println("CAR   : GREEN : ON");
  digitalWrite(car_green, HIGH);
  
  Serial.println("END CAR GREEN");
  Serial.println("#####################################");
}

void set_car_red(){
  Serial.println("#####################################");
  Serial.println("START CAR RED");

  Serial.println("CAR   : YELLOW: ON");
  digitalWrite(car_yellow, HIGH);

  Serial.println("CAR   : GREEN : OFF");
  digitalWrite(car_green, LOW);

  delay(1000);

  Serial.println("CAR   : YELLOW: OFF");
  digitalWrite(car_yellow, LOW);
  
  Serial.println("CAR   : RED   : ON");
  digitalWrite(car_red, HIGH);

  delay(1000);

  set_walker_green();

  Serial.println("END CAR RED");
  Serial.println("#####################################");
}

void set_walker_green(){
  Serial.println("#####################################");
  Serial.println("START WALKER GREEN");

  Serial.println("WALKER: GREEN : ON");
  digitalWrite(walker_green, HIGH);

  Serial.println("WALKER: RED   : OFF");
  digitalWrite(walker_red, LOW);
  
  Serial.println("END WALKER GREEN");
  Serial.println("#####################################");

  Serial.println("#####################################");
  Serial.println("Wait for Walker to walk");
  delay(5000);
  Serial.println("#####################################");
}

void set_walker_red(){
  Serial.println("#####################################");
  Serial.println("START WALKER RED");

  Serial.println("WALKER: GREEN : OFF");
  digitalWrite(walker_green, LOW);

  Serial.println("WALKER: RED   : ON");
  digitalWrite(walker_red, HIGH);

  delay(2000);
  
  Serial.println("END WALKER RED");
  Serial.println("#####################################");
}

