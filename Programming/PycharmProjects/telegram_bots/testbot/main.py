import telebot

token = "867183926:AAHBptOQqfZR0pFRkItOsofbNn-RbFOigBU"
bot = telebot.TeleBot(token)

list_id_money = dict()
file_id = open("id.txt", 'r')
for line in file_id:
    id = line[:line.find(" ")]
    money = int(line[line.find(" ") + 1:-1])
    list_id_money[id] = money
file_id.close()

standart_keyboard = telebot.types.ReplyKeyboardMarkup()
standart_keyboard.row('Смотреть рекламу', 'Мой баланс')

@bot.message_handler(commands=["start"])
def start_message(message):
    start_keyboard = telebot.types.ReplyKeyboardMarkup()
    start_keyboard.row('Смотреть рекламу', 'Мой баланс')
    bot.send_message(message.from_user.id, "Привествую тебя!",
                     reply_markup=start_keyboard)
    if str(message.from_user.id) not in list_id_money:
        list_id_money[str(message.from_user.id)] = 0


@bot.message_handler(commands=["save"])
def start_message(message):
    start_keyboard = telebot.types.ReplyKeyboardMarkup()
    start_keyboard.row('Смотреть рекламу', 'Мой баланс')
    file_id = open("id.txt", 'w')
    for key in list_id_money:
        file_id.write(key + " " + str(list_id_money[key]) + "\n")
    file_id.close()
    bot.send_message(message.from_user.id, "Информация бота сохранена",
                     reply_markup=start_keyboard)


@bot.message_handler(content_types=["text"])
def handle_text(message):
    if message.text == "Смотреть обычную рекламу":
        advertising_keyboard = telebot.types.ReplyKeyboardMarkup()
        advertising_keyboard.row('Смотреть рекламу', 'Мой баланс', '/save')
        bot.send_message(message.from_user.id, "https://www.instagram.com/pankillerg/?hl=ru",
                         reply_markup=advertising_keyboard)
        bot.send_message(message.from_user.id, "ПАШЕЛ НАХУЙ, но твой баланс увеличен",
                         reply_markup=advertising_keyboard)
        list_id_money[str(message.from_user.id)] += 1
    elif message.text == "Мой баланс":
        balance_keyboard = telebot.types.ReplyKeyboardMarkup()
        balance_keyboard.row('Смотреть рекламу', 'Мой баланс')
        bot.send_message(message.from_user.id, "Баланс: " + str(list_id_money[str(message.from_user.id)]),
                         reply_markup=balance_keyboard)
    elif message.text in ["test", "test2"]:
        bot.send_message(message.from_user.id, "test finished with no exсeption")
    else:
        bot.send_message(message.from_user.id, "Разраб долбоеб, еще не написал такую обработку")


bot.polling(none_stop=True, interval=1)
