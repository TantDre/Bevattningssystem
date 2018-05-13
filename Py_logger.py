# Titel: Py-logger (Prototyp)
# Författare: André Sollander
# Datum: 2018-02-22

# Import
import serial
import matplotlib.pyplot as plt

#Globala variabler
datalog = []

# Läser data från serialporten
def readSerial():
    try:
        arduino = serial.Serial('COM3', 9600)
        while True:
            data = (arduino.readline()).decode("utf-8")
            print(data)
            writeLog(data)
        arduino.close()
        return
    except:
        print('No Serial')
        exit()

# Skriver data till textfil
def writeLog(data):
    try:
        datalog.append(int(data))
        log = open('log_sensor.txt', 'a')
        log.write(str(data) + '\n')
        log.close()
        plotData()
        return
    except:
        print("Can't write to file")
        exit()

# Plottar data
def plotData():
    try:
        t = range(len(datalog))
        plt.plot(t, datalog, 'bo')
        plt.xlabel('Tid [h]')
        plt.ylabel('Jordfuktighet [%]')
        plt.title('Bevattning')
        plt.savefig('Figure.png')
        plt.show()
        return
    except:
        print("Error in plot")
        exit()

# Start
readSerial()