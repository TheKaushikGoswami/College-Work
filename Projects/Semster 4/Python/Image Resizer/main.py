import cv2

source = input('Enter the path of the image: ')

src = cv2.imread(source, cv2.IMREAD_UNCHANGED)

print('Original Dimensions : ', src.shape)

dimensions = input('Enter the width and height of the image (width, height): ')
width, height = map(int, dimensions.split(', '))

dsize = (width, height)
output = cv2.resize(src, dsize)

print('Resized Dimensions : ', output.shape)

destination = input('Enter the path where you want to save the resized image: ')
cv2.imwrite(destination, output)

cv2.imshow('Resized image', output)
cv2.waitKey(0)