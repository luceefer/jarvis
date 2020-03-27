import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import smtplib

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)


def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 12:
        speak("good morning sir!")

    elif hour >= 12 and hour < 18:
        speak("good afternoon sir!")

    else:
        speak("good evening sir!")

    speak("i am jarvis , how may i help you sir")


def takeCommand():
    # it takes microphone input from the user and returns string output

    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening.....")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language="en-in")
        print(f"boss said : {query}\n")

    except Exception as e:
        print("say that again please...")
        return "None"
    return query

def sendEmail(to,content):
    server = smtplib.SMTP('smtp.gmail.com',587)
    server.ehlo()
    server.starttls()
    server.login('tyeytdjgtrd@gmail.com','gfstrjyszydygc')
    server.sendmail('tyeytdjgtrd@gmail.com',to,content)
    server.close()





if __name__ == "__main__":
    wishMe()
    #you can write another condition here if you don't want a infinte loop
    while True:
        query = takeCommand().lower()

        # logic for executing tasks based on query

        if 'wikipedia' in query:
            speak('searching wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2)
            speak("According to wikipedia...")
            print(results)
            speak(results)
        elif 'open youtube' in query:
            webbrowser.open("youtube.com")
        elif 'open google' in query:
            webbrowser.open("google.com")
        elif 'open stackoverflow' in query:
            webbrowser.open("stackoverflow.com")

        elif 'play music' in query:
            music_dir ='E:\\evergreen songs'
            songs = os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[12]))

        elif 'the time' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")
            print(strTime)
            speak(f"sir the time is {strTime}")

        elif 'python' in query:
            codePath = "C:\\Users\\User\\AppData\\Local\\Programs\\Python\\Python36\\Lib\\idlelib\\idle.pyw"
            os.startfile(codePath)
#you can open any app. or file here,by using above 3 lines jst write name and change the codepath

        elif 'email to him\her' in query:
            try:
                speak("what sholud i write sir?")
                content = takeCommand()
                to = "dmyjjgycmy@gmail.com"
                sendEmail(to,content)
                speak("email has been sent sir")
            except Exception as e:
                print(e)
                speak("sorry boss i cannot send this email")



