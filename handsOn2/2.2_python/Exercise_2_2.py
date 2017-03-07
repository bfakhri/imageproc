# Bijan Fakhri
import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import numpy as np
from scipy import ndimage
from scipy import signal 
from scipy import misc 

#2 - Import the Image
img = mpimg.imread("cameraman.jpg")

#3 - Display the image
plot_img = plt.imshow(img, cmap='gray')
plt.show()

#4 - Generate Filter Impulse Response
h = np.ones((3,3))/9

#5 - Convole Image with Filter
#  - Display and Generate Printout of filtered image
y1 = signal.convolve2d(img, h, mode='same')
print("Displaying and Saving image 'y1' - Close the image window to move on")
plt.imshow(y1, cmap='gray')
plt.show()
misc.imsave('y1.jpg', y1)

#6 - Convolve using ndimage.convolve
#  - Display and Generate Printout of filtered image
y2 = ndimage.convolve(img, h)
print("Displaying and Saving image 'y2' - Close the image window to move on")
plt.imshow(y2, cmap='gray')
plt.show()
misc.imsave('y2.jpg', y2)

print("Images y1 and y2 appear the same, expect for average intensity and the borders")

#7 - Creating the separated filter parts and filtering using 1D convolution
h_n1 = np.ones(3,1)/3
h_n2 = np.ones(1,3)/3
