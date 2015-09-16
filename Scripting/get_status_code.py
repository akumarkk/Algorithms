import re

d = {}
resp_pat = re.compile(r"^HTTP/\d.\d (\d*) (.*)")

def get_code(http_file):
    global d
    with open(http_file, "r") as file:
	for line in file:
	    match = re.finditer(resp_pat, line)
	    #print(match)
	    #print(type(match))
	    for match1 in match:
		code = match1.group(1)
		status = match1.group(2)
		if code in d:
		    d[code].append(status)
		else:
		    d[code] = [status]

get_code("./http2.txt")
for code in d:
    print("Code	    :	", code)
    for status in d[code]:
	print("                  ", status)
    print("Total # of response messages	    :	", len(d[code]))
    print("		")


	    
