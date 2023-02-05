#Imports
from my_package.model import ImageCaptioningModel
from my_package.data import Dataset, Download
from my_package.data.transforms import FlipImage, RescaleImage, BlurImage, CropImage, RotateImage


import numpy as np
from PIL import Image


def experiment(annotation_file, captioner, transforms, outputs):
    '''
        Function to perform the desired experiments

        Arguments:
        annotation_file: Path to annotation file
        captioner: The image captioner
        transforms: List of transformation classes
        outputs: Path of the output folder to store the images
    '''



    #Create the instances of the dataset, download
    dataset=Dataset(annotation_file,transforms)
    downloader=Download()




    #Print image names and their captions from annotation file using dataset object
    for i in dataset.data:
        print("Image_Name:{}".format(i['file_name']))
        print("Captions:{}".format('\n'.join([str(s) for s in i['captions']])))
        print()


    #Download images to ./data/imgs/ folder using download object
    for i in dataset.data:
        downloader(r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\imgs\{}'.format(i['file_name']), i['url'])

    #Transform the required image (roll number mod 10) and save it seperately
    img = dataset.__transformitem__(r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\imgs\8.jpg')
    img.save(outputs)

    #Get the predictions from the captioner for the above saved transformed image  
    print(captioner(outputs,3))

def main():
    captioner = ImageCaptioningModel()
  #  with open(r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\imgs\temp.jpg', 'wb') as f:
        #print(captioner(r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\imgs\6.jpg',1))
    #captioner(r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\data\imgs\6.jpg',1)
    experiment('./data/annotations.jsonl', captioner, [FlipImage('vertical'), BlurImage(1)],r'C:\Users\karthikreddyvoddula\Desktop\softlab\ass2q2\Python_DS_Assignment_Question_02\output\transformed.jpg' ) # Sample arguments to call experiment()


if __name__ == '__main__':
    main()