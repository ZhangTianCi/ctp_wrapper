// things alloc by Marshal::StringToHGlobalAnsi
// needs to free by Marshal::FreeHGlobal

#pragma once

using namespace System;
using namespace System::Runtime::InteropServices;

namespace CTPWrapper {

#define COPY_MANAGED_STRING(dst, s) \
	if (s) { \
		MyUnmanagedString cpps(s); \
		strcpy(dst, cpps.c_str()); \
	}

	class MyUnmanagedString
	{
	public:
		static String^ ToManaged(const char* s)
		{
			return Marshal::PtrToStringAnsi((IntPtr) (char *) s);
		}

	public:
		MyUnmanagedString(String^ s)
		{
			ptr_ = Marshal::StringToHGlobalAnsi(s);
		}

		~MyUnmanagedString()
		{
			Marshal::FreeHGlobal(ptr_);
		}

		char* c_str()
		{
			return (char*)ptr_.ToPointer();
		}

	private:
		IntPtr ptr_;
	};

}