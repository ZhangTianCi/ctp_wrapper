# python struct2cli.py data.txt

import sys
from typedefs import CPPTYPES_TO_CSHARPTYPES

def read_struct(filename):
	name  = None
	attrs = []

	f = file(filename)
	for line in f.xreadlines():
		line = line.strip()
		if line.startswith('struct'):
			name = line.split(' ')[1].strip()
		elif line[-1] == ';':
			tmp = line.split()
			if len(tmp) == 2:
				attrs.append((tmp[0], tmp[1][:-1]))
		
	f.close()

	return name, attrs

if __name__ == '__main__':
	name, attrs = read_struct(sys.argv[1])

	print '\tpublic ref struct %sWrapper' % name
	print '\t{'
	for (typ, field) in attrs:
		print '\t\t%s %s;' % (CPPTYPES_TO_CSHARPTYPES[typ], field)
	print '\t};'

	print ''
	print ''
	print ''
	print ''

	print '%sWrapper^ csharpData = gcnew %sWrapper();' % (name, name)
	for (typ, field) in attrs:
		if CPPTYPES_TO_CSHARPTYPES[typ] == 'String^':
			print 'COPY_UNMANAGED_STRING(csharpData->%s, cppData->%s);' % (field, field)
		else:
			print 'csharpData->%s = cppData->%s;' % (field, field)

	print ''
	print ''
	print ''
	print ''

	print '%s req;' % name
	print 'memset(&req, 0, sizeof(req));'
	print ''
	for (typ, field) in attrs:
		if CPPTYPES_TO_CSHARPTYPES[typ] == 'String^':
			print 'COPY_MANAGED_STRING(req.%s, pFensUserInfo->%s);' % (field, field)
		else:
			print 'req->%s = csharpData->%s;' % (field, field)
	print ''