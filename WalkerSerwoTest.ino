#include <Servo.h>

//переменные для чтения информации из монитора порта
String strData = "";
boolean recievedFlag;
int intVar;

//параметры сервопривода
const int servos = 4;// количество сервоприводов в механизме
int angle = 90;
int servoCenterConst[servos] = {95, 99, 98, 85};// сюда записываем полученные показатели среднего положения сервоприводов
Servo servoLegs[servos];

void setup() {
  Serial.begin(9600); // включаем монитор порта
  int iter = 0; //счетчик сервоприводов (начинается с нуля
  
  //инициализируем сервоприводы
  for (int i = 0; i < servos; ++i) {
    servoLegs[i].attach(i + 7);
    servoLegs[i].write(angle);
    delay(1000);
  }

  //начинаем калибровку сервоприводов
  Serial.println("write the value of the average position of the servo");
  Serial.println("if the middle position is found enter: 1");
  delay(500);
  // последовательная настройка сервоприводов с первого до последнего (servos)
  while (iter < servos) {
    //читаем информацию из монитора порта
    while (Serial.available() > 0) {         // ПОКА есть что то на вход
      strData += (char)Serial.read();        // забиваем строку принятыми данными
      recievedFlag = true;                   // поднять флаг что получили данные
      delay(2);                              // ЗАДЕРЖКА. Без неё работает некорректно!
    }
    intVar = strData.toInt(); //переводим строку в целое число
    if (recievedFlag) {                      // если данные получены
      //переход к следующему сервоприводу
      if (intVar == 1) {
        Serial.print("Middle position of ");
        Serial.print(iter);
        Serial.print(" servo is ");
        Serial.print(servoCenterConst[iter]);
        Serial.println(" degrees ");
        ++iter;
        delay(50);
      }
      //вывод отправленного значения угла и выставление сервопривода в него
      else {
        // отсылаем то, что получили
        Serial.print("The average position value for ");
        Serial.print(iter);
        Serial.print(" is ");
        Serial.println(strData);

        servoLegs[iter].write(intVar);
        servoCenterConst[iter] = intVar;
      }
      strData = "";                          // очистить
      recievedFlag = false;                  // опустить флаг
    }
  }

  //делаем отступы для вывода таблицы
  for (int i = 0; i < 3; ++i) {    
    Serial.println();
  }  
  
  //составляем заголовки
  Serial.print("Servo number");
  for (int i = 0; i < servos; ++i) {
    Serial.print('\t');
    Serial.print(i);
  }
  Serial.println();
  
  //выводим полученные углы
  Serial.print("angle ");
  Serial.print('\t');
  for (int i = 0; i < servos; ++i) { 
    Serial.print('\t');
    Serial.print(servoCenterConst[i]);
  }
  Serial.println();
}

void loop() {}
