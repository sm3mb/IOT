# -*- coding: utf-8 -*-
"""
Created on Thu Mar 19 16:26:14 2020

@author: chand
"""
import requests,json
from Adafruit_IO import Client,Feed,Data
aio=Client("aio_JMBS084virWotlPbQSUZE1dgywL4")
url = "https://api.thingspeak.com/channels/985051/feeds.json?results=2"
req = requests.get(url)
resp = json.loads(req.content)
for i in range(1,7):
    key = (resp['channel']['field'+str(i)])
    value = (resp['feeds'][0]['field'+str(i)])
    aio.send(key, value)
    