#Imports
from PIL import Image
from math import floor

class RescaleImage(object):
    '''
        Rescales the image to a given size.
    '''

    def __init__(self, output_size):
        '''
            Arguments:
            output_size (tuple or int): Desired output size. If tuple, output is
            matched to output_size. If int, smaller of image edges is matched
            to output_size keeping aspect ratio the same.
        '''
        self.output_size=output_size


    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)

            Note: You do not need to resize the bounding boxes. ONLY RESIZE THE IMAGE.
        '''
     #   img=Image.open(image)
        width,height=image.size



        if isinstance(self.output_size,tuple):
            img1=image.resize((floor(self.output_size[0]),floor(self.output_size[1])))
           # img1.show()
            return img1

        elif isinstance(self.output_size,int):
            if height>=width:
                height=(self.output_size)*(height/width)
                width=self.output_size
            else:
                width=(self.output_size)*(width/height)
                height=self.output_size
            img1=image.resize((floor(width),floor(height)))
            return img1
            #img1.show()
        else:
            print("invalid input")

#a=RescaleImage((200,400))
#a(r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\imgs\8.jpg')


