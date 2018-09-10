import numpy # library for matrix
import time
import pandas # library to parse csv
import matplotlib.pyplot as plt # to plot
dataset=numpy.genfromtxt("nets.csv",delimiter=",",skip_header=1) #reads csv file
#library for neural network
from keras.layers import Activation
from keras.layers import Dense
from keras.models import Sequential
from keras.callbacks import EarlyStopping
from keras.callbacks import ModelCheckpoint
from keras.models import model_from_json #save models
from random import shuffle
from keras import optimizers
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2' #for avs warning
#prepares dataset
shuffle(dataset) 
X=dataset[:,1:9] 
Y_pre=dataset[:,9]
Y=Y_pre;
X_train=X[0:40000]
Y_train=Y[0:40000]
X_test=X[40000:]
Y_test=Y[40000:]
Z=Y_test[:]

start_time=time.time()
print ("starting execution")

model=Sequential()
model.add(Dense(1,input_dim=8,activation='linear',use_bias=False)) # adds one layer to model with 8 input
model.add(Dense(1,activation='linear')) # adds 2nd layer
ModelCheckpoint=ModelCheckpoint("intermediate", monitor='val_loss', verbose=0, save_best_only=True, save_weights_only=False, mode='auto', period=1)
#adam optimizer for back fropagation
adam=optimizers.Adam(lr=1e-2, beta_1=0.9, beta_2=0.999, epsilon=None, decay=1e-5, amsgrad=False)

model.compile(loss='mean_squared_error', optimizer='adam', metrics=['accuracy'])
#train the model on training set
model.fit(X_train,Y_train, epochs=100,batch_size=100,validation_data=(X_test,Y_test),verbose=1,shuffle=True,callbacks=[ModelCheckpoint])

#utilize trained model for prediction
Y_pred=model.predict([X_test])

f=open("C_result.csv","w")
f.write("C_actual,C_predicted \n")
for i,j in zip(Y_test,Y_pred[:,0]):
    f.write(str(i)+","+str(j)+"\n")
f.close()

# plot results
plt.scatter(Y_test, Y_pred[:,0], color='blue', label='Cap actual vs predicted ')
plt.xlabel('actual caf(pf)')
plt.ylabel('predicted cap(pf)')
plt.title('Neural network Regression')
plt.legend()
plt.show()
print ("--------%s seconds -----"% (time.time()-start_time))
