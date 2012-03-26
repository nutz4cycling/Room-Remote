from bottle import Bottle, run, static_file
import serial

ser = serial.Serial(9,9600)


app = Bottle()

@app.route('/<id:int>-on')
def oneOn(id=1):
    ser.write('[%s-on]\n' %id)
    return 'on'

@app.route('/<id2:int>-off')
def oneOff(id2=1):
    ser.write('[%s-off]\n' %id2)
    return 'off'

@app.route('/')
def index():
    return static_file('index.html', root='/Users/Andy/Room-Remote/')

run(app, host='localhost', port=8080)
