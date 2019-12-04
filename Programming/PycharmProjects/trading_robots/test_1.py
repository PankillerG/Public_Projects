import requests

r = requests.get('http://iss.moex.com/iss/history/engines/stock/markets/shares/boa rds/tqbr/securities.xml?date=2013-12-20')
print(r.text)