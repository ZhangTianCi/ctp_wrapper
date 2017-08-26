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
	

def read_func_list(filename):
	ret = [] 
	f = open(filename)
	for line in f.xreadlines():
		line = line.strip()
		if line.startswith('virtual'):
			line = line.replace('(', ' ').replace(')', ' ')
			_, rettype, funcname, datatype, _, _, _, _, _ = line.split()
			ret.append((rettype, funcname, datatype))
	f.close()
	return ret

if __name__ == '__main__':
	struct_dict = read_struct_list('../ctpapi/include/ThostFtdcUserApiStruct.h')

	func_list = read_func_list(sys.argv[1])

	for (rettype, funcname, datatype) in func_list:
		s = struct_dict[datatype]
		f = open('data.txt', 'w')
		f.write(s)
		f.close()

		os.system('python struct2cli.py data.txt > result.txt')
		f = open('result.txt')
		datacopycode = f.read()
		f.close()

		# int ReqQryOrder(CThostFtdcQryOrderField *pQryOrder, int nRequestID)
		print '\t\t%s %s(%sWrapper^ csharpData, int nRequestID)' % (rettype, funcname, datatype)
		print '\t\t{'
		print datacopycode
		print '\t\t\treturn api_->%s(&req, nRequestID);' % funcname
		print '\t\t}'
		print ''
		
