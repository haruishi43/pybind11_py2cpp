import cv2
import process_in_cpp

src_img = cv2.imread("./lena_gray.bmp")
src_img = src_img[:, :, 0]

cv2.imshow("window_python_1", src_img)
cv2.waitKey()

dst_img = process_in_cpp.process_single_channel_image(src_img)

cv2.imshow("window_python_2", dst_img)
cv2.waitKey()
