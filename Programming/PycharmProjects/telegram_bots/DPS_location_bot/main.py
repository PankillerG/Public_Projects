import telebot
import time

token = "897142888:AAHnwr4ha5r0K5kXlBMhoHlAwLg-mAHYCaE"

bot = telebot.TeleBot(token)

# Нужные значения
# Время хранения записей в секундах:
time_saving_information = 7200  # 900 секунд = 15 минут


# Ответы на запросы:
# Приветствие при старте
string_start = "Приветствую тебя!\n" \
               "Наш бот хранит информацию не более " + str(time_saving_information // 60) + " минут\n"\
               "Выберите район, о котором хотите узнать информацию или сообщите информацию нам:"
# Основная часть
string_main_part = "Наш бот хранит информацию не более " + str(time_saving_information // 60) + " минут\n"\
                   "Выберите район, о котором хотите узнать информацию или сообщите информацию нам:"
# Перед тем как добавить информацию
string_before_update = "Напишите улицу или более точное местоположение ДПС, используя обычную клавиатуру телефона " \
                       "или /menu, чтобы вернуться в начало"
# После того, как была добавлена информация
string_after_update = "Спасибо, информация обновлена"
# Неизвестный запрос
string_unidentified_request = "Данный запрос я не могу обработать"


# Описание различных клавиатур
# Клавитура в стартовом положениии она же лавиатура со районами города
keyboard_start = telebot.types.ReplyKeyboardMarkup(resize_keyboard=True)
keyboard_start.row('Окружная')
keyboard_start.row('Дзержинский', 'Заволжский')
keyboard_start.row('Кировский', 'Красноперекопский')
keyboard_start.row('Ленинский', 'Фрунзенский')
keyboard_start.row('Сообщить о местонахождении ДПС')

# Клавиатура с районами города для сообщения о местоположения ДПС
keyboard_locations = telebot.types.ReplyKeyboardMarkup(resize_keyboard=True)
keyboard_locations.row('Окружная (Чурик)')
keyboard_locations.row('Дзержинский р.', 'Заволжский р.')
keyboard_locations.row('Кировский р.', 'Красноперекопский р.')
keyboard_locations.row('Ленинский р.', 'Фрунзенский р.')
keyboard_locations.row('В начало')

# Клавиатура перед тем, как человек вводить более точную информацию об локации ДПС
keyboard_before_update = telebot.types.ReplyKeyboardMarkup(resize_keyboard=True)
keyboard_before_update.row('В начало')

# Клавиатура перед тем, как человек вводить более точную информацию об локации ДПС
keyboard_remove = telebot.types.ReplyKeyboardRemove()

# Dictionary, где храниться локация и время записи для каждого района
# Дзержинский район
dict_location_1 = {}
# Заволжский район
dict_location_2 = {}
# Кировский район
dict_location_3 = {}
# Красноперекопский район
dict_location_4 = {}
# Ленинский район
dict_location_5 = {}
# Фрунзенский район
dict_location_6 = {}
# Окружная
dict_location_7 = {}

# set для каждого района, где храняться все люди(их id), сделавшие запрос на добавление новой информации
# Дзержинский район
set_id_location_1 = set()
# Заволжский район
set_id_location_2 = set()
# Кировский район
set_id_location_3 = set()
# Красноперекопский район
set_id_location_4 = set()
# Ленинский район
set_id_location_5 = set()
# Фрунзенский район
set_id_location_6 = set()
# Окружная
set_id_location_7 = set()

# set, состоящий из всех id админов
set_admins_id = set()
# Загрузка всех id админов в set_admins_id из файла (будет загружать только при первом включении бота)
file_admins_id = open("admins_id.txt", 'r')
for line in file_admins_id:
    set_admins_id.add(line.strip())
file_admins_id.close()

# set, состоящий из всех id пользователей
set_all_users_id = set()
# Загрузка всех id в set_all_users_id из файла (будет загружать только при первом включении бота)
file_all_users_id = open("users_id.txt", 'r')
for line in file_all_users_id:
    set_all_users_id.add(line.strip())
file_all_users_id.close()

# set из слов, которые бллокируются ботом
file_stop_words = open("stop_words.txt", 'r')
set_stop_words = set(set(file_stop_words.read().split()))
file_stop_words.close()


# Функции
# Функция для вывода актуальной информации (происходит проверка на актуальность)
def check_information_for_relevance(container, message):
    local_time = time.time() // 1  # Замеряем время для отбрасывания старых данных
    local_list_for_removing = []  # list, в котором храняться данные на удаление
    local_flag = True  # Флаг, если True - актуальной информации нет, False - иначе
    string_answer = "ДПС стоят:\n"  # Строка с ответом на запрос
    for key in container:
        if (local_time - container[key]) > time_saving_information:
            local_list_for_removing.append(key)
        else:
            local_flag = False
            string_answer += key + " (" + str(int((local_time - container[key]) // 60)) + " минут назад)" + "\n\n"
    if local_flag:
        bot.send_message(message.from_user.id, "Данные по этому району не найдены",
                         reply_markup=keyboard_start)
    else:
        bot.send_message(message.from_user.id, string_answer,
                         reply_markup=keyboard_start)
    for el in local_list_for_removing:
        del container[el]


# Функция удаляет id пользователя из каждого set
def delete_id_from_all_sets(id):
    set_id_location_1.discard(id)
    set_id_location_2.discard(id)
    set_id_location_3.discard(id)
    set_id_location_4.discard(id)
    set_id_location_5.discard(id)
    set_id_location_6.discard(id)
    set_id_location_7.discard(id)


# Функция, добавляющая id пользователя в нужный set, перед считыванием более точной локации
def before_update_information(container, message):
    delete_id_from_all_sets(message.from_user.id)
    container.add(message.from_user.id)
    bot.send_message(message.from_user.id, string_before_update,
                     reply_markup=keyboard_remove)


# Функция, добавляющая новую информацию в выбранный район и удаляющая пользователя из set
def after_update_information(local_dict, local_set, message):
    if len(set(message.text.split()) & set_stop_words) == 0:
        local_dict.update({message.text: time.time() // 1})
        local_set.discard(id)
        bot.send_message(message.from_user.id, string_after_update,
                         reply_markup=keyboard_start)
    else:
        local_set.discard(id)
        bot.send_message(message.from_user.id, "Ваша фараза содержит запретные слова",
                         reply_markup=keyboard_start)


# Обработка команды /start
@bot.message_handler(commands=["start"])
def start_message(message):
    if str(message.from_user.id) not in set_all_users_id:
        set_all_users_id.add(str(message.from_user.id))
        file_all_users_id = open("users_id.txt", 'a')
        file_all_users_id.write(str(message.from_user.id) + "\n")
        file_all_users_id.close()
    bot.send_message(message.from_user.id, string_start,
                     reply_markup=keyboard_start)


# Обработка команды /menu
@bot.message_handler(commands=["menu"])
def menu_message(message):
    bot.send_message(message.from_user.id, string_main_part,
                     reply_markup=keyboard_start)


# Обработка команды /Рассылка
@bot.message_handler(commands=["Рассылка"])
def advertising_message(message):
    if str(message.from_user.id) in set_admins_id and len(message.text) > 10:
        for el in set_all_users_id:
            try:
                bot.send_message(int(el.strip()), (message.text[10:]),
                                 reply_markup=keyboard_start)
            except:
                continue


# Обработка команды /Статистика
@bot.message_handler(commands=["Статистика"])
def statistics_message(message):
    if str(message.from_user.id) in set_admins_id:
        bot.send_message(message.from_user.id, "Количество пользователей: " + str(len(set_all_users_id)) +
                                               "\nКоличество админов: " + str(len(set_admins_id)),
                         reply_markup=keyboard_start)


# Обработка команды /update_admins
@bot.message_handler(commands=["update_admins"])
def update_message(message):
    if str(message.from_user.id) in set_admins_id:
        set_admins_id.clear()
        file_admins_id = open("admins_id.txt", 'r')
        for line in file_admins_id:
            set_admins_id.add(line.strip())
        file_admins_id.close()
        bot.send_message(message.from_user.id, "Список админов обновлен",
                         reply_markup=keyboard_start)


# Обработка команды /update_stop_words
@bot.message_handler(commands=["update_stop_words"])
def update_message(message):
    if str(message.from_user.id) in set_admins_id:
        set_stop_words.clear()
        file_stop_words = open("stop_words.txt", 'r')
        set_stop_words.update(set(set(file_stop_words.read().split())))
        file_stop_words.close()
        bot.send_message(message.from_user.id, "Список запретных слов обновлен",
                         reply_markup=keyboard_start)


# Обработка текстовых сообщений
@bot.message_handler(content_types=["text"])
def handle_text(message):
    # Обработка главного меню
    if message.text == "Дзержинский":
        check_information_for_relevance(dict_location_1, message)

    elif message.text == "Заволжский":
        check_information_for_relevance(dict_location_2, message)

    elif message.text == "Кировский":
        check_information_for_relevance(dict_location_3, message)

    elif message.text == "Красноперекопский":
        check_information_for_relevance(dict_location_4, message)

    elif message.text == "Ленинский":
        check_information_for_relevance(dict_location_5, message)

    elif message.text == "Фрунзенский":
        check_information_for_relevance(dict_location_6, message)

    elif message.text == "Окружная":
        check_information_for_relevance(dict_location_7, message)

    elif message.text == "В начало":
        delete_id_from_all_sets(message.from_user.id)
        bot.send_message(message.from_user.id, string_main_part,
                         reply_markup=keyboard_start)

    elif message.text == "Сообщить о местонахождении ДПС":
        delete_id_from_all_sets(message.from_user.id)
        bot.send_message(message.from_user.id, "Выберет район, о котором вы хотите сообщить",
                         reply_markup=keyboard_locations)

    # Обработка раздела с добавлением информации
    elif message.text == "Дзержинский р.":
        before_update_information(set_id_location_1, message)

    elif message.text == "Заволжский р.":
        before_update_information(set_id_location_2, message)

    elif message.text == "Кировский р.":
        before_update_information(set_id_location_3, message)

    elif message.text == "Красноперекопский р.":
        before_update_information(set_id_location_4, message)

    elif message.text == "Ленинский р.":
        before_update_information(set_id_location_5, message)

    elif message.text == "Фрунзенский р.":
        before_update_information(set_id_location_6, message)

    elif message.text == "Окружная (Чурик)":
        before_update_information(set_id_location_7, message)

    else:
        # Тут происходит проверка нахождение человека в set
        # Если он находится в каком-то из них, то бот ждет информации об уточнении лоакции
        # В противном случае, бот выводит "string_unidentified_request"
        if message.from_user.id in set_id_location_1:
            after_update_information(dict_location_1, set_id_location_1, message)

        elif message.from_user.id in set_id_location_2:
            after_update_information(dict_location_2, set_id_location_2, message)

        elif message.from_user.id in set_id_location_3:
            after_update_information(dict_location_3, set_id_location_3, message)

        elif message.from_user.id in set_id_location_4:
            after_update_information(dict_location_4, set_id_location_4, message)

        elif message.from_user.id in set_id_location_5:
            after_update_information(dict_location_5, set_id_location_5, message)

        elif message.from_user.id in set_id_location_6:
            after_update_information(dict_location_6, set_id_location_6, message)

        elif message.from_user.id in set_id_location_7:
            after_update_information(dict_location_7, set_id_location_7, message)
        else:
            bot.send_message(message.from_user.id, string_unidentified_request,
                             reply_markup=keyboard_start)
        delete_id_from_all_sets(message.from_user.id)


bot.polling(none_stop=True, interval=1)
