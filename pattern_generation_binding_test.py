import numpy as np
import cv2
import math
import sys

# Build dizinini ekle ki .so dosyasını import edebilelim
sys.path.append("/home/enes/Desktop/cpp_ws/pattern_generator/build")

import cyclicalGenerator as cg # type: ignore #ignore 

# Parametreler
width, height = 1200, 700
t = 0

cv2.namedWindow("Window", cv2.WINDOW_AUTOSIZE)

while True:
    radians = (t / 100.0) * 2 * math.pi
    y = (math.sin(radians) + 1) / 2 * 100 + 10  # 10..110 aralığı

    # Boş beyaz görüntü
    img = np.full((height, width, 3), 255, dtype=np.uint8)

    # Renk (BGR)
    color = (255, 0, 255)

    # C++ binding fonksiyonu çağrısı
    res = cg.CyclicalPattern.disciplined(img, 3, 5, int(y), 2)  # lineInterval=y, lineThickness=2

    cv2.imshow("Window", res)

    key = cv2.waitKey(15) & 0xFF
    if key == 27:  # ESC ile çıkış
        break

    t += 1

cv2.destroyAllWindows()
