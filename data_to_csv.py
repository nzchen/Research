import serial
import keyboard
import matplotlib.pyplot as plt

arduino_port = "COM7" #serial port of Arduino
baud = 9600 #arduino uno runs at 9600 baud
file_name = input("Enter File Name: \n")
fileName=file_name+".csv" #name of the CSV file generated

ser = serial.Serial(arduino_port, baud)
print("Connected to Arduino port:" + arduino_port)
file = open(fileName, "a")
print("Created file")

#userinput = input("Enter q to quit\n")
#reading at 10 samples a second 
s = 0 
x = []
y = []
#display the data to the terminal
while(1):
    if(keyboard.is_pressed('q')):
        print("Finish Data Collection \n")
        break;
    getData=str(ser.readline())
    data =getData[2:][:-5]
    print(data)

    #add the data to the file
    file = open(fileName, "a") #append the data to the file
    file.write(data + "\n") #write data with a newline
    x.append(s)
    y.append(data)
    s=s+1
    #print(s)    

#close out the file
file.close()
plt.plot(x, y)
plt.show()

