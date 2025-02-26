read_in = 1
while(read_in):
	read_in = input()
	op,set1,set2 = read_in.split("set")
	if op.strip() == "union":
		print("{"+f"{','.join(sorted(list(set(set1.split() + set2.split()))))}"+"}")
	elif op.strip() == "intersection":
		print("{"+",".join(list(set(set1.split()).intersection(set2.split())))+"}")
	#elif op == "intersection":
		

