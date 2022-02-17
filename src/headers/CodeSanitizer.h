/*
  Санитайзер конфигурации для прошивки
  Позволяет не ломать голову, почему же ничего не компилируется
  или компилируется, но не работает
  (показывает почти все возможные ошибки конфигурации)
  Не воспринимать как панацею
  За облегчение передавать спасибо @toqsycc
*/

#pragma once

#ifndef DISABLE_SECURE_COMPILING

#if defined(COMPILE_FOR_MEGA2560) && defined(COMPILE_FOR_NANO328P)
#error "Неверно задана целевая платформа. Компиляция возможна только для одного из устройств!"
#endif

#if !defined(COMPILE_FOR_MEGA2560) && !defined(COMPILE_FOR_NANO328P)
#error "Целевая платформа не задана."
#endif

#if RGBD_CHANNELS != 3
#error "RGBD_CHANNELS должен быть равен 3."
#endif

#if !defined(RED_PWMC) || !defined(GRN_PWMC) || !defined(BLU_PWMC)
#error "RED_PWMC, GRN_PWMC или BLU_PWMC отсутствуют в файле конфигурации."
#endif

// Если вылезла эта ошибка, смотри ниже
#if (RED_PWMC < 1) || (GRN_PWMC < 1) || (BLU_PWMC < 1)
#error "Для RED_PWMC, GRN_PWMC или BLU_PWMC задан несуществующий пин или не задан вовсе."
#endif

#if !defined(TARGET_1) || !defined(TARGET_2) || !defined(TARGET_3) \
    || !defined(TARGET_4) || !defined(TARGET_5) || !defined(TARGET_6)
#error "Данные о мишени отсутствуют в файле конфигурации."
#endif

// Если вылезла эта ошибка, смотри ниже
#if (TARGET_1 < 1) || (TARGET_2 < 1) || (TARGET_3 < 1) \
    || (TARGET_4 < 1) || (TARGET_5 < 1) || (TARGET_6 < 1)
#error "Для мишени задан несуществующий пин или не задан вовсе."
#endif

#if !defined(TARGET_SIGN_1) || !defined(TARGET_SIGN_2) || !defined(TARGET_SIGN_3) \
    || !defined(TARGET_SIGN_4) || !defined(TARGET_SIGN_5) || !defined(TARGET_SIGN_6)
#error "Данные о датчике мишени отсутствуют в файле конфигурации."
#endif

#if !defined(PIN_NUM_BASE) || !defined(PIN_NUM_SIDE_1) || !defined(PIN_NUM_SIDE_2)
#error "Данные о шинах SPI отсутствуют в файле конфигурации."
#endif

// Если вылезла эта ошибка, смотри ниже
#if (PIN_NUM_BASE < 1) || (PIN_NUM_SIDE_1 < 1) || (PIN_NUM_SIDE_2 < 1)
#error "Для шин SPI задан несуществующий пин или не задан вовсе."
#endif

#if HIT_THRESHOLD < 0
#error "Слишком низкая пороговая чувствительность! Минимально допустимое значение - 0."
#endif

#if HIT_THRESHOLD > 1023
#error "Слишком высокая пороговая чувствительность! Максимально допустимое значение - 1023."
#endif

#if HP_VALUE < 1
#error "Количество хитпоинтов не может быть меньше 1!"
#endif

#if DAMAGE >= HP_VALUE
#error "Урон не может быть равен или превосходить количество хитпоинтов!"
#endif

#endif
