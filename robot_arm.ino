#include <Servo.h>

#define base 3                     // 바닥
#define wrist 5                    // 손목
#define elbow 6                    // 팔꿈치
#define gripper 11                 // 그립

int LED1 = 13;
int LED2 = 4;
int LED3 = 2;

Servo s3, s5, s6, s11;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);

  s3.attach(base);                 // 밑 바닥
  s5.attach(wrist);                // 손목
  s6.attach(elbow);                // 팔꿈치
  s11.attach(gripper);             // 그립
  Serial.begin(9600);
  initialization();
}

void loop(){

    if(Serial.available()){
      char input = Serial.read();

      if(input == 'b'){
        delay(1500);
        digitalWrite(13, HIGH);
        Serial.println("glass");
        glass();
      }
      else if(input == 'c'){
        delay(1500);
        digitalWrite(4, HIGH);
        Serial.println("can");
      }
      else if(input == 'd'){
        digitalWrite(2, HIGH);
        Serial.println("plastic");
        delay(1500);
        plastic();
      }
      else if(input == 'a'){
        digitalWrite(13, LOW);
        digitalWrite(4, LOW);
        digitalWrite(2, LOW);
      }
    }
}

void glass(){
  delay(2000);
  s5.write(30);
  s6.write(145);
  delay(2000);
  s11.write(180);
  delay(2500);
  s5.write(90);
  s6.write(90);
  delay(2000);
  s3.write(165);                 // 오른쪽으로 회전
  delay(1500);
  s11.write(90);
  delay(1500);
  s3.write(90);
  s5.write(155);
  s6.write(30);
  s11.write(90);
  delay(2000);
}

void plastic(){
  delay(2000);
  s5.write(30);
  s6.write(145);
  delay(2000);
  s11.write(180);
  delay(2500);
  s5.write(90);  
  s6.write(90);
  delay(2000);
  s3.write(15);                 // 왼쪽으로 회전
  delay(1500);
  s11.write(90);
  delay(1500);
  s3.write(90);
  s5.write(155);
  s6.write(30);
  s11.write(90);
  delay(2000);
}

void initialization(){             // 초기 상태
  delay(1500);
  s3.write(90);
  s5.write(155);
  s6.write(30);
  s11.write(90);
  delay(2000);
}

/*void stretch(){                    // 뻗은 후에 잡은 상태
  delay(1000);
  s5.write(30);
  s6.write(145);
  delay(2000);
  s11.write(180);
}

void lift_L(){                     // 잡고 들어올린 후 왼쪽으로 이동
  delay(2500);
  s5.write(90);
  s6.write(90);
  delay(2000);
  s3.write(15);
  delay(1500);
}

void lift_R(){                     // 잡고 들어올린 후 오른쪽으로 이동
  delay(2500);
  s5.write(90);
  s6.write(90);
  delay(2000);
  s3.write(165);
  delay(1500);
}

/*
    servo_base.write(90);       // 바닥 부분 초기값                3
    servo_base.write(15);       // 바닥 부분 오른쪽
    servo_base.write(165);      // 바닥 부분 왼쪽

    servo_shoulder.write(155);  // 손목 부분 초기값                5
    servo_shoulder.write(30);   // 손목 부분 최대 펴진 상태

    servo_elbow.write(30);      // 팔꿈치 부분 초기값              6
    servo_elbow.write(145);     // 팔꿈치 부분 최대 펴진 상태

    servo_gripper.write(90);    // 그립이 완전 벌린 상태           11
    servo_gripper.write(180);   // 그립이 닫힌 상태
*/
