#import os
from subprocess import check_output

MAX = 268435455
print(f'i \t num \t hex(i) \t ret')
for i in range(0,MAX):
	num = hex(i)[2:]
	#ret = os.system(f"echo {num} | ./a.out")
	ret = check_output([f'echo "{num}" | ./a.out'],shell=True)
	#ret = check_output([f'pwd'])
	if int(ret) != i:
		for j in range(50):
			ret = check_output([f'echo "{num}" | ./a.out'],shell=True)
			if int(ret) == i:
				break
		if int(ret) != i:
			print(f'{i} \t {num} \t {hex(i)} \t {int(ret)}')
