import time
import speech_recognition as sr
from gpiozero import Robot
import pyttsx3

def listen():
    recognizer = sr.Recognizer()
    with sr,Microphone() as source:
        recognizer.adjust_for_ambient_noise(source)
        print("Aguardando comando de voz...")
        audio = recognizer.listen(source)

    try:
        command = recognizer.recognize_google(audio).lower()
        print(f"Comando Recebido: {command}")
        return command 
        
    except sr.UnknownValueError:
        print("Não compreendi o comando.")
        return None
        
def talk (text):
    engine = pyttsx3.init()
    engine.say(text)
    engine.runAndWait()

def move_forward(duration_seconds):
    robot.forward()
    talk("Movendo para a frente.")
    time.sleep(duration_seconds) # Stay moviment in 'duration_seconds' seconds
    robot.stop()
    talk("Parando.")

command = listen()
if command == "forward":
    move_forward(5) # Forward in 5 seconds

elif command == "stop":
    robot.stop()
    talk("Parando.")