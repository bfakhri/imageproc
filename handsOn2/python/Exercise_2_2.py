# Bijan Fakhri
import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import numpy as np
from scipy import ndimage
from scipy import signal 
from scipy import misc 

#2 - Import the Image
img = mpimg.imread("cameraman.jpg")
print(img)

#3 - Display the image
plot_img = plt.imshow(img, cmap='gray')
plt.show()
print(img.shape)

#4 - Generate Filter Impulse Response
h = np.ones((3,3))/9
print(h)

#5 - Convole Image with Filter
y1 = signal.convolve2d(img, h, mode='same')

#6 - Display and Generate Printout of filtered image
plt.imshow(img)
misc.imsave('y1.jpg', y1)

