import vk_api
from vk_api.keyboard import VkKeyboard, VkKeyboardColor
import time
from random import randint


token = '00fe30963f90c3b59b84d70826591d579aaaad1e3fa5e81d3ad520da0abf4659dfd0d3879e67ef9c6a219'
vk = vk_api.VkApi(token=token)
vk._auth_token()


def bot_welcome():

    person_name = messages["profiles"][0]['first_name']

    keyboard = VkKeyboard(one_time=True)
    keyboard.add_button('Функции', color=VkKeyboardColor.POSITIVE)
    keyboard.add_line()
    keyboard.add_button('Предложить рецепт', color=VkKeyboardColor.PRIMARY)
    keyboard.add_line()
    keyboard.add_button('Есть вопросы или нашли баг', color=VkKeyboardColor.NEGATIVE)

    vk.method('messages.send', {'peer_id': person_id,
                                'message': "Добро пожаловать, " + person_name + ". \n Выберите раздел: \n ",
                                'random_id': randint(1, 1000000000),
                                'keyboard': keyboard.get_keyboard()})


def part_developing():

    keyboard = VkKeyboard(one_time=True)
    keyboard.add_button('Функции', color=VkKeyboardColor.POSITIVE)
    keyboard.add_line()
    keyboard.add_button('В начало', color=VkKeyboardColor.NEGATIVE)

    vk.method('messages.send', {'peer_id': person_id,
                                'message': "Такой запрос я еще не могу обработать. \n"
                                "Перейдите в раздел функции, чтобы узнать мои возможности.",
                                "random_id": randint(1, 1000000000),
                                'keyboard': keyboard.get_keyboard()})


def bot_functions():

    keyboard = VkKeyboard(one_time=True)
    keyboard.add_button('1. Любой рецепт на наш вкус', color=VkKeyboardColor.POSITIVE)
    keyboard.add_button('2. Рецепт по виду блюда', color=VkKeyboardColor.POSITIVE)
    keyboard.add_line()
    keyboard.add_button('В начало', color=VkKeyboardColor.NEGATIVE)

    vk.method('messages.send', {'peer_id': person_id,
                                'message': "Мои функции: \n "
                                           "(Чтобы выбрать функцию, отправьте ее номер мне или выберете ниже)",
                                'random_id': randint(1, 1000000000),
                                'keyboard': keyboard.get_keyboard()})


def recipe_offer():
    keyboard = VkKeyboard(one_time=True)
    keyboard.add_button('В начало', color=VkKeyboardColor.NEGATIVE)

    vk.method('messages.send', {'peer_id': person_id,
                                'message': "Оставьте свою завявку здесь: \n"
                                           "https://docs.google.com/forms/d/16e8GwPJKHI-ZoVBe-FRvhOhGaSemq64lipjz0cAzu3k",
                                "random_id": randint(1, 1000000000),
                                'keyboard': keyboard.get_keyboard()})


def questions_bugs():

    keyboard = VkKeyboard(one_time=True)
    keyboard.add_button('В начало', color=VkKeyboardColor.NEGATIVE)

    vk.method('messages.send', {'peer_id': person_id,
                                'message': "Напишите нам сюда: \n"
                                           "https://vk.me/mariaabr",
                                "random_id": randint(1, 1000000000),
                                'keyboard': keyboard.get_keyboard()})

def random_recipe():
    random_name_of_file = randint(1, 6)
    recipe_file = open("./files_random_recipe/" + str(random_name_of_file) + ".txt", "r")
    lines = ""
    flag = False
    for line in recipe_file:
        if flag:
            lines += line
        else:
            flag = True
            photo_url = line[0:].strip()
    vk.method('messages.send', {'peer_id': person_id,
                                'message': lines,
                                "random_id": randint(1, 1000000000),
                                'attachment': photo_url})

    keyboard = VkKeyboard(one_time=True)
    keyboard.add_button('В начало', color=VkKeyboardColor.NEGATIVE)

    vk.method('messages.send', {'peer_id': person_id,
                                'message': "Нажмите на кнопку ниже, чтобы продолжить:",
                                "random_id": randint(1, 1000000000),
                                'keyboard': keyboard.get_keyboard()})

while True:
    try:
        messages = vk.method('messages.getConversations', {'offset': 0,
                                                           'count': 20,
                                                           'filter': 'unanswered',
                                                           'extended': 1})
        if messages['count'] >= 1:
            person_id = messages['items'][0]['last_message']['from_id']
            message_body = messages['items'][0]['last_message']['text']
            print('новое сообщение:')
            print(messages)

            if message_body.lower() == 'привет' or \
                    message_body.lower() == 'начать' or \
                    message_body.lower() == 'в начало':
                bot_welcome()

            elif message_body.lower() == '!функции' or \
                    message_body.lower() == 'функции' or \
                    message_body.lower() == 'назад':
                bot_functions()

            elif message_body.lower() == '1' or \
                    message_body.lower() == '1. любой рецепт на наш вкус':
                random_recipe()

            elif message_body.lower() == '2' or \
                    message_body.lower() == '2. рецепт по виду блюда':

                part_developing()

            elif message_body.lower() == 'предложить рецепт':
                recipe_offer()

            elif message_body.lower() == 'есть вопросы или нашли баг':
                questions_bugs()


            else:
                part_developing()



    except Exception as E:
        print(E)
        time.sleep(1)
