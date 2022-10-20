'''Python task scheduler'''
import time;
import datetime;
import schedule;

def MinuteTask():
    print("Current time is:");
    print(datetime.datetime.now());
    print("Scheduler executed after one minute");
    print("-"*30);

def Fun_Minute():
    print("Current time is:");
    print(datetime.datetime.now());
    print("Scheduler executed after five minutes");
    print("-"*30);

def Fun_Hour():
    print("Current time is:");
    print(datetime.datetime.now());
    print("Scheduler executed after one hour");
    print("-"*30);

def Fun_Day():
    print("Current time is:");
    print(datetime.datetime.now());
    print("Scheduler executed after one day");
    print("-"*30);

def Fun_Afternoon():
    print("Current time is:");
    print(datetime.datetime.now());
    print("Scheduler executed at 12:00 noon");
    print("-"*30);

def Fun_Sunday():
    print("Current time is:");
    print(datetime.datetime.now());
    print("Scheduler executed every Sunday");
    print("-"*30);

def main():
    print("Python Job Scheduler");
    print("Current time is:");
    print(datetime.datetime.now());
    schedule.every().minute.do(MinuteTask);
    schedule.every(5).minutes.do(Fun_Minute);
    schedule.every().hour.do(Fun_Hour);
    schedule.every().day.do(Fun_Day);
    schedule.every().day.at("00:00").do(Fun_Afternoon);
    schedule.every().sunday.do(Fun_Sunday);
    while True:
        schedule.run_pending();
        time.sleep(1);
        

if __name__ == "__main__":
    main();