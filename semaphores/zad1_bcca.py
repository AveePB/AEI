from threading import Semaphore, Thread
import time

# Constants
CLOSE = 0
OPEN = 1

# Semaphores
semA = Semaphore(CLOSE)
semB = Semaphore(OPEN)
semC = Semaphore(CLOSE)


def printA(ntimes):
    """Function printing A"""
    for _ in range(ntimes):
        semA.acquire()

        semA.acquire()
        print('A ', end="")

        semB.release()
        time.sleep(1)


def printB(ntimes):
    """Function printing B"""
    for _ in range(ntimes):
        semB.acquire()
        print('B', end="")

        semC.release()
        semC.release()
        time.sleep(1)


def printC(ntimes):
    """Function printing C"""
    for _ in range(ntimes):
        semC.acquire()
        print('C', end="")

        semA.release()
        time.sleep(2)

how_many = 10
threads = [
    Thread(target=printA, args=(how_many,)), 
    Thread(target=printB, args=(how_many,)), 
    Thread(target=printC, args=(2*how_many,)),
]

for thread in threads:
    thread.start()
for thread in threads:
    thread.join()
    
print("\nAll done")