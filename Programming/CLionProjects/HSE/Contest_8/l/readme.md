L. UTF-8: декодирование
=======================

Ограничение времени

1 секунда

Ограничение памяти

64Mb

Ввод

стандартный ввод или input.txt

Вывод

стандартный вывод или output.txt

В кодировке UTF-8 каждый символ из таблицы Unicode кодируется одним, двумя, тремя или четыремя байтами в зависимости от своего кода. Последовательности байтов могут иметь вид либо 0xxxxxxx, либо 110xxxxx 10xxxxxx, либо 1110xxxx 10xxxxxx 10xxxxxx, либо 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx. Биты, обозначенные символом x, склеиваются вместе и образуют код закодированного символа. Вам требуется по заданной последовательности байтов UTF-8 выписать коды закодированных символов.

Формат ввода
------------

На вход подаётся набор байтов (текст, закодированный в UTF-8). Вы можете считать его в std::string. Размер текста не превосходит 1024 байт.

### Пример 1

##### Ввод

```
Hello!
```

##### Вывод

```
72 101 108 108 111 33 
```

### Пример 2

##### Ввод

```
Привет, мир!
```

##### Вывод

```
1055 1088 1080 1074 1077 1090 44 32 1084 1080 1088 33 
```

Примечания
----------

Выпишите коды закодированных символов в десятичной системе счисления через пробел.