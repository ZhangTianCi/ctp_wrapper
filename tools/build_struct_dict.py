# python build_struct_dict.py ThostFtdcUserApiDataType.h > typedefs.py

import sys

def parse_h_header(hfile):
	ret = {}
	f = open(hfile)
	for line in f.xreadlines():
		line = line.strip()
		if line.startswith('typedef'):
			typedef, typename, name = line.split(' ')
			if typename == 'char':
				if name[-2:] == '];':
					name = name.split('[')[0]
					ret[name] = 'String^'
				else:
					name = name.split(';')[0]
					ret[name] = 'char'
			else:
				name = name.split(';')[0]
				ret[name] = typename
	f.close()
	return ret

if __name__ == '__main__':
	data = parse_h_header(sys.argv[1])
	print 'CPPTYPES_TO_CSHARPTYPES = {'
	for k, v in data.iteritems():
		print '  \'%s\' : \'%s\',' % (k, v)
	print '}'

