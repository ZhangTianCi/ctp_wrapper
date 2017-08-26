import sys
import os

def read_struct_list(filename):
	found_struct = False
	struct_str = ''
	struct_name = ''
	ret = {}
	f = open(filename)
	for line in f.xreadlines():
		line = line.strip()
		if found_struct:
			struct_str += '\r\n'
			struct_str += line
			if line == '};':
				struct_str += '\r\n'
				found_struct = False
				ret[struct_name] = struct_str
		elif line.startswith('struct'):
			struct_name = line.split()[1]
			struct_str = line
			found_struct = True
			
	f.close()
	return ret
	

def read_type_list(filename):
	ret = [] 
	f = open(filename)
	for line in f.xreadlines():
		line = line.strip()
		ret.append(line)
	f.close()
	return ret

if __name__ == '__main__':
	struct_dict = read_struct_list('../ctpapi/include/ThostFtdcUserApiStruct.h')

	type_list = read_type_list(sys.argv[1])

	for typename in type_list:
		s = struct_dict[typename]
		f = open('data.txt', 'w')
		f.write(s)
		f.close()

		os.system('python struct2cli.py data.txt > result.txt')
		f = open('result.txt')
		typedefcode = f.read()
		f.close()

		print typedefcode	
