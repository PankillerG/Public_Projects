L. Итератор по контейнеру контейнеров
=====================================

Ограничение времени

1 секунда

Ограничение памяти

64Mb

Ввод

стандартный ввод или input.txt

Вывод

стандартный вывод или output.txt

Вам надо реализовать функцию MakeRange которая позволит итерироваться по произвольному контейнеру контейнеров с семантикой ForwardIterator (http://en.cppreference.com/w/cpp/concept/ForwardIterator):

template <typename OuterCollection>    
<implementation\_defined> MakeRange(const OuterCollection&);

Функция должна работать с произвольным контейнером, который имеет методы begin, end, возвращающие итераторы. Возвращаемое значение фунции MakeRange должно занимать константную память и позволять проитерироваться по контейнеру контейнеров за линейное время. Возвращаемое значение функции должно быть можно использовать в range-based for.

Например, код

const std::vector<std::vector<int>> data = {    
    {1, 2, 3},    
    {},    
    {4, 5, 6}};    
for (const auto x : MakeRange(data)) {    
    std::cout << x << ", ";    
}

Должен вывести 1, 2, 3, 4, 5, 6,

Примечания
----------

Вам требуется сдать только заголовочный файл с релизованной функцией MakeRange.

Возможно, Вам потребуется записать типы итераторов шаблонного типа-контейнера OuterCollection и внутреннего контейнера. Их можно записать так:

typename OuterCollection::const\_iterator    
typename OuterCollection::value\_type::const\_iterator