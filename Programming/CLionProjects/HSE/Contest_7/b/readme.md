B. Матрица - 2
==============

Ограничение времени

1 секунда

Ограничение памяти

64Mb

Ввод

стандартный ввод или input.txt

Вывод

стандартный вывод или output.txt

Добавьте в предыдущий класс следующие методы:

1.  operator +=, принимающий константную ссылку на вторую матрицу того же типа и размера. Заметьте, что оператор должен вернуть ссылку на класс.
2.  Константный operator +, принимающий константную ссылку на вторую матрицу того же типа и размера и возвращающий сумму матриц.
3.  Шаблонный operator \*=, принимающий константную ссылку на число (не обязательно типа T) и умножающий матрицу на этот скаляр. Заметьте, что оператор должен вернуть ссылку на класс.
4.  Шаблонный константный operator \*, принимающий константную ссылку на число (не обязательно типа T) и возвращающий матрицу, умноженную на этот скаляр.

Убедитесь также, что в программе присутствуют операторы присваивания и конструктор копирования (при корректной реализации задачи хватит стандартных, которые автоматически генерирует компилятор), а также оператор вывода из предыдущей задачи.