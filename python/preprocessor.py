def format_preprocessor(content):
	res = []
	indent_size = 0
	preprocessor = get_preprocessor(content)
	for i in preprocessor:
		i = i[1:].split()
		if "end" in i[0]:
			indent_size -= 1
		res.append(get_line(indent_size, i[0], " ".join(i[1:])))
		if "if" in i[0] and "end" not in i[0]:
			indent_size += 1
	return res

def get_preprocessor(content):
	res = []
	for i in content:
		i = i.strip()
		if len(i) > 0 and i[0] == '#':
			res.append(i)
	return res

def get_line(indent_size, instruction, value):
	res = "#" + " " * indent_size + instruction
	if value != "":
		res += " " + value
	return res

'''
#if ok
#ifdef ok 
#ifndef ok
#else ok
#define ok 
#undef ok 
#error ok 
#include ok 
#endif ok
'''