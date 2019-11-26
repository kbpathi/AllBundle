all:	tree helloworld
CC = gcc
CFLAGS1 = -Wall -g -c
CFLAGS2 = -g

#objectfile:	helloworld-jenkins.o tree.o
#	${CC} ${CFLAGS2} -o objectfile tree.o helloworld-jenkins.o

helloworld-jenkins:	helloworld-jenkins.c
	${CC} ${CFLAGS1} helloworld-jenkins.o helloworld-jenkins.c

tree:	tree.c
	${CC} ${CFLAGS1} -o tree.o tree.c

#helloworld-jenkins.o:	helloworld-jenkins.c
#	gcc -o helloworld-jenkins helloworld-jenkins.c

#working
#tree:	tree.c
#	gcc -o tree tree.c

#helloworld-jenkins:	helloworld-jenkins.c
#	gcc -o helloworld-jenkins helloworld-jenkins.c

clean:
	rm *.o output
