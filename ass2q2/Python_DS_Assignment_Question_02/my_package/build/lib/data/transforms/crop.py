#Imports
from PIL import Image
import random

class CropImage(object):
    '''
        Performs either random cropping or center cropping.
    '''

    def __init__(self, shape, crop_type='center'):
        '''
            Arguments:
            shape: output shape of the crop (h, w)
            crop_type: center crop or random crop. Default: center
        '''
        self.shape=shape
        self.crop_type=crop_type

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)
        '''
        #img=Image.open(image)
        width,height=image.size
        cwidth =self.shape[1]
        cheight=self.shape[0]
        if self.crop_type =='center' :
            img1=image.crop(((width-cwidth)/2,(height-cheight)/2,(width+cwidth)/2,(height+cheight)/2))
            return img1
            #img1.show()
        elif self.crop_type=='random':
            rcw=random.randint(cwidth/2,width-cwidth/2)
            rch=random.randint(cheight/2,height-cheight/2)
            img1=image.crop((rcw-cwidth/2,rch-cheight/2,rcw+cwidth/2,rch+cheight/2))
          #  img1.show()
            return img1
        else :
            print('Invalid choice')

#a=CropImage((200,200),'ranom')
#a(r"C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\imgs\8.jpg")





 