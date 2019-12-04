B. Ambitious Experiment
=======================

Ограничение времени

4 секунды

Ограничение памяти

256Mb

Ввод

стандартный ввод или input.txt

Вывод

стандартный вывод или output.txt

Учёные с планеты Нибиру уже несколько десятилетий трудятся над созданием двигателя, который позволит космическим кораблям попадать в гиперпространство и двигаться там со сверхсветовой скоростью. Чтобы проверить, верны ли их представления о свойствах гиперпространства, учёные разработали следующий эксперимент.

В гиперпространство помещают цепочку из n частиц, позиции в которой пронумерованы от 1 до n. Изначально i\-я частица имеет заряд ai.

Согласно современной теории, если на частицу с номером i попадает специальное излучение мощности d, по гиперпространству распространяются колебания, которые увеличивают на d заряд частиц под номерами i, 2i, 3i и т. д. (то есть под номерами, которые делятся на i).

С помощью специального прибора учёные могут направить излучение одинаковой мощности на отрезок соседних частиц. Например, пусть изначально было 6 частиц с нулевыми зарядами, и учёные направили излучение мощности 5 на частицы с номерами 2 и 3. Тогда заряд частиц с номерами 2, 3, 4 повысится до пяти, а заряд частицы с номером 6 — до десяти (колебания настигнут её дважды). Заряд остальных частиц не изменится.

Без воздействия прибора заряд частиц в эксперименте меняться не может.

В течение эксперимента учёные планируют выполнять действия следующих типов:

1.  Измерить текущий заряд частицы с номером i.
2.  Направить излучение мощности d на частицы с номерами от l до r включительно.

Вашей программе будет дан список выполненных действий. На каждое действие первого типа она должна выдать ожидаемый заряд частицы, рассчитанный согласно современной теории, описанной выше.

Если ожидаемый заряд частиц совпадёт с зарядом, измеренным во время эксперимента, представления учёных о природе гиперпространства окажутся верными, и они смогут приступить к постройке гипердвигателей. Тогда всего через несколько лет жители Нибиру наконец-то встретятся со своими братьями с Земли!

Формат ввода
------------

Первая строка содержит единственное число n — количество частиц (1 ≤ n ≤ 3 ⋅ 105).

Вторая строка содержит n целых чисел ai, записанных через пробел — начальные заряды частиц (0 ≤ ai ≤ 106).

Третья строка содержит единственное число q — количество действий в эксперименте (1 ≤ q ≤ 3 ⋅ 105).

В следующих q строках вводится либо два, либо четыре целых числа через пробел — описание очередного действия в одном из следующих форматов:

*   1 i — измерить заряд частицы с номером i (1 ≤ i ≤ n).
*   2 l r d — направить излучение мощности d на частицы с номерами от l до r включительно (1 ≤ l ≤ r ≤ n, 0 ≤ d ≤ 106).

Формат вывода
-------------

Для каждого запроса первого типа выведите ожидаемый заряд i\-й частицы.

### Пример 1

##### Ввод

```
3
1 2 3
2
2 1 3 5
1 2
```

##### Вывод

```
12
```

### Пример 2

##### Ввод

```
6
1 2 1 4 5 6
5
2 2 4 2
1 3
1 4
2 3 5 1
1 5
```

##### Вывод

```
3
8
6
```

[Скачать условие задачи](/contest/12717/download/B/)