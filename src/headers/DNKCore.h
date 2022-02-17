#pragma once

#include <Arduino.h>
 
/*
  Приводит заданное число таким образом, будто оно
  лежит на интервале [0.0; 1.0], где 1.0 - число,
  определённое maxValue.
  Фактически возвращает процент от maxValue в in.
  [!] Защита от in > maxValue не предусмотрена
  [!] От in < 0 тоже
*/
double RecastIntoInterval(int, int);

/*
  Генерирует меандр заданной частоты на заданном пине
  с заданным количеством периодов

  pin - пин, на котором будет выводиться сигнал
  frequency - частота сигнала
  cycles - количество периодов
  bSignal - начальное значение периода
    false - период начинается с LOW (по умолчанию)
    true - период начинается с HIGH
*/
void SquareWave(byte, unsigned int, byte, bool bSignal = false);

// То же самое, только для нескольких пинов "одновременно"
// (то есть с минимальной задержкой между ними)
void SquareWave(byte*, unsigned int, byte, bool bSignal = false);
