import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText


from email.mime.image import MIMEImage

print("Hello!") 

words = ['Internet', 'of', 'Things']
word = int(input("Type 1, 2, or 3"))

bodyMessage = None

if word==1:
	print "Sending email"
	bodyMessage="Internet"
elif word==2:
	print "Sending email"
	bodyMessage="of"
elif word==3:
	print "Sending email"
	bodyMessage="Things"
else: 
	print "You did not choose."
	bodyMessage="ERROR 404"

fromaddr = "XXXX"
toaddr = "XXXX"

msg = MIMEMultipart()
msg['Subject'] = "Python Homework"
msg['From'] = fromaddr
msg['To'] = toaddr
body = bodyMessage
msg.attach(MIMEText(body, 'plain'))

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(fromaddr, "XXXXXX")
text = msg.as_string()
server.sendmail(fromaddr, toaddr, text)

server.quit()