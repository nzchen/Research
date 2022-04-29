import serial
import keyboard
import matplotlib.pyplot as plt
import csv

arduino_port = "COM7" #serial port of Arduino
baud = 9600 #arduino uno runs at 9600 baud
file_name = input("Enter File Name: \n")
fileName=file_name+".csv" #name of the CSV file generated

ser = serial.Serial(arduino_port, baud)
print("Connected to Arduino port:" + arduino_port)
file = open(fileName, "a")
print("Created file")
writer = csv.writer(file)

timeDataList = []
dataDataList = []

#display the data to the terminal
while(1):
    if(keyboard.is_pressed('q')):
        print("Finish Data Collection \n")
        break;
    getData=str(ser.readline())
    data =getData[2:][:-5]
    #timeData = getData[2:][:-14]
    #dataData = getData[7:][:-5]
    timeData = str.split(getData)[0][2:]
    dataData = str.split(getData)[1][:-5]

    print(data)
    
    #add the data to the file
    file = open(fileName, "a") #append the data to the file
    file.write(dataData + "\n") #write data with a newline
    
    timeDataList.append(timeData)
    dataDataList.append(dataData)

#make mapping list
combinedList = list (map (  lambda x,y: [x,y], timeDataList,dataDataList    ))

#add to CSV File
# name of csv file 
filename = file_name+"_Combined_Data"+".csv"
fields = ['time', 'data']
# writing to csv file 
with open(filename, 'w', newline='', encoding='utf-8') as csvfile: 
    # creating a csv writer object 
    csvwriter = csv.writer(csvfile) 
    # writing the fields 
    csvwriter.writerow(fields) 
    # writing the data rows 
    csvwriter.writerows(combinedList)

#close out the file
file.close()
#plt.plot(timeDataList, dataDataList)
#plt.show()

  
