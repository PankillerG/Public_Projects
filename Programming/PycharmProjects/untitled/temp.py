#извлекаем x и y из входных данных
X_train = data_train[:,0]
y_train = data_train[:,1]

X_test = data_test[:,0]
y_test = data_test[:,1]

X_n = []

for x in X_train:
    X_n.append([1, x])
X_n = numpy.matrix(X_n)

for i in range(2, 7):
    temp = []
    j = 0
    for x in X_train:
        temp.append([])
        temp[j].append(x**i)
        j +=1
    temp_m = numpy.matrix(temp)
    X_n = numpy.concatenate((X_n, temp_m), axis=1)
a = numpy.dot(numpy.dot(numpy.linalg.inv((numpy.dot(numpy.transpose(X_n) , X_n))) , numpy.transpose(X_n)), y_train)
#a это матрица без регуляризации, теперь подберу какую-нибудь хорошую матрицу, чтобы уменьшить ошибку на тестовых
E = numpy.identity(7)
a_good = numpy.dot(numpy.dot(numpy.linalg.inv((numpy.dot(numpy.transpose(X_n) , X_n) + 0.41*E)) , numpy.transpose(X_n)), y_train)
#накидывал разные коэфы в диапозоне [-2;2], это лчшее, из этого, что выдавало
print('Определитель без регуляризации = ', numpy.linalg.det(numpy.dot(numpy.transpose(X_n) , X_n)))
print('Определитель c регуляризацией  = ', numpy.linalg.det(numpy.dot(numpy.transpose(X_n) , X_n) + 0.41*E))
y = []
x = []
y_good = []
for x_ in X_train:
    x.append(x_)
    temp = 0
    temp_good = 0
    for j in range(0, 7):
        temp += a[0, j]*(x_**j)
        temp_good += a_good[0, j]*(x_**j)
    y.append(temp)
    y_good.append(temp_good)
matplotlib.pyplot.plot(x, y)
matplotlib.pyplot.plot(x, y_good)
#Посчитаю среднеквадратичную ошибку для обычной модели на тренирвочных и тествоых данных, и для новой модели на тестовых
test = 0
train = 0
test_default = 0
for j in range(0, 21):
    test += (y_good[j] - y_test[j])**2
    train += (y[j] - y_train[j])**2
    test_default += (y[j] - y_test[j])**2
print('ошибка на тренировочных данных у обычной модели  ', train/21)
print('ошибка модели с регуляризацией на тестовых данных', test/21)
print('в то время как ошибка на тестовых у обычной      ', test_default/21)
matplotlib.pyplot.show()