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
			part1, part2 = line.split('(')   # 'virtual void OnFrontDisconnected'
			part2 = part2.split(')')[0]      # 'args'

			_, rettype, funcname = part1.split()

			tmp = part2.split()
			if len(tmp) in (0, 2, 4, 8):
				tmp = [a[1:] if a[0] == '*' else a for a in tmp]
				tmp = [a[:-1] if a[-1] == ',' else a for a in tmp]
				ret.append((rettype, funcname, tmp))

	f.close()
	return ret

def get_datacopy_code(struct_dict, datatype):
	s = struct_dict[datatype]
	f = open('data.txt', 'w')
	f.write(s)
	f.close()

	os.system('python struct2cli.py data.txt > result.txt')
	f = open('result.txt')
	datacopycode = f.read()
	f.close()

	return datacopycode

def print_func_0(struct_dict, rettype, funcname, args):
	# virtual void OnFrontConnected(){};
	print '\t\t%s %s()' % (rettype, funcname)
	print '\t\t{'
	print '\t\t\treturn wrapper_->%s();' % funcname
	print '\t\t}'
	print ''

def print_func_2(struct_dict, rettype, funcname, args):
	# virtual void OnFrontDisconnected(int nReason){};
	if struct_dict.has_key(args[0]):
		datacopycode = get_datacopy_code(struct_dict, args[0])
		print '\t\tvirtual %s %s(%s* cppData) override' % (rettype, funcname, args[0])
		print '\t\t{'
		print datacopycode
		print '\t\t\treturn wrapper_->%s(csharpData);' % funcname
		print '\t\t}'
	else:
		print '\t\tvirtual %s %s(%s %s) override' % (rettype, funcname, args[0], args[1])
		print '\t\t{'
		print '\t\t\treturn wrapper_->%s(%s);' % (funcname, args[1])
		print '\t\t}'

def print_func_4(struct_dict, rettype, funcname, args):
	# virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) {};
	assert struct_dict.has_key(args[0])
	assert args[2] == 'CThostFtdcRspInfoField'

	datacopycode = get_datacopy_code(struct_dict, args[0])
	print '\t\tvirtual %s %s(%s* cppData, %s* cppError) override' % (rettype, funcname, args[0], args[2])
	print '\t\t{'
	print datacopycode
	print ''
	print '\t\t\tCOPY_ERROR_CODE;'
	print '\t\t\treturn wrapper_->%s(csharpData, csharpError);' % funcname
	print '\t\t}'
	print ''

def print_func_6(struct_dict, rettype, funcname, args):
	# virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	assert args[0] == 'CThostFtdcRspInfoField'

	print '\t\tvirtual %s %s(%s* cppError, %s %s, %s %s) override' % (rettype, funcname, args[0], args[2], args[3], args[4], args[5])
	print '\t\t{'
	print '\t\t\tCOPY_ERROR_CODE;'
	print '\t\t\treturn wrapper_->%s(csharpError, %s, %s);' % (funcname, args[2], args[4])
	print '\t\t}'
	print ''

def print_func_8(struct_dict, rettype, funcname, args):
	# virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	assert struct_dict.has_key(args[0])
	assert args[2] == 'CThostFtdcRspInfoField'

	datacopycode = get_datacopy_code(struct_dict, args[0])
	print '\t\t%s %s(%s* cppData, %s* cppError, %s %s, %s %s)' % (rettype, funcname, args[0], args[2], args[4], args[5], args[6], args[7])
	print '\t\t{'
	print datacopycode
	print ''
	print '\t\t\tCOPY_ERROR_CODE;'
	print '\t\t\treturn wrapper_->%s(csharpData, csharpError, %s, %s);' % (funcname, args[5], args[7])
	print '\t\t}'
	print ''

if __name__ == '__main__':
	struct_dict = read_struct_list('../ctpapi/include/ThostFtdcUserApiStruct.h')

	func_list = read_func_list(sys.argv[1])

	for (rettype, funcname, args) in func_list:
		# int ReqQryOrder(CThostFtdcQryOrderField *pQryOrder, int nRequestID)
		if len(args) == 0:
			print_func_0(struct_dict, rettype, funcname, args)
		elif len(args) == 2:
			print_func_2(struct_dict, rettype, funcname, args)
		elif len(args) == 4:
			print_func_4(struct_dict, rettype, funcname, args)
		elif len(args) == 6:
			print_func_6(struct_dict, rettype, funcname, args)
		elif len(args) == 8:
			print_func_8(struct_dict, rettype, funcname, args)

