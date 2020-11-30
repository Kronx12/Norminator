import os
import sys
import header
import preprocessor

for i in range(1, len(sys.argv)):
	if "".join(list(reversed(sys.argv[1]))[:2]) == "c." and os.path.isfile(sys.argv[1]):
		f = open(sys.argv[i])
		content = f.read().split("\n")
		res = header.get_header(sys.argv[i], i)

		res += preprocessor.format_preprocessor(content)
		print(sys.argv[i][:-2])

		output = open(sys.argv[i][:-2] + "_normed.c", "w+")
		for i in res:
			output.write(i + "\n")
		print("\n".join(res))
	else:
		print(sys.argv[1])
		print("Warning: Not a valid file")