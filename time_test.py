import time
print time.time()
print time.localtime(time.time())
while True:
    print time.asctime(time.localtime(time.time()))
    time.sleep(10)
    print time.localtime(time.time())