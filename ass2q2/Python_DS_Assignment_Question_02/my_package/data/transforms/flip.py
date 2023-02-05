#Imports
from PIL import Image

class FlipImage(object):
    '''
        Flips the image.
    '''

    def __init__(self, flip_type='horizontal'):
        '''
            Arguments:
            flip_type: 'horizontal' or 'vertical' Default: 'horizontal'
        '''
        self.flip_type=flip_type

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)
        '''
#        img=Image.open(image)
        if self.flip_type=='horizontal':
            img1=image.transpose(Image.FLIP_LEFT_RIGHT)
          #  img1.show()
            return img1
        elif self.flip_type=='vertical':
            img1=image.transpose(Image.FLIP_TOP_BOTTOM)
            return img1
            #img1.show()
        else :
            print("Invalid choice")

#a=FlipImage('vertical')
#a(r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\imgs\0.jpg')
