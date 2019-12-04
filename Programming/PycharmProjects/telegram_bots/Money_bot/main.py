import telebot
import time

token = "864139805:AAEgLFkMmmhi7fzfom9TNv2YGEvbxaGTyD0"
bot = telebot.TeleBot(token)

# Ответы на запросы:
string_start = "Привествую тебя"


# Описание различных клавиатур
# Клавитура в стартовом положениии она же лавиатура со районами города
keyboard_start = telebot.types.ReplyKeyboardMarkup(resize_keyboard=True)
keyboard_start.row('Посмотреть посты о заработке')
keyboard_start.row('Баланс')
keyboard_start.row('Испытать удачу')


# set, состоящий из всех id пользователей
set_all_users_id = set()
# dict, хранящий {id: balance}
dict_users_id_balance = dict()
# dict, хранящий {id: time getting coins}
dict_users_id_time = dict()

# Загрузка всех id в set_all_users_id, dict_users_id_balance, dict_users_id_time
# из файла (будет загружать только при первом включении бота)
file_users_information = open("users_information.txt", 'r')
for line in file_users_information:
    temp_list = list(map(int, line.split()))
    set_all_users_id.add(temp_list[0])
    dict_users_id_balance.update({temp_list[0]: temp_list[1]})
    dict_users_id_time.update({temp_list[0]: temp_list[2]})
file_users_information.close()


# Обработка команды /start
@bot.message_handler(commands=["start"])
def start_message(message):
    if message.from_user.id not in set_all_users_id:
        set_all_users_id.add(message.from_user.id)
        dict_users_id_balance.update({message.from_user.id: 0})
        dict_users_id_time.update({message.from_user.id: 0})
        file_all_users_id = open("users_information.txt", 'a')
        file_all_users_id.write(str(message.from_user.id) + " 0 0\n")
        file_all_users_id.close()
    bot.send_message(message.from_user.id, string_start,
                     reply_markup=keyboard_start)


bot.polling(none_stop=True, interval=1)
