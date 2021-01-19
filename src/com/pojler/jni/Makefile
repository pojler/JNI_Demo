CC=g++
CPPFLAGS:=-shared -m64

majca: com_pojler_jni_Main.o
	${CC} ${CPPFLAGS} -o $@.dll $^

com_pojler_jni_Main.o: com_pojler_jni_Main.cpp com_pojler_jni_Main.hpp
	${CC} ${CPPFLAGS} -c $<

clean: 
	del *.o
