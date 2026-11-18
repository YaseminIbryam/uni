import cv2
import numpy as np
import keras

alphabet = input("Choose an alphabet - English or Bulgarian (E/B): ").upper()
if alphabet == "E":
    model = keras.models.load_model('letters_model.keras') #модела за латинските букви
elif alphabet == "B":
    model = keras.models.load_model('...') # модела за кирилица
else :
    exit("Not a valid alphabet")

cyrillic_letters = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЬЮЯ"

drawing = False  # true if mouse is pressed
pt1_x, pt1_y = None, None


# mouse callback function
def line_drawing(event, x, y, flags, param):
    global pt1_x, pt1_y, drawing

    if event == cv2.EVENT_LBUTTONDOWN:
        drawing = True
        pt1_x, pt1_y = x, y

    elif event == cv2.EVENT_MOUSEMOVE:
        if drawing == True:
            cv2.line(img, (pt1_x, pt1_y), (x, y), color=(255, 255, 255), thickness=30)
            pt1_x, pt1_y = x, y
    elif event == cv2.EVENT_LBUTTONUP:
        drawing = False
        cv2.line(img, (pt1_x, pt1_y), (x, y), color=(255, 255, 255), thickness=30)


img = np.zeros((512, 512, 3), np.uint8)
cv2.namedWindow('test draw')
cv2.setMouseCallback('test draw', line_drawing)

while (1):
    cv2.imshow('test draw', img)
    key = cv2.waitKey(1) & 0xFF

    if key == 27: #Esc
        break
    elif key == 32:  #Space
        # Превръща в черно-бяло и смаля до 28x28
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        resized = cv2.resize(gray, (28, 28))

        # Подготвя за модела и класифицира
        input_data = (resized.astype('float32') / 255.0).reshape(1, 28, 28, 1) # 1 картина (28, 28) размера 1 цвят
        prediction = model.predict(input_data) # праща матрицата на модела и получава списък с вероятности за всяка буква
        predicted_index = np.argmax(prediction) #намира позицията на най-голямото число


        # Принтира резултата
        if alphabet == "E":
            letter =  chr( predicted_index + 65) # превръща числото в char
        else :
            letter = cyrillic_letters[predicted_index] # Взима буквата от масива

        print(letter)

        # Изчиства екрана
        img[:] = 0

cv2.destroyAllWindows()