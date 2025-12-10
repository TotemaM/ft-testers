import random
import sys

if __name__ == "__main__":
	if len(sys.argv) == 2:
		generated = " ".join([str(num) for num in random.sample(range(-1024, 1024), int(sys.argv[1]))])
	else:
		generated = " ".join([str(num) for num in random.sample(range(-1024, 1024), 10)])
	print(generated)