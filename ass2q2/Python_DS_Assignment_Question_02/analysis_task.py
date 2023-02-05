from my_package.model import ImageCaptioningModel
from my_package.data import Dataset, Download
from my_package.data.transforms import FlipImage, RescaleImage, BlurImage, CropImage, RotateImage
from PIL import Image

captioner=ImageCaptioningModel()

for i in range(10):
     print('Name:{}.jpg'.format(i))
     print("Captions: ")
     print('\n'.join(captioner((r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\imgs\{}.jpg'.format(i)),3)))
     print()
i=1
Dict={1:'a',2:'b',3:'c',4:'d',5:'e',6:'f',7:'g'}
path=r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\imgs\8.jpg'
img=Image.open(r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\imgs\8.jpg')
width,height=img.size
transforms=[FlipImage(),BlurImage(2),RescaleImage((2*width,2*height)),RescaleImage((width/2,height/2)),RotateImage(-90),RotateImage(45)]
img.save(r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\output\{}.jpg'.format(Dict[i]))
img.show()
print('Trasform:{}'.format(Dict[i]))
print('Captions:')
print('\n'.join(captioner((r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\output\{}.jpg'.format(Dict[i])),3)))
i=i+1
print()

for transform in transforms:
    img1=transform(img)
    img1.show
    img1.save(r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\output\{}.jpg'.format(Dict[i]))
    print('Trasform:{}'.format(Dict[i]))
    print('Captions:')
    print('\n'.join(captioner((r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\output\{}.jpg'.format(Dict[i])),3)))
    i=i+1
    print()
