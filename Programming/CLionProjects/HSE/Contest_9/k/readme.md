K. Callback
===========

Ограничение времени

1 секунда

Ограничение памяти

64Mb

Ввод

стандартный ввод или input.txt

Вывод

стандартный вывод или output.txt

Вам даны классы Tokenizer и CallbackBase: [https://clck.ru/CdyQH](https://clck.ru/CdyQH).

Класс Tokenizer умеет каким-то способом разбивать текстовую строчку на фрагменты (токены). Токены могут быть словами, предложениями, фрагментами слов - сейчас это не важно.

В классе Tokenizer есть функция Tokenize. Она принимает на вход строчку, а также указатель на CallbackBase. Что это и зачем нужно?

Обрабатываемый текст может быть очень большим, и записывать все найденные токены в отдельный массив может быть расточительным. Часто бывает достаточно для каждого очередного найденного токена просто выполнить какое-то действие и пойти дальше, не сохраняя все токены в памяти. В базовом классе CallbackBase есть виртуальная функция OnToken, которую Tokenize будет вызывать всякий раз, когда обнаружит новый токен. Обратите внимание, что OnToken получает на вход const char \* и size\_t, а не std::string. Действительно, зачем копировать подстроку для каждого токена и создавать новый std::string? Достаточно просто передать указатель на начало очередного токена в уже существующей исходной строке, и его длину.

Вы можете унаследоваться от CallbackBase и реализовать OnToken по-своему. Например, при вызове OnToken вы можете сохранять в своём классе-наследнике какие-то статистические данные.

Напишите программу с функцией main, которая

*   получает строчку со стандартного ввода с помощью std::getline;
*   создаёт объект типа Tokenizer;
*   вызывает у него функцию Tokenize и передаёт ей эту строчку и указатель на ваш особый Callback-объект.

Программа должна подсчитать и напечатать через пробел два числа: количество токенов в строке и длину максимального токена.

Начните свою программу со строки #include "tokenizer.h", чтобы подключить наши версии классов Tokenizer и CallbackBase.