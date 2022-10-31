import sys;
import time;
import os;
import hashlib;
import schedule;
import datetime;
import smtplib;
import urllib.request;
from email import encoders;
from email.mime.text import MIMEText;
from email.mime.base import MIMEBase;
from email.mime.multipart import MIMEMultipart;

def GetChecksum(path, blocksize = 1024):
    fd = open(path,'rb');
    h = hashlib.md5();
    buf = fd.read(blocksize);

    while len(buf)>0:
        h.update(buf);
        buf = fd.read(blocksize);
    fd.close();

    return h.hexdigest();
	
def MailSender(filename,time,totalscanned,totalduplicates,toaddress):
	try:
		fromaddress = 'hemlata127@gmail';
		toaddr = toaddress;
		msg = MIMEMultipart();
		msg['From'] = fromaddress;
		msg['To'] = toaddr;
		body = """
		The file scanning started at %s
		Total files scanned are: %d
		Total duplicate files are %d
		"""%(time,totalscanned,totalduplicates);
		subject = """Duplicate files removed"""
		msg['Subject'] = subject;
		msg.attach(MIMEText(body,'plain'));
		attachment = open(filename,'rb');
		p = MIMEBase('application','octet-stream');
		p.set_payload(attachment.read());
		encoders.encode_base64(p);
		p.add_header('Content-Disposition',"attachment;filename=%s"%filename);
		msg.attach(p);
		smtpobj = smtplib.SMTP('smtp.gmail.com',587);
		smtpobj.starttls();
		smtpobj.login('hemlata127@gmail.com','(@anwesha02$)');
		text = msg.as_string();
		smtpobj.sendmail(fromaddress,toaddr,text)
		smtpobj.quit();
		print("Mail sent successfully");
	
	except Exception as E:
		print("Unable to send email",E)
    

def DuplicateFile(path,toaddress):
    if os.path.exists(path) == False:
        print("%s does not exist"%path);

    if os.path.isabs(path) == False:
        path = os.path.abspath(path);

    data = {};
    totalscanned=0;
    for Folder,Subfolder,Files in os.walk(path):
        for name in Files:
            name = os.path.join(Folder,name);
            checksum = GetChecksum(name);
            if checksum in data:
                data[checksum].append(name);
            else:
                data[checksum] = [name];
            totalscanned = totalscanned+1;
        
    newdata = list(filter(lambda x:len(x)>1,data.values()));
    if os.path.exists("Marvellous") == False:
        os.mkdir("Marvellous",mode=777);
    currenttime = datetime.datetime.now().strftime("%d%m%Y%H%M%S");
    filename = "Marvellous\log"+currenttime+".txt";
    fd1 = open(filename,'a');
    fd1.write("\nFollowing duplicate files are removed: at %s"%(datetime.datetime.now()));
    fd1.write("\n"+"-"*60);
    
    totalduplicates = 0
    for outer in newdata:
        count = 0
        for inner in outer:
            count = count + 1;
            if count<2 :
                pass
            else:
                fd1.write("\n"+inner);
                os.remove(inner);
                totalduplicates = totalduplicates+1;
    fd1.close();
    time = datetime.datetime.now();
    MailSender(filename,time,totalscanned,totalduplicates,toaddress);
	

def main():
    print("Duplicate file removal script");
    if len(sys.argv) <4:
        print("Invalid number of arguments");
        exit();
    if sys.argv[1] == "-h":
        print("This is duplicate file removal script");
        exit();
    if sys.argv[1] == "-u":
        print("demo.py dir1");
        exit();
		
    scheduleduration = int(sys.argv[2]);

    schedule.every(scheduleduration).minutes.do(DuplicateFile,path=sys.argv[1],toaddress=sys.argv[3]);
    while True:
        schedule.run_pending();
        time.sleep(1);


    
if __name__ == "__main__":
    main();