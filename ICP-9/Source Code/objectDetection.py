import cv2
import matplotlib.pyplot as plt
import cvlib as cv
from cvlib.object_detection import draw_bbox
if True:
    path = r'D:\Masters-UMKC\IOT\objectdetection\images\traffic.jpg'
    im = cv2.imread(path)
    bbox, label, conf = cv.detect_common_objects(im)
    print(bbox)
    print(label)
    print(conf)
    output_image = draw_bbox(im, bbox, label, conf,write_conf=True)
    plt.imshow(output_image)
    plt.show()
