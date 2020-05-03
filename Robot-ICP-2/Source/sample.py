

"""
Created on Thu Apr  9 13:18:03 2020

@author: vemula1800
"""

from keras.models import model_from_json
import pickle
from keras.models import load_model
import librosa
import librosa.display
import numpy as np
import sklearn.preprocessing
from sklearn.preprocessing import LabelEncoder
import time
import matplotlib.pyplot as plt
import IPython.display as ipd

path = r'lungs.wav'
plt.figure(figsize=(12,4))
data,sample_rate = librosa.load(path)
_ = librosa.display.waveplot(data,sr=sample_rate)
ipd.Audio(path)