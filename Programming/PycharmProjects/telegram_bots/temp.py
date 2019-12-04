import telebot
import random
import time

token = "459513087:AAEb5Pid7fZaG7cSWf6-ZwXtXWYF5cUZo58"
bot = telebot.TeleBot(token)
#bot.send_message(150288882, "Test")
#upd = bot.get_updates()
#print(upd)
#last_upd = upd[-1]
#message_from_user = last_upd.message
#print(message_from_user)

inf = dict()
i=1
k=0
print(bot.get_me())

file_users_information = open('users_inforamtion.txt', 'r')
for line in file_users_information:
    s = line
    n = s.find(' ')
    key = s[0:n]
    s = s[n:]
    money = s[:]
    inf[int(key, 10)]= int(money, 10)
file_users_information.close()

def log(message, answer):
    print("\n -----")
    from datetime import datetime
    print(datetime.now())
    print("Сообщение от {0} {1}. (id = {2}) \n Текст - {3}".format(message.from_user.first_name,
                                                                   message.from_user.last_name,
                                                                   str(message.from_user.id),
                                                                   message.text))
    print('Ответ бота: ', answer)
    #print(message.from_user.id, inf[message.from_user.id])
    #print(inf[message.from_user.id])

#стартовая команда
@bot.message_handler(commands=['start'])
def handle_text(message):
    user_markup = telebot.types.ReplyKeyboardMarkup(True, False)
    user_markup.row('Начать')
    user_markup.row('Пополнить', 'Вывести')
    user_markup.row('Информация о вас', 'Информация о нас')
    bot.send_message(message.from_user.id,
                     'Рады вас привествовать',
                     reply_markup=user_markup)
    #mass_number.append(message.from_user.id)
    #mass_money.append(0)
    #inf = dict.update({'message.from_user.id': '0'})
    if not message.from_user.id in inf:
        inf[message.from_user.id]=0
        k=inf[message.from_user.id]
        file_users_information = open('users_inforamtion.txt', 'a')
        file_users_information.write(str(message.from_user.id) + ' ' + str(k) + '\n')
        file_users_information.close()

#Отсылка сообщения каждому пользователю
#file_users_information = open('users_inforamtion.txt', 'r')
#for line in file_users_information:
#    s = line
#    n = s.find(' ')
#    key = s[0:n]
#    answer = "Бот в стадии тестирования, поэтому выплаты не осуществляем"
#    bot.send_message(int(key,10), answer)

#Основной раздел
@bot.message_handler(content_types=['text'])
def handle_text(message):
    if message.text == "Начать":
        hide_markup = telebot.types.ReplyKeyboardRemove()
        bot.send_message(message.from_user.id,
                         'Ссылка на канал с отзывами и обновлениями: https://t.me/LuckyWheel',
                         reply_markup=hide_markup)
        user_markup = telebot.types.ReplyKeyboardMarkup(True, False)
        user_markup.row('Угадать число(10р)')
        user_markup.row('Угадать число(100р)')
        user_markup.row('Игры в разработке')
        user_markup.row('В начало')
        bot.send_message(message.from_user.id,
                         'Выберете игру:',
                         reply_markup=user_markup)

    elif message.text == "В начало":
        file_users_information = open('users_inforamtion.txt', 'r')
        file_users_information_for_update = open('users_information_for_update.txt', 'w')
        for line in file_users_information:
            s = line
            n = s.find(' ')
            key = s[0:n]
            if int(key, 10) == message.from_user.id:
                file_users_information_for_update.write(str(message.from_user.id) + ' ' +
                                                        str(inf[message.from_user.id]) + '\n')
            else:
                file_users_information_for_update.write(line)
        file_users_information.close()
        file_users_information_for_update.close()
        file_users_information = open('users_inforamtion.txt', 'w')
        file_users_information_for_update = open('users_information_for_update.txt', 'r')
        for line in file_users_information_for_update:
            s = line
            if not s == (''):
                file_users_information.write(line)
        file_users_information.close()
        file_users_information_for_update.close()
        hide_markup = telebot.types.ReplyKeyboardRemove()
        bot.send_message(message.from_user.id,
                         'Ссылка на канал с отзывами и обновлениями: https://t.me/LuckyWheel',
                         reply_markup=hide_markup)
        user_markup = telebot.types.ReplyKeyboardMarkup(True, False)
        user_markup.row('Начать')
        user_markup.row('Пополнить', 'Вывести')
        user_markup.row('Информация о вас', 'Информация о нас')
        bot.send_message(message.from_user.id,
                         'Выберете раздел',
                         reply_markup=user_markup)

    elif message.text == "Пополнить":
        #answer = "Переводы принимаем только на счет QIWI: \n " \
        #         "+79619725654 \n " \
        #         "В комментарий обязательно укажите данный код: {0} \n" \
        #         "Иначе платеж не будет принят".format(str(message.from_user.id))
        answer = "Из-за того что проходит тестовый режим бота, вы можете бесплатно свой пополнить баланс"
        log(message, answer)
        bot.send_message(message.chat.id, answer)
        hide_markup = telebot.types.ReplyKeyboardRemove()
        bot.send_message(message.from_user.id,
                         'Ссылка на канал с отзывами и обновлениями: https://t.me/LuckyWheel',
                         reply_markup=hide_markup)
        user_markup = telebot.types.ReplyKeyboardMarkup(True, False)
        user_markup.row('+100')
        user_markup.row('В начало')
        bot.send_message(message.from_user.id,
                         'Выберете сумму для пополнения:',
                         reply_markup=user_markup)


    elif message.text == "+100":
        if inf[message.from_user.id] < 500:
            file_users_information = open('users_inforamtion.txt', 'r')
            file_users_information_for_update = open('users_information_for_update.txt', 'w')
            for line in file_users_information:
                s = line
                n = s.find(' ')
                key = s[0:n]
                if int(key, 10) == message.from_user.id:
                    inf[message.from_user.id] = inf[message.from_user.id] +100
                    file_users_information_for_update.write(str(message.from_user.id) + ' ' +
                                                            str(inf[message.from_user.id]) + '\n')
                else:
                    file_users_information_for_update.write(line)
            file_users_information.close()
            file_users_information_for_update.close()
            file_users_information = open('users_inforamtion.txt', 'w')
            file_users_information_for_update = open('users_information_for_update.txt', 'r')
            for line in file_users_information_for_update:
                s = line
                if not s == (''):
                    file_users_information.write(line)
            file_users_information.close()
            file_users_information_for_update.close()
            answer = "Ваш баланс пополнен на 100 р. и составляет: {0} р.".format(inf[message.from_user.id])
            log(message, answer)
            bot.send_message(message.chat.id, answer)
        else:
            answer = "На вашем счету уже имеются средства. \n Ваш баланс: {0} р.".format(inf[message.from_user.id])
            log(message, answer)
            bot.send_message(message.chat.id, answer)
    elif message.text == "Информация о нас":
        answer = "Лучшее место, где можно проверить свою удачу \n " \
                 "Ссылка на канал с отзывами и обновлениями: \n https://t.me/LuckyWheel"
        log(message, answer)
        bot.send_message(message.chat.id, answer)
    elif message.text == "Информация о вас":
        file_users_information = open('users_inforamtion.txt', 'r')
        for line in file_users_information:
            s = line
            n = s.find(' ')
            key = s[0:n]
            s = s[n:]
            money = s[:]
            inf[int(key, 10)] = int(money, 10)
        file_users_information.close()
        answer = "Ваше Имя: {0} \n Ваш ID: {2} \n Ваш баланс: {3} р.".format(message.from_user.first_name,
                                                                             message.from_user.last_name,
                                                                             str(message.from_user.id),
                                                                             inf[message.from_user.id])
        log(message,answer)
        bot.send_message(message.chat.id,answer)



    elif message.text == "Угадать число(10р)":
        hide_markup = telebot.types.ReplyKeyboardRemove()
        bot.send_message(message.from_user.id,
                         'Ссылка на канал с отзывами и обновлениями: https://t.me/LuckyWheel',
                         reply_markup=hide_markup)
        user_markup = telebot.types.ReplyKeyboardMarkup(True, False)
        user_markup.row('10Число 0')
        user_markup.row('10Число 1')
        user_markup.row('В начало')
        bot.send_message(message.from_user.id, 'Ставка 10р. Выигрывая, вы получаете +10р. на баланс. При проигрыше спишется 10р. с баланса.'
                                               '\n После выбора числа, вы сразу узнаете результат игры', reply_markup=user_markup)
    elif message.text == "10Число 0":
        if inf[message.from_user.id] >= 10:
            #t = random.randint(1, 3)
            #bot.send_message(message.from_user.id, 'В связи с большим количеством участников будет задержка ответа (1-3c)')
            #time.sleep(t)
            random_text = message.text
            random_text = random_text[8:]
            random0_1 = random.randint(0, 1)
            if int(random_text,10) == random0_1:
                inf[message.from_user.id] = inf[message.from_user.id] + 10
                answer = ('Вы выиграли, ваш баланс увеличен на 10 р. \n И составляет: {0} р.'.format(inf[message.from_user.id]))
                log(message,answer)
                bot.send_message(message.from_user.id, answer)
            else:
                inf[message.from_user.id] = inf[message.from_user.id] - 10
                answer = ('Вы проиграли, ваш баланс уменьшился на 10р. \n И составляет: {0} р.'.format(inf[message.from_user.id]))
                log(message, answer)
                bot.send_message(message.from_user.id, answer)
        else:
            answer = ('У вас недостаточно средств для игры, пожалуйста, пополните баланс. \n Ваш баланс: {0} р.'.format(inf[message.from_user.id]))
            log(message, answer)
            bot.send_message(message.from_user.id, answer)
    elif message.text == "10Число 1":
        if inf[message.from_user.id] >= 10:
            #t = random.randint(1, 3)
            #bot.send_message(message.from_user.id, 'В связи с большим количеством участников будет задержка ответа (1-3c)')
            #time.sleep(t)
            random_text = message.text
            random_text = random_text[8:]
            random0_1 = random.randint(0, 1)
            if int(random_text,10) == random0_1:
                inf[message.from_user.id] = inf[message.from_user.id] + 10
                answer = ('Вы выиграли, ваш баланс увеличен на 10 р. \n И составляет: {0} р.'.format(inf[message.from_user.id]))
                log(message,answer)
                bot.send_message(message.from_user.id, answer)
            else:
                inf[message.from_user.id] = inf[message.from_user.id] - 10
                answer = ('Вы проиграли, ваш баланс уменьшился на 10р. \n И составляет: {0} р.'.format(inf[message.from_user.id]))
                log(message, answer)
                bot.send_message(message.from_user.id, answer)
        else:
            answer = ('У вас недостаточно средств для игры, пожалуйста, пополните баланс. \n Ваш баланс: {0} р.'.format(inf[message.from_user.id]))
            log(message, answer)
            bot.send_message(message.from_user.id, answer)

    elif message.text == "Угадать число(100р)":
        hide_markup = telebot.types.ReplyKeyboardRemove()
        bot.send_message(message.from_user.id,
                         'Ссылка на канал с отзывами и обновлениями: https://t.me/LuckyWheel',
                         reply_markup=hide_markup)
        user_markup = telebot.types.ReplyKeyboardMarkup(True, False)
        user_markup.row('100Число 0')
        user_markup.row('100Число 1')
        user_markup.row('В начало')
        bot.send_message(message.from_user.id, 'Ставка 100р. Выигрывая, вы получаете +100р. на баланс. При проигрыше спишется 100р. с баланса.'
                                               '\n После выбора числа, вы сразу узнаете результат игры', reply_markup=user_markup)
    elif message.text == "100Число 0":
        if inf[message.from_user.id] >= 100:
            #t = random.randint(1, 3)
            #bot.send_message(message.from_user.id, 'В связи с большим количеством участников будет задержка ответа (1-3c)')
            #time.sleep(t)
            random_text = message.text
            random_text = random_text[9:]
            random0_1 = random.randint(0, 1)
            if int(random_text,10) == random0_1:
                inf[message.from_user.id] = inf[message.from_user.id] + 100
                answer = ('Вы выиграли, ваш баланс увеличен на 100 р. \n И составляет: {0} р.'.format(inf[message.from_user.id]))
                log(message,answer)
                bot.send_message(message.from_user.id, answer)
            else:
                inf[message.from_user.id] = inf[message.from_user.id] - 100
                answer = ('Вы проиграли, ваш баланс уменьшился на 100р. \n И составляет: {0} р.'.format(inf[message.from_user.id]))
                log(message, answer)
                bot.send_message(message.from_user.id, answer)
        else:
            answer = ('У вас недостаточно средств для игры, пожалуйста, пополните баланс. \n Ваш баланс: {0} р.'.format(inf[message.from_user.id]))
            log(message, answer)
            bot.send_message(message.from_user.id, answer)
    elif message.text == "100Число 1":
        if inf[message.from_user.id] >= 100:
            #t = random.randint(1, 3)
            #bot.send_message(message.from_user.id, 'В связи с большим количеством участников будет задержка ответа (1-3c)')
            #time.sleep(t)
            random_text = message.text
            random_text = random_text[9:]
            random0_1 = random.randint(0, 1)
            if int(random_text,10) == random0_1:
                inf[message.from_user.id] = inf[message.from_user.id] + 100
                answer = ('Вы выиграли, ваш баланс увеличен на 100 р. \n И составляет: {0} р.'.format(inf[message.from_user.id]))
                log(message,answer)
                bot.send_message(message.from_user.id, answer)
            else:
                inf[message.from_user.id] = inf[message.from_user.id] - 100
                answer = ('Вы проиграли, ваш баланс уменьшился на 100р. \n И составляет: {0} р.'.format(inf[message.from_user.id]))
                log(message, answer)
                bot.send_message(message.from_user.id, answer)
        else:
            answer = ('У вас недостаточно средств для игры, пожалуйста, пополните баланс. \n Ваш баланс: {0} р.'.format(inf[message.from_user.id]))
            log(message, answer)
            bot.send_message(message.from_user.id, answer)




    else:
        answer = "Бот еще разрабатывается"
        log(message,answer)
        bot.send_message(message.chat.id, answer)



#if message.text == "1":
        #bot.send_message(message.chat.id,"вывод 1")

bot.polling(none_stop=True, interval=0)