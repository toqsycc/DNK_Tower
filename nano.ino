byte *pins;
byte pwm(0xFF);

void SquareWave(byte *pins, unsigned int frequency, byte cycles, bool bSignal)
{
  unsigned int msDuration = 1000 / (2 * frequency);
  byte *parallelPins = new byte[6]{ 0 };
  byte pinsCounter(0);

  /*
    Займём несколько тактов в начале для оптимизации:
    "Переупаковка" полученного массива для избежания "пробелов"
    Это позволит не тратить время на if в основном цикле
    Однако, время будет потрачено зря, если все шесть ячеек содержали
    ненулевую информацию. Добавление проверки на "пробелы" увеличит
    задержку перед стартом ещё на 6N тактов, что неприемлемо.
  */
  for (byte i(0); i < 6; i++)
  {
    if (pins[i])
      // Перемещаем пин во внутренний массив, затем инкрементируем счётчик
      parallelPins[pinsCounter++] = pins[i];
    else continue;
  }

  /*
    После оптимизации наконец-то можно на максимально возможной скорости
    реализовать параллельное управление пинами
  */
  for (byte i(1); i <= 2 * cycles; i++)
  {
    if (i % 2)
      for (byte j(0); j < pinsCounter; j++)
        digitalWrite(parallelPins[j], bSignal);
    else
      for (byte j(0); j < pinsCounter; j++)
        digitalWrite(parallelPins[j], !bSignal);
    delay(msDuration);
  }
}

void setup() {
  // put your setup code here, to run once:
  pins = new byte[6]
  {
    2, 3, 4, 5, 6, 7
  };
  for (byte i(0); i < 6; i++)
    pinMode(pins[i], OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(74880);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!pwm) pwm = 0xFF;
  analogWrite(8, pwm);
  pwm -= 0x08;
  Serial.println(pwm);
  delay(100);
  analogWrite(8, 0);
  //SquareWave(pins, 20, 8, true);
  
}
