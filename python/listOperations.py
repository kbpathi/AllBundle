import sys

def swapOper(lst):
	print "swapping the list"	
	count = 0
	tmp = 0
	lent = len(lst)-1
	for count in range (lent/2):
		'''print lst[count]'''
		tmp = lst[count]
		lst[count] = lst[lent-count]
		lst[lent-count] = tmp
		count +=1
	return lst


def takeinput(lst):
    takeip = int(raw_input("please enter the list value: "))
    print "input provided is : ", takeip
    lst.append(takeip)


lst = [10,20,30,40,50,60,70,80,90]

print "Print list = ", lst
print len(lst)
lst = swapOper(lst)
print lst

li = [5, 7, 22, 97, 54, 62, 77, 23, 73, 61] 
print "odd numbers from list", li
final_list = list(filter(lambda x: (x%2 != 0) , li)) 
print "Used lambda with filter", final_list

while (1):
	ip = raw_input("please press 'Y' or 'y' or 'yes' to append value to the list: ")
	if ip == "y" or ip == "Y" or ip == "yes":
		takeinput(lst)
		print lst
	else:
		exit(1)
	print ""
	print lst[len(lst)-2], type(lst[len(lst)-2])
	print lst[len(lst)-1], type(lst[len(lst)-1])
	
