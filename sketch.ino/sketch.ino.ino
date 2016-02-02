const int PINmotorIn1 = 9;
const int PINmotorIn2 = 10;
const int PINacc_x = A0;
const int PINacc_y = A1;
const int PINacc_z = A2;
double acc_x;
double acc_y;
double acc_z;
double angle_x;
double angle_y;
double angle_z;

void setup() {
  pinMode(PINmotorIn1,OUTPUT);
  pinMode(PINmotorIn2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  acc_x = analogRead(PINacc_x);
  acc_y = analogRead(PINacc_y);
  acc_z = analogRead(PINacc_z);

  angle_x = double(180) * atan2(acc_x, acc_z) / PI;
  angle_y = double(180) * atan2(acc_x, acc_y) / PI;
  angle_z = double(180) * atan2(acc_y, acc_z) / PI;
  

  Serial.print(angle_x);
  Serial.print('\t');
  Serial.print(angle_y);
  Serial.print('\t');
  Serial.print(angle_z);
  Serial.print('\t');
  Serial.print('\n');
}

//Accepts values between -255 and +255.
//Negative values result in counterclockwise motion with 255 degrees of precision between stoped and full Speed.
//Positive values result in clockwise motion with 255 degrees of precision between stoped and full Speed.
void run_motor(int Speed)
{
  Serial.println(Speed);
  if (Speed < 0 && Speed >= 255)
  {
    analogWrite(PINmotorIn1,-Speed);
    analogWrite(PINmotorIn2,0);
    
  }
  else if (Speed >0 && Speed <= 255)
  {
    analogWrite(PINmotorIn1,0);
    analogWrite(PINmotorIn2,Speed);
  }
  else
  {

    analogWrite(PINmotorIn1,0);
    analogWrite(PINmotorIn2,0);
    
  }
}



