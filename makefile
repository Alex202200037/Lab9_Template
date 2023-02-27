default:
	gcc -o prog main.c input.c disk.c hanoi.c stackElem.c stackLinkedList.c

debug:
	gcc -o prog -g main.c input.c disk.c hanoi.c stackElem.c stackLinkedList.c

clean:
	rm -f ./prog
