import vk_api
import time

token = '00fe30963f90c3b59b84d70826591d579aaaad1e3fa5e81d3ad520da0abf4659dfd0d3879e67ef9c6a219'
vk = vk_api.VkApi(token=token)
vk._auth_token()


def hello():
    person_name = messages["profiles"][0]['first_name']
    print(person_name)
    vk.method("messages.send", {"peer_id": person_id, "message": person_name})


while True:
    try:
        messages = vk.method('messages.getConversations', {'offset': 0, 'count': 20, 'filter': 'unanswered', "extended":1})
        if messages['count'] >= 1:
            person_id = messages['items'][0]['last_message']['from_id']
            body_of_message = messages['items'][0]['last_message']['text']

            if body_of_message.lower() == 'привет':
                hello()
            else:
                vk.method("messages.send", {"peer_id": person_id, "message": 'ОТСОСУ ЗА 100, пиши в лс'})



    except Exception as E:
        time.sleep(1)
