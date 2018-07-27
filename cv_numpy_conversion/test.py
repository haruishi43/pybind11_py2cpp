import cv2
import process_in_cpp

src_img = cv2.imread("./pano.jpg")
src_img = src_img[:, :, :]

print(type(src_img))
print(src_img.shape)

cv2.imshow("window_python_1", src_img)
cv2.waitKey()


# convert as array[np.array2d]

arr = [src_img[:,:, 0], src_img[:, :, 1], src_img[:, :, 2]]

print(type(arr))
print(type(arr[0]))

dst_img = process_in_cpp.process_single_channel_image(arr)
# cv2.imshow("window_python_2", dst_img)
# cv2.waitKey()
