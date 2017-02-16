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
plt.imshow(y1, cmap='gray')
plt.show()
misc.imsave('y1.jpg', y1)

#6 - Convolve using ndimage.convolve
#  - Display and Generate Printout of filtered image
y2 = ndimage.convolve(img, h)
plt.imshow(y2, cmap='gray')
plt.show()
misc.imsave('y2.jpg', y2)
