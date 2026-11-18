import matplotlib.pyplot as plt
import numpy as np
import keras
from keras import layers
import tensorflow_datasets as tfds

batch_size = 128
num_classes = 26
epochs = 12

# input image dimensions
img_rows, img_cols = 28, 28
# the data, shuffled and split between train and test sets
ds_train, ds_test = tfds.load('emnist/letters', split=['train', 'test'], as_supervised=True, batch_size=-1)
x_train, y_train = tfds.as_numpy(ds_train)
x_test, y_test = tfds.as_numpy(ds_test)

x_train = np.transpose(x_train, (0, 2, 1, 3))
x_test = np.transpose(x_test, (0, 2, 1, 3))

y_train = y_train - 1
y_test = y_test - 1
#x_train = x_train.reshape(x_train.shape[0], img_rows, img_cols, 1)
#x_test = x_test.reshape(x_test.shape[0], img_rows, img_cols, 1)
input_shape = (img_rows, img_cols, 1)

x_train = x_train.astype('float32')
x_test = x_test.astype('float32')
x_train /= 255
x_test /= 255
print('x_train shape:', x_train.shape)
print(x_train.shape[0], 'train samples')
print(x_test.shape[0], 'test samples')

# convert class vectors to binary class matrices
y_train = keras.utils.to_categorical(y_train, num_classes)
y_test = keras.utils.to_categorical(y_test, num_classes)

from keras.models import Sequential
from keras.layers import Conv2D, BatchNormalization, Dropout, Flatten, Dense

input_size = (28, 28, 1)
output_size = 26

model = Sequential()
model.add(Conv2D(32, kernel_size=3, activation='relu', input_shape=(input_size[0], input_size[1], input_size[2])))
model.add(BatchNormalization())
model.add(Conv2D(32, kernel_size=3, activation='relu'))
model.add(BatchNormalization())
model.add(Conv2D(32, kernel_size=5, strides=2, padding='same', activation='relu'))
model.add(BatchNormalization())
model.add(Dropout(0.4))

model.add(Conv2D(64, kernel_size=3, activation='relu'))
model.add(BatchNormalization())
model.add(Conv2D(64, kernel_size=3, activation='relu'))
model.add(BatchNormalization())
model.add(Conv2D(64, kernel_size=5, strides=2, padding='same', activation='relu'))
model.add(BatchNormalization())
model.add(Dropout(0.4))

model.add(Conv2D(128, kernel_size=4, activation='relu'))
model.add(BatchNormalization())
model.add(Flatten())
model.add(Dropout(0.4))
model.add(Dense(output_size, activation='softmax'))

model.summary()

model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
history = model.fit(x_train, y_train, batch_size=batch_size, epochs=epochs, validation_data=(x_test, y_test))
model.save('letters_model.keras')

plt.plot(history.history['accuracy'], label='Train Accuracy')
plt.plot(history.history['val_accuracy'], label='Validation Accuracy')
