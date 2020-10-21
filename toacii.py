import cv2


CHARS = ' ,.-~:;=!*#$@'
nw = 250

# img = cv2.imread('./as.png');

cap = cv2.VideoCapture(0)

print("\x1b[2J",end=" ")

while cap.isOpened():
    ret, img = cap.read()
    if not ret:
        break

    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    h, w = img.shape
    nh = int(h / w * nw)

    img = cv2.resize(img, (int(nw), int(nh)))

    frame = ""
    for row in img:
        for pixel in row:
            index = int(pixel / 255 * len(CHARS)-1)
            # if index >= 13: index = 12
            # print(index, end=' ')
            # if index >= 13: print(index)
            # print(CHARS[index], end=' ')
            frame += CHARS[index]
        # print()
        frame += '\n'
    
    print("\x1b[2J",end=" ")
    print(frame)
