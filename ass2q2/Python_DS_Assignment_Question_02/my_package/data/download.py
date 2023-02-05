from PIL import Image
import requests
from io import BytesIO
import json

class Download(object):
    '''
        A class for helping in dowloading the required images from the given url to the specified path
    '''

    def __call__(self, path, url):
        '''
            Arguments:
            path: download path with the file name
            url: required image URL
        '''
        r=requests.get(url)
        with open(path,'wb') as f:
            f.write(r.content)


#f = open(r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\annotations.jsonl')
#data=json.load(f)
#for i in data :
 #   a=  Download()
  #  a(r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\imgs\{}'.format(i['file_name']),i['url'])



