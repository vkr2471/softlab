#Imports
import json
from PIL import Image
import os
import numpy as np

class Dataset(object):
    '''
        A class for the dataset that will return data items as per the given index
    '''

    def __init__(self, annotation_file, transforms=None):
        '''
            Arguments:
            annotation_file: path to the annotation file
            transforms: list of transforms (class instances)
                        For instance, [<class 'RandomCrop'>, <class 'Rotate'>]
        '''
        self.annotation_file=annotation_file
        self.transforms=transforms
        f = open(  r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\annotations.jsonl')
        self.data = json.load(f)
     

    def __len__(self):
        '''
            return the number of data points in the dataset
        '''

        return (len(self.data))

    
    def __getann__(self, idx):
        '''
            return the data items for the index idx as an object
        '''
        return (self.data[idx])

        

    def __transformitem__(self, path):
        '''
            return transformed PIL Image object for the image in the given path
        '''
        img=Image.open(path)
        for transform in self.transforms:
           img= transform(img)
        return img
