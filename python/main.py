import sys
import header

for i in range(1, len(sys.argv)):
	f = open(sys.argv[i])
	content = f.read().split("\n")
	res = header.get_header(sys.argv[i], i)


	print("\n".join(res))


