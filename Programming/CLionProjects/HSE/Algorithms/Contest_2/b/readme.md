B. Города
=========

Ограничение времени

1 секунда

Ограничение памяти

64Mb

Ввод

стандартный ввод или input.txt

Вывод

стандартный вывод или output.txt

Петя и Вася играют в города. Правила игры такие:

*   Петя называет любой город;
*   Вася называет любой город, до которого можно доехать на машине из города, который назвал Петя;
*   Петя называет любой город, до которого можно доехать на машине из последнего города, который назвал Вася;
*   И т.д.

Города, называемые игроками, не должны повторяться. Если игрок не может назвать ни одного города по указанным выше правилам, этот игрок проиграл.

Считается, что из города А можно доехать на машине до города B, если существует последовательность городов (A, x1, …, xk, B), такая, что между любыми двумя соседними городами в этой последовательности есть автомобильная дорога.

Петя слышал, что недавно боты OpenAI победили пятёрку профессиональных игроков в Доту. Петя хочет написать такого же бота для игры в города, чтобы бот играл за Петю и всегда выигрывал. За помощью Петя обратился к вам.

Формат ввода
------------

На вход вашей программе подаются через пробел два числа n и m (1 ≤ n, m ≤ 105), где n – число городов, m – число запросов к вашей программе. Далее следуют m строк, каждая из строк представляет собой запрос одного из двух типов:

*   Символ "a" и через пробел два числа bi и ci (где 1 ≤ bi, ci ≤ n) – запрос на добавление дороги между городами с номерами bi и ci (дороги двусторонние, нумерация городов начинается с 1). В ответ на этот запрос ничего выводить не требуется;
*   Символ "c" – в ответ на этот запрос вы должны вывести номер города, с которого Пете надо начать игру, чтобы точно победить (в текущей конфигурации дорожной сети). Если таких городов нет, выведите -1; если таких городов несколько, выведите город с наименьшим номером.

Формат вывода
-------------

В ответ на каждый запрос типа "с" выведите с новой строки целое число, являющееся ответом.

### Пример 1

##### Ввод

```
2 2
a 1 2
c
```

##### Вывод

```
\-1```

### Пример 2

##### Ввод

```
4 8
a 1 3
c
a 1 2
c
a 1 4
c
a 2 4
c
```

##### Вывод

```
2
1
-1
-1```

### Пример 3

##### Ввод

```
7 14
a 2 4
c
a 2 6
c
a 2 5
c
a 4 7
c
a 4 5
c
a 5 6
c
a 5 7
c
```

##### Вывод

```
1
1
1
1
1
1
1```