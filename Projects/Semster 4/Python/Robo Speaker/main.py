# import os
import pyttsx3

if __name__ == '__main__':
    engine = pyttsx3.init()
    engine.setProperty('rate', 150)
    voices = engine.getProperty('voices')
    voice = input("Choose Speaker Voice: \n1. Male\n2. Female\n")
    if voice == '1':
        engine.setProperty('voice', voices[0].id)
    elif voice == '2':
        engine.setProperty('voice', voices[2].id)
    else:
        print("Invalid Input. Please Try Again.")

    while True:
        x = input("Enter the text you want to convert to speech (Press q to exit): ")
        if x == 'q':
            engine.say("Exiting...")
            engine.runAndWait()
            break
        engine.say(x)
        engine.runAndWait()

    engine.stop()