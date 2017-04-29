import random, sys

i = random.sample(xrange(1, 100), int(sys.argv[1]))

s = ' '.join([str(x) for x in i])

print s
