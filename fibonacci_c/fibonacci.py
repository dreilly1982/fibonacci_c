#!/usr/local/bin/python
LIMIT = 1000000
a = 0
b = 1
c = 0
d = LIMIT
d -= 2
#print "%d %d" % (0, 0)
#print "%d %d" % (1, 1)
c = a + b
while (d):
    #print "%d %d" % (LIMIT - d, c)
    a = b
    b = c
    c = a + b
    d -= 1
#print "%d %d" % (LIMIT - d, c)
